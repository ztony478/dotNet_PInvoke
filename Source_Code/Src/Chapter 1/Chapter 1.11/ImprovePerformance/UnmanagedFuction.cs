using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace ImprovePerformance
{
    class UnmanagedFuction
    {
        //Unmanaged function 
        //bool IsAsciiNonblittable(char asciiChar);
        [DllImport("NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl
            )]
        public static extern bool IsAsciiNonblittable(char asciiChar);

        //Unmanaged function 
        //int IsAsciiBlittable(__int8 asciiChar);
        [DllImport("NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl
            )]
        public static extern int IsAsciiBlittable(byte asciiChar);

        //Unmanaged function 
        //void UnmanagedTest();
        [DllImport("NativeLib.dll")]
        public static extern void UnmanagedTest();

        //Unmanaged function 
        //bool IsWasciiNonblittable(wchar_t wasciiChar)
        [DllImport("NativeLib.dll", CharSet = CharSet.Unicode)]
        public static extern bool IsWasciiNonblittable(char charForTest);

        //Unmanaged function
        //void __cdecl ReverseStringA(char* rawString, char* reversedString)
        [DllImport("NativeLib.dll", 
            CharSet = CharSet.Ansi, 
            CallingConvention = CallingConvention.Cdecl
            )]
        public static extern void ReverseString(string rawString, StringBuilder reversedString);

        [DllImport("NativeLib.dll",
            CharSet = CharSet.Ansi,
            CallingConvention = CallingConvention.Cdecl,
            ExactSpelling = true
            )]
        public static extern void ReverseStringA(string rawString, StringBuilder reversedString);
    }
}
