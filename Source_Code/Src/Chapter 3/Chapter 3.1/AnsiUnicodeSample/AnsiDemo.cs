using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace AnsiUnicodeSample
{
    public class DefaultCharSetDemo
    {
        // Win32 API
        //BOOL WINAPI GetUserName(
        //  __out    LPTSTR lpBuffer,
        //  __inout  LPDWORD lpnSize
        //);

        [DllImport("advapi32.dll")]
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

    public class CharSetAsAnsiDemo
    {
        [DllImport("advapi32.dll", CharSet = CharSet.Ansi)]
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

    public class DefaultCharSetAndEntryPointSpecifiedDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameA")]
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

    public class CharSetAsAnsiAndEntryPointSpecifiedDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameA", CharSet = CharSet.Ansi)]
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

    public class CharSetAndEntryPointMismatchDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameA", CharSet = CharSet.Unicode)]
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

    public class CharSetAsAutoAndEntryPointDemo
    {
        [DllImport("advapi32.dll", EntryPoint = "GetUserNameA", CharSet = CharSet.Auto)]
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
