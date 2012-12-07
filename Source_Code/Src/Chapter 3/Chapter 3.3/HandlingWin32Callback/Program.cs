using System;
using System.Collections.Generic;
using System.Text;


namespace HandlingWin32Callback
{
    class Program
    {
        static void Main(string[] args)
        {
            IntPtr lParam = IntPtr.Zero;
            Win32CallbackMismatchDemo.EnumSystemLanguageGroups(LanguageGroupEnumCallback, (uint)LanGroupEnum.LGRPID_SUPPORTED, lParam);

            Win32CallbackMismatchDemo.EnumSystemLanguageGroups(LanguageGroupEnumCallback, (uint)LanGroupEnum.LGRPID_SUPPORTED, lParam);

            Win32CallbackMarshalAsDemo.EnumSystemLanguageGroups(LanguageGroupEnumCallback, (uint)LanGroupEnum.LGRPID_SUPPORTED, lParam);

            Win32CallbackUnmanagedFPDemo.EnumSystemLanguageGroups(LanguageGroupEnumCallback, (uint)LanGroupEnum.LGRPID_SUPPORTED, lParam);

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        public static bool LanguageGroupEnumCallback(int languageGroup,
            string pLanguageGroupString,
            string pLanguageGroupNameString,
            uint dwFlags,
            IntPtr lParam)
        {
            string instalOrSupport = "";
            if (dwFlags == (uint)LanGroupEnum.LGRPID_INSTALLED)
            {
                instalOrSupport = "Language group identifier is installed.";
            }
            else if (dwFlags == (uint)LanGroupEnum.LGRPID_SUPPORTED)
            {
                instalOrSupport = "Language group identifier is both supported and installed.";
            }

            //Console.WriteLine("LanguageGroupId: {0}, LanguageGroupName: {1}, \t{2}",
            //    languageGroup, pLanguageGroupNameString, instalOrSupport);

            Console.WriteLine("LanguageGroupId: {0}, LanguageGroupName: {1}",
                languageGroup, pLanguageGroupNameString);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine(instalOrSupport);
            Console.ResetColor();
            for (int i = 0; i < Console.WindowWidth; i++)
            {
                Console.Write("-");
            }
            //Console.WriteLine();

            return true;
        }

    }
}
