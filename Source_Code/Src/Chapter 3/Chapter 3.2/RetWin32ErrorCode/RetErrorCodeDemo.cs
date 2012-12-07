using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.ComponentModel;

namespace RetWin32ErrorCode
{
    public class RetErrorCodeDemo
    {
        //Win32 API
        //DWORD WINAPI GetFileAttributes(
        //  __in  LPCTSTR lpFileName
        //);

        // 保存最后一次错误，并使用Unicode版本的Win32 函数
        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        public static extern uint GetFileAttributes(string lpFileName);

        public static void TestErrorCode()
        {
            GetFileAttributes("FileNotFoundDemo.txt");

            // 获得最后一次获得的错误
            int lastErrorCode = Marshal.GetLastWin32Error();
            Console.WriteLine("GetFileAttributes last win32 error code: {0}", lastErrorCode);
        }

        public static void TestFormatErrorMsg()
        {
            // 试图获得一个不存在的文件的属性
            GetFileAttributes("FileNotFoundDemo.txt");

            // 通过Win32 API中的FormatMessage函数获得最后一次获得的错误信息
            Console.WriteLine("GetFileAttributes last win32 error message: {0}", FormatErrorCode.GetLastErrorMsg());
        }

        public static void TestErrorMsgByWin32Exception()
        {

            // 试图获得一个不存在的文件的属性
            GetFileAttributes("FileNotFoundDemo.txt");

            // 获得最后一次获得的错误
            int lastErrorCode = Marshal.GetLastWin32Error();

            // 将Win32的错误码转化成一个用户友好的托管异常
            Win32Exception win32Exception = new Win32Exception(lastErrorCode);
            Console.WriteLine("GetFileAttributes last win32 error message: {0}", win32Exception.Message);
        }

        public static void TestErrorMsgByWin32ExceptionDefault()
        {
            // 试图获得一个不存在的文件的属性
            GetFileAttributes("FileNotFoundDemo.txt");

            // 使用Win32的缺省构造函数，使其自动调用Marshal.GetLastWin32Error()来
            // 将Win32的错误码转化成一个用户友好的托管异常
            Win32Exception win32Exception = new Win32Exception();
            Console.WriteLine("GetFileAttributes last win32 error message: {0}", win32Exception.Message);
        }
    }

    public class WithoutSetLastErrorDemo
    {
        // 不保存错误设置
        [DllImport("kernel32.dll", CharSet = CharSet.Unicode, EntryPoint = "GetFileAttributesW")]
        public static extern uint GetFileAttributesWithoutSetLastError(string lpFileName);

        public static void Test()
        {
            // 试图获得一个不存在的文件的属性
            GetFileAttributesWithoutSetLastError("FileNotFoundDemo.txt");

            // 获得最后一次获得的错误，因为没有将SetLastError设置为true，
            // 因此无法成功获得正确的错误码
            int lastErrorCode = Marshal.GetLastWin32Error();
            Console.WriteLine("GetFileAttributes last win32 error code: {0}", lastErrorCode);
        }
    }

    public class FormatErrorCode
    {
        const uint FORMAT_MESSAGE_ALLOCATE_BUFFER = 0x00000100;
        const uint FORMAT_MESSAGE_IGNORE_INSERTS = 0x00000200;
        const uint FORMAT_MESSAGE_FROM_SYSTEM = 0x00001000;

        //Win32 API
        //DWORD WINAPI FormatMessage(
        //  __in      DWORD dwFlags,
        //  __in_opt  LPCVOID lpSource,
        //  __in      DWORD dwMessageId,
        //  __in      DWORD dwLanguageId,
        //  __out     LPTSTR lpBuffer,
        //  __in      DWORD nSize,
        //  __in_opt  va_list* Arguments
        //);

        [DllImport("kernel32.dll")]
        public static extern uint FormatMessage(uint dwFlags, IntPtr lpSource,
            uint dwMessageId, uint dwLanguageId, ref IntPtr lpMsgBuf,
            uint nSize, IntPtr Arguments);

        //Win32 API
        //HLOCAL WINAPI LocalFree(
        //  __in  HLOCAL hMem
        //);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern IntPtr LocalFree(IntPtr hMem);

        public static string GetLastErrorMsg()
        {
            int lastError = Marshal.GetLastWin32Error();

            IntPtr lpMsgBuf = IntPtr.Zero;

            uint dwChars = FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
                | FORMAT_MESSAGE_IGNORE_INSERTS,
                IntPtr.Zero, (uint)lastError, 0, ref lpMsgBuf, 0, IntPtr.Zero);

            if (dwChars == 0)
            {
                return "";
            }

            string errorMsg = Marshal.PtrToStringAnsi(lpMsgBuf);
            // 释放内存
            LocalFree(lpMsgBuf);

            return errorMsg;
        }
    }

}
