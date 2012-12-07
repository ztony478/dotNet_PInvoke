using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;

namespace PassManagedObject
{
    class ManagedObjectInCallback
    {
        delegate bool EnumWindowProc(int windowHandle, IntPtr param);

        // 将托管对象作为LPARAM参数传递
        // Win32 API
        // BOOL EnumDesktopWindows(
        //  __in          HDESK hDesktop,
        //  __in          WNDENUMPROC lpfn,
        //  __in          LPARAM lParam);
        [DllImport("user32.dll")]
        static extern bool EnumDesktopWindows(
            IntPtr desktopHandle, 
            EnumWindowProc cb, 
            IntPtr param);

        // Win32 API
        // int GetWindowText(HWND hWnd, LPTSTR lpString, int nMaxCount);
        [DllImport("user32.dll")]
        static extern int GetWindowText(
            int windowHandle, 
            StringBuilder textBuffer, 
            int bufferLength);

        /// <summary>
        /// 这个回调方法用于显示窗体的标题
        /// </summary>
        /// <param name="handle">窗体的句柄</param>
        /// <param name="param">参数</param>
        /// <returns></returns>
        private static bool DisplayWindowsTitleProc(int windowHandle, IntPtr param)
        {
            GCHandle gch = (GCHandle)param;
            TextWriter tw = gch.Target as TextWriter;
            if (null != tw)
            {
                StringBuilder buffer = new StringBuilder(1024);
                int size = GetWindowText(windowHandle, buffer, buffer.Capacity);
                if (size != 0)
                {
                    tw.WriteLine("Window Handle: 0x{0:x8}  Title: {1}", windowHandle, buffer);
                }
                return true;
            }
            else
            {
                return false;
            }
        }	

        public void Test()
        {   
            // 这个TextWriter托管对象将会被传递给Win32 API函数
            // 这个对象将一直存在，直到调用结束
            TextWriter outputWriter = System.Console.Out;

            // 使用GCHandle来阻止TextWriter对象被垃圾回收器回收
            GCHandle gch = GCHandle.Alloc(outputWriter, GCHandleType.Normal);
            
            EnumWindowProc cb = new EnumWindowProc(DisplayWindowsTitleProc);

            // P/Invoke会在调用结束前，自动阻止垃圾
            // 回收器对委托进行回收
            EnumDesktopWindows(IntPtr.Zero, cb, (IntPtr)gch);

            // 当不再需要GCHandle时，必须调用Free方法将其释放掉
            gch.Free();
        }
    }


}
