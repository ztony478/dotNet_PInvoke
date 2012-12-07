using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.ComponentModel;

namespace DotNetVersionOfWin32
{

    class CopyFileWin32
    {
        // CopyFileµÄWin32¶¨Òå
        //BOOL WINAPI CopyFile(
        //  __in  LPCTSTR lpExistingFileName,
        //  __in  LPCTSTR lpNewFileName,
        //  __in  BOOL bFailIfExists
        //);

        [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        public static extern bool CopyFile(string lpExistingFileName, string lpNewFileName,
          bool bFailIfExists);

        public static void Test(string srcFile, string destFile, bool overwrite)
        {
            bool copyResult = CopyFile(srcFile, destFile, !overwrite);
            if (!copyResult)
            {
                Console.WriteLine("Copying file using Win32 P/Invoke, error message: {0}", new Win32Exception().Message);
                //throw new Win32Exception();
            }
        }
    }

    class CopyFileManaged
    {
        public static void Test(string srcFile, string destFile, bool overwrite)
        { 
            try
            {
                File.Copy(srcFile, destFile, overwrite);
            }
            catch (Exception exc)
            {
                Console.WriteLine("Copying file using managed fuction, error message: {0}", exc.Message);
                //throw exc;
            }
        }
    }

}
