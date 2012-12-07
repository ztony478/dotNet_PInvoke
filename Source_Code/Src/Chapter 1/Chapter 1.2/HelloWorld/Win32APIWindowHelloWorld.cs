using System;
using System.Runtime.InteropServices;

namespace HelloWorld
{
    class Win32APIWindowHelloWorld
    {
        // Win32 API
        // int MessageBox(      
        //    HWND hWnd,
        //    LPCTSTR lpText,
        //    LPCTSTR lpCaption,
        //    UINT uType
        //);
        [DllImport("user32.dll", EntryPoint = "MessageBox")]
        public static extern int MessageBox(
            int hwnd,
            string lpText,
            string lpCaption,
            int wType
        );

        public static void SayHelloWorld()
        {
            MessageBox(0, "Hello world!", "Welcome", 0);
        }
    }
}
