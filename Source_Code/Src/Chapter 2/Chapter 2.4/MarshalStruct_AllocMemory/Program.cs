using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace MarshalStruct_AllocMemory
{
    class Program
    {
        private const string _dllName = "NativeLib.dll";

        //typedef struct _MSEMPLOYEE
        //{
        //    UINT employeeID;
        //    short employedYear;
        //    char* displayName; 
        //    char* alias; 
        //} MSEMPLOYEE, *PMSEMPLOYEE;
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        private struct MsEmployee
        {
            public uint EmployeeID;
            public short EmployedYear;
            public string DisplayName;
            public string Alias;
        }

        [StructLayout(LayoutKind.Sequential)]
        private struct MsEmployee_IntPtrString
        {
            public uint EmployeeID;
            public short EmployedYear;
            public IntPtr DisplayName;
            public IntPtr Alias;
        }

        // void __cdecl GetEmployeeInfo(PMSEMPLOYEE pEmployee)
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Ansi)]
        private extern static void GetEmployeeInfo(ref MsEmployee employee);

        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl,
           CharSet = CharSet.Ansi, EntryPoint = "GetEmployeeInfo")]
        private extern static void GetEmployeeInfo_IntPtrString(ref MsEmployee_IntPtrString employee);

        //typedef struct _MSEMPLOYEE2
        //{
        //    UINT employeeID;
        //    short employedYear;
        //    char displayName[255]; 
        //    char alias[255]; 
        //} MSEMPLOYEE2, *PMSEMPLOYEE2;
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        private struct MsEmployee2
        {
            public uint EmployeeID;
            public short EmployedYear;
            // 字符集是由StructLayout的CharSet指定的
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
            public string DisplayName;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 255)]
            public string Alias;
        }

        // void __cdecl GetEmployeeInfo2(PMSEMPLOYEE2 pEmployee)
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Ansi)]
        private extern static void GetEmployeeInfo2(ref MsEmployee2 employee);



        static void Main(string[] args)
        {
            TestAllocString();

            TestAllocString_IntPtrString();

            TestInlineString();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        private static void TestAllocString()
        {
            MsEmployee employee = new MsEmployee();
            employee.EmployeeID = 10001;
            GetEmployeeInfo(ref employee);

            Console.WriteLine("\n员工信息:");
            Console.WriteLine("ID: {0}", employee.EmployeeID);
            Console.WriteLine("工龄:{0}", employee.EmployedYear);
            Console.WriteLine("Alias: {0}", employee.Alias);
            Console.WriteLine("姓名: {0}", employee.DisplayName);
        }

        private static void TestAllocString_IntPtrString()
        {
            MsEmployee_IntPtrString employee = new MsEmployee_IntPtrString();
            employee.EmployeeID = 10001;
            GetEmployeeInfo_IntPtrString(ref employee);

            string displayName = Marshal.PtrToStringAnsi(employee.DisplayName);
            string alias = Marshal.PtrToStringAnsi(employee.Alias);

            Marshal.FreeCoTaskMem(employee.DisplayName);
            Marshal.FreeCoTaskMem(employee.Alias);

            Console.WriteLine("\n员工信息:");
            Console.WriteLine("ID: {0}", employee.EmployeeID);
            Console.WriteLine("工龄:{0}", employee.EmployedYear);
            Console.WriteLine("Alias: {0}", alias);
            Console.WriteLine("姓名: {0}", displayName);
        }

        private static void TestInlineString()
        {
            MsEmployee2 employee = new MsEmployee2();
            employee.EmployeeID = 10002;
            GetEmployeeInfo2(ref employee);

            Console.WriteLine("\n员工信息:");
            Console.WriteLine("ID: {0}", employee.EmployeeID);
            Console.WriteLine("工龄:{0}", employee.EmployedYear);
            Console.WriteLine("Alias: {0}", employee.Alias);
            Console.WriteLine("姓名: {0}", employee.DisplayName);
        }
    }
}
