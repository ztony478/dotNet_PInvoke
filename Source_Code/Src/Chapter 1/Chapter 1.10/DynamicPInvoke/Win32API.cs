using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace DynamicPInvoke
{
    class Win32API
    {
        //Win32 API For LoadLibrary
        //HMODULE WINAPI LoadLibrary(
        //  __in  LPCTSTR lpFileName
        //);
        [DllImport("kernel32.dll", EntryPoint = "LoadLibrary")]
        public static extern IntPtr LoadLibrary(
            string lpLibFileName
        );

        //Win32 API For FreeLibrary
        //BOOL WINAPI FreeLibrary(
        //  __in  HMODULE hModule
        //);
        [DllImport("kernel32.dll", EntryPoint = "FreeLibrary")]
        public static extern bool FreeLibrary(
            IntPtr hLibModule
        );

        //Win32 API For GetProcAddress
        //FARPROC WINAPI GetProcAddress(
        //  __in  HMODULE hModule,
        //  __in  LPCSTR lpProcName
        //);
        [DllImport("kernel32.dll", EntryPoint = "GetProcAddress")]
        public static extern IntPtr GetProcAddress(
            IntPtr hModule,
            string lpProcName
        );

    }
}
