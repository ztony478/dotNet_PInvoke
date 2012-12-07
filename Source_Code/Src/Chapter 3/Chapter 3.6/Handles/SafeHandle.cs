using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;

namespace Handles
{
    class SafeHandleSample
    {
        // 这里只是为了进行演示，所以就没有采用
        // 本该在枚举中定义常量的做法
        const uint FILE_SHARE_READ = 0x00000001;
        const uint OPEN_EXISTING = 3;

        // Win32 API
        // DWORD GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
        [DllImport("Kernel32.dll", EntryPoint = "GetFileSize")]
        static extern int GetFileSizeSafe(SafeFileHandle fileHandle, IntPtr fileSizeHigh);

        // Win32 API
        //  HANDLE CreateFile(
        //      LPCTSTR lpFileName,
        //      DWORD dwDesiredAccess,
        //      DWORD dwShareMode,
        //      LPSECURITY_ATTRIBUTES lpSecurityAttributes,
        //      DWORD dwCreationDisposition,
        //      DWORD dwFlagsAndAttributes,
        //      HANDLE hTemplateFile
        //  ); 

        [DllImport("Kernel32.dll", SetLastError = true, EntryPoint = "CreateFile")]
        static extern SafeFileHandle CreateFileSafe(
            string fileName,
            uint desiredAccess,
            uint shareMode,
            IntPtr securityAttributes,
            uint creationDisposition,
            uint flagsAndAttributes,
            IntPtr templateFile);

        public void Test()
        {
            // 这里无需再调用CloseHandle()来释放掉文件句柄，
            // 这是因为SafeFileHandle已经实现了IDisposable接口，
            // 因此句柄会被CLR释放或在调用Dispose()时被释放
            using (SafeFileHandle fileHandle = OpenFile("TestFile.txt"))
            {
                int fileSize = GetFileSizeSafe(fileHandle, IntPtr.Zero);
                Console.WriteLine("GetFileSizeSafe returns: {0}", fileSize);
            }
        }

        /// <summary>
        /// 打开一个文件以备读取
        /// </summary>
        /// <param name="fileName">文件名</param>
        /// <returns></returns>
        private SafeFileHandle OpenFile(string fileName)
        {
            SafeFileHandle fileHandle = CreateFileSafe(
                           fileName,
                           0,
                           FILE_SHARE_READ,
                           IntPtr.Zero,
                           OPEN_EXISTING,
                           0,
                           IntPtr.Zero);

            if (fileHandle.IsInvalid)
            {
                int lastErrorCode = Marshal.GetLastWin32Error();
                throw new System.ComponentModel.Win32Exception(lastErrorCode);
            }
            else 
            {
                return fileHandle;
            }
        }

    }

    /// <summary>
    /// 使用Win32 Handles的不安全的方式
    /// </summary>
    class UnsafeHandleSample
    {
        // 这里只是为了进行演示，所以就没有采用
        // 本该在枚举中定义常量的做法
        const uint FILE_SHARE_READ = 0x00000001;
        const uint OPEN_EXISTING = 3;

        // Win32 API
        // DWORD GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
        [DllImport("Kernel32.dll", EntryPoint = "GetFileSize")]
        static extern int GetFileSizeUnsafe(IntPtr fileHandle, IntPtr fileSizeHigh);

        // Win32 API
        //  HANDLE CreateFile(
        //      LPCTSTR lpFileName,
        //      DWORD dwDesiredAccess,
        //      DWORD dwShareMode,
        //      LPSECURITY_ATTRIBUTES lpSecurityAttributes,
        //      DWORD dwCreationDisposition,
        //      DWORD dwFlagsAndAttributes,
        //      HANDLE hTemplateFile
        //  ); 

        [DllImport("Kernel32.dll", SetLastError = true, EntryPoint = "CreateFile")]
        static extern IntPtr CreateFileUnsafe(
            string fileName,
            uint desiredAccess,
            uint shareMode,
            IntPtr securityAttributes,
            uint creationDisposition,
            uint flagsAndAttributes,
            IntPtr templateFile);

        // Win32 API
        //  BOOL CloseHandle(
        //      HANDLE hObject
        //  ); 
        [DllImport("Kernel32.dll", SetLastError = true)]
        static extern bool CloseHandle(IntPtr fileHandle);

        public void Test()
        {
            IntPtr fileHandle = CreateFileUnsafe(
                "TestFile.txt",
                0,
                FILE_SHARE_READ,
                IntPtr.Zero,
                OPEN_EXISTING,
                0,
                IntPtr.Zero);

            if (fileHandle == IntPtr.Zero)
            {
                int lastErrorCode = Marshal.GetLastWin32Error();
                throw new System.ComponentModel.Win32Exception(lastErrorCode);
            }
            int fileSize = GetFileSizeUnsafe(fileHandle, IntPtr.Zero);
            Console.WriteLine("GetFileSizeUnsafe returns: {0}", fileSize);

            // 如果这里发生了异常，比如在这里书写的代码
            // 出现了未知错误或抛出了异常，那么就无法保
            // 证句柄被关闭了

            // 如果仅仅寄希望于使用try/finally语句来保证关闭句柄，
            // 也是不能保证就一定能关闭句柄的，比如遇到了一
            // 个AppDomain被卸载问题，就不一定能保证了

            // 调用CloseHandle释放掉句柄，防止出现泄漏问题
            bool ret = CloseHandle(fileHandle);
        }

    }
}
