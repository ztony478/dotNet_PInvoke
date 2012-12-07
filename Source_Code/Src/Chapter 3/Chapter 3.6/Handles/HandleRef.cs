using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;

namespace Handles
{
    /// <summary>
    /// 对HandleRef 范例的包装
    /// </summary>
    class HandleRefSample
    {
        // Win32 API
        // DWORD GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
        [DllImport("Kernel32.dll")]
        static extern int GetFileSize(HandleRef fileHandle, IntPtr fileSizeHigh);

        public void Test()
        {
            // 最佳的做法是采用FileStream，但是这里
            // 为了演示采用HandleRef的方法，就放弃
            // 下面被注释掉的使用FileStream的方法

            //using (FileStream fs = new FileStream("TestFile.txt", FileMode.Open))
            //{
            //    HandleRef handleRef = new HandleRef(fs, fs.SafeFileHandle.DangerousGetHandle());
            //    int fileSize = GetFileSize(handleRef, IntPtr.Zero);
            //    Console.WriteLine("GetFileSize returns: {0}", fileSize);
            //}

            // 这样做只是为了演示，最佳的做法应该
            // 像上面被注释掉的方法那样去做
            FileStream fs = new FileStream("TestFile.txt", FileMode.Open);
            HandleRef handleRef = new HandleRef(fs, fs.Handle);
            int fileSize = GetFileSize(handleRef, IntPtr.Zero);
            Console.WriteLine("GetFileSize returns: {0}", fileSize);
        }
    }
}
