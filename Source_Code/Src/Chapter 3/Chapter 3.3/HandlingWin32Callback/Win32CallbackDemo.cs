using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace HandlingWin32Callback
{

    public enum LanGroupEnum : uint
    {
        /// <summary>
        /// 只枚举安装了的语言组标识符
        /// </summary>
        LGRPID_INSTALLED = 1,

        /// <summary>
        /// 枚举所有支持的语言组标识符
        /// </summary>
        LGRPID_SUPPORTED 
    }

    public class Win32CallbackDefaultDemo
    {
        //Win32 API
        //BOOL CALLBACK EnumLanguageGroupsProc(
        //LGRPID LanguageGroup, 
        //LPTSTR lpLanguageGroupString,     
        //LPTSTR lpLanguageGroupNameString,  
        //DWORD dwFlags, 
        //LONG_PTR  lParam);

        public delegate bool LanguageGroupEnumDelegate(int languageGroup,
            string pLanguageGroupString,
            string pLanguageGroupNameString,
            uint dwFlags,
            IntPtr lParam);

        // Win32 API
        //BOOL EnumSystemLanguageGroups(
        //LANGUAGEGROUP_ENUMPROC lpLanguageGroupEnumProc,
        //DWORD dwFlags,
        //LONG_PTR lParam);


        [DllImport("kernel32.dll")]
        public static extern bool EnumSystemLanguageGroups(
            LanguageGroupEnumDelegate pLangGroupEnumProc,
            uint dwFlags,
            IntPtr lParam);
    }

    public class Win32CallbackMismatchDemo
    {
        public delegate bool LanguageGroupEnumDelegate(int languageGroup,
            string pLanguageGroupString,
            string pLanguageGroupNameString,
            uint dwFlags,
            IntPtr lParam);

        [DllImport("kernel32.dll", CharSet = CharSet.Unicode)]
        public static extern bool EnumSystemLanguageGroups(
            LanguageGroupEnumDelegate pLangGroupEnumProc,
            uint dwFlags,
            IntPtr lParam);
    }

    public class Win32CallbackMarshalAsDemo
    {
        public delegate bool LanguageGroupEnumDelegate(int languageGroup,
            [MarshalAs(UnmanagedType.LPWStr)] string pLanguageGroupString,
            [MarshalAs(UnmanagedType.LPWStr)] string pLanguageGroupNameString,
            uint dwFlags,
            IntPtr lParam);

        [DllImport("kernel32.dll", CharSet = CharSet.Unicode)]
        public static extern bool EnumSystemLanguageGroups(
            LanguageGroupEnumDelegate pLangGroupEnumProc,
            uint dwFlags,
            IntPtr lParam);
    }

    public class Win32CallbackUnmanagedFPDemo
    {
        [UnmanagedFunctionPointer(CallingConvention.Winapi, CharSet = CharSet.Unicode)]
        public delegate bool LanguageGroupEnumDelegate(int languageGroup,
            string pLanguageGroupString,
            string pLanguageGroupNameString,
            uint dwFlags,
            IntPtr lParam);

        [DllImport("kernel32.dll", CharSet = CharSet.Unicode)]
        public static extern bool EnumSystemLanguageGroups(
            LanguageGroupEnumDelegate pLangGroupEnumProc,
            uint dwFlags,
            IntPtr lParam);
    }


}
