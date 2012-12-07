using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace AnsiUnicodeSample
{

    public class CharSetAsUnicodeDemo
    {
        // Win32 API
        //BOOL WINAPI GetUserName(
        //  __out    LPTSTR lpBuffer,
        //  __inout  LPDWORD lpnSize
        //);

        [DllImport("advapi32.dll", CharSet = CharSet.Unicode)]
        public static extern bool GetUserName(
            StringBuilder lpBuffer,
            ref int nSize
        );

        public static void Test()
        {
            StringBuilder userNameStringBuilder = new StringBuilder(255);
            int size = userNameStringBuilder.Capacity;
            bool result = GetUserName(userNameStringBuilder, ref size);
            if (result)
            {
                Console.WriteLine("Current user name: {0}, len: {1}", userNameStringBuilder.ToString(), size - 1);
            }
            else
            {
                Console.WriteLine("Failed to read username");
            }
        }
    }

    public class CharSetAsUnicodeAndEntryPointMatchedDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameW", CharSet = CharSet.Unicode)]
        public static extern bool GetUserName(
            StringBuilder lpBuffer,
            ref int nSize
        );

        public static void Test()
        {
            StringBuilder userNameStringBuilder = new StringBuilder(255);
            int size = userNameStringBuilder.Capacity;
            bool result = GetUserName(userNameStringBuilder, ref size);
            if (result)
            {
                Console.WriteLine("Current user name: {0}, len: {1}", userNameStringBuilder.ToString(), size - 1);
            }
            else
            {
                Console.WriteLine("Failed to read username");
            }
        }
    }

    public class CharSetAsUnicodeButWithExactSpellingTrueDemo
    {
        [DllImport("advapi32.dll", CharSet = CharSet.Unicode, ExactSpelling = true)]
        public static extern bool GetUserName(
            StringBuilder lpBuffer,
            ref int nSize
        );

        public static void Test()
        {
            StringBuilder userNameStringBuilder = new StringBuilder(255);
            int size = userNameStringBuilder.Capacity;
            bool result = GetUserName(userNameStringBuilder, ref size);
            try
            {
                if (result)
                {
                    Console.WriteLine("Current user name: {0}, len: {1}", userNameStringBuilder.ToString(), size - 1);
                }
                else
                {
                    Console.WriteLine("Failed to read username");
                }
            }
            catch (DllNotFoundException exc)
            {
                throw exc;
            }
        }
    }

    public class CharSetAsUnicodeButWithModifiedRootFunctionNameDemo
    {
        [DllImport("advapi32.dll", CharSet = CharSet.Unicode)]
        public static extern bool GetUserNameModified(
            StringBuilder lpBuffer,
            ref int nSize
        );

        public static void Test()
        {
            StringBuilder userNameStringBuilder = new StringBuilder(255);
            int size = userNameStringBuilder.Capacity;
            bool result = GetUserNameModified(userNameStringBuilder, ref size);
            try
            {
                if (result)
                {
                    Console.WriteLine("Current user name: {0}, len: {1}", userNameStringBuilder.ToString(), size - 1);
                }
                else
                {
                    Console.WriteLine("Failed to read username");
                }
            }
            catch (DllNotFoundException exc)
            {
                throw exc;
            }
        }
    }

    public class CharSetAsUnicodeAndEntryPointMismatchDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameW", CharSet = CharSet.Ansi)]
        public static extern bool GetUserName(
            StringBuilder lpBuffer,
            ref int nSize
        );

        public static void Test()
        {
            StringBuilder userNameStringBuilder = new StringBuilder(255);
            int size = userNameStringBuilder.Capacity;
            bool result = GetUserName(userNameStringBuilder, ref size);
            if (result)
            {
                Console.WriteLine("Current user name: {0}, len: {1}", userNameStringBuilder.ToString(), size - 1);
            }
            else
            {
                Console.WriteLine("Failed to read username");
            }
        }
    }

    public class CharSetAsAutoAndEntryPointSpecifiedDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameW", CharSet = CharSet.Auto)]
        public static extern bool GetUserName(
            StringBuilder lpBuffer,
            ref int nSize
        );

        public static void Test()
        {
            StringBuilder userNameStringBuilder = new StringBuilder(255);
            int size = userNameStringBuilder.Capacity;
            bool result = GetUserName(userNameStringBuilder, ref size);
            if (result)
            {
                Console.WriteLine("Current user name: {0}, len: {1}", userNameStringBuilder.ToString(), size - 1);
            }
            else
            {
                Console.WriteLine("Failed to read username");
            }
        }
    }

}
