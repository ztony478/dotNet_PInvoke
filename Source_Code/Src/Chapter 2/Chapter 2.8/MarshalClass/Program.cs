using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace MarshalClass
{
    class Program
    {
        private const string _dllName = "NativeLib.dll";

        //typedef struct _MSEMPLOYEE
        //{
        //    UINT  employeeID;
        //    short employedYear;
        //    char* displayName; 
        //    char* alias; 
        //} MSEMPLOYEE, *PMSEMPLOYEE;
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        private class MsEmployee
        {
            private uint _employeeID;
            private short _employedYear;
            private string _displayName;
            private string _alias;

            #region Properties
            public uint EmployeeID
            {
                get { return _employeeID; }
                set { _employeeID = value; }
            }

            public short EmployedYear
            {
                get { return _employedYear; }
                set { _employedYear = value; }
            }

            public string DisplayName
            {
                get { return _displayName; }
                set { _displayName = value; }
            }

            public string Alias
            {
                get { return _alias; }
                set { _alias = value; }
            }
            #endregion
        }

        // void __cdecl GetEmployeeInfo(PMSEMPLOYEE pEmployee)
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Ansi)]
        private extern static void GetEmployeeInfo([In, Out] MsEmployee employee);

        //typedef struct _SIMPLESTRUCT
        //{
        //    int    intValue;
        //    short  shortValue;
        //    float  floatValue;
        //    double doubleValue;
        //} SIMPLESTRUCT, *PSIMPLESTRUCT;
        [StructLayout(LayoutKind.Sequential)]
        private class ManagedClassBlittable
        {
            private int _intValue;
            private short _shortValue;
            private float _floatValue;
            private double _doubleValue;

            #region Properties
            public int IntValue
            {
                get { return _intValue; }
                set { _intValue = value; }
            }

            public short ShortValue
            {
                get { return _shortValue; }
                set { _shortValue = value; }
            }

            public float FloatValue
            {
                get { return _floatValue; }
                set { _floatValue = value; }
            }

            public double DoubleValue
            {
                get { return _doubleValue; }
                set { _doubleValue = value; }
            }
            #endregion
        }

        // void __cdecl TestStructArgument(PSIMPLESTRUCT pStruct);
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestStructArgumentByRef(ManagedClassBlittable argClass);

        // void __cdecl TestReturnStructFromArg(PSIMPLESTRUCT* pStruct);
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl)]
        private extern static void TestReturnStructFromArg(out ManagedClassBlittable outObject);

        static void Main(string[] args)
        {
            TestClassNonBlittlable();

            TestClassBlittalbe();

            TestPointer2Pointer();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        private static void TestClassNonBlittlable()
        {
            MsEmployee employee = new MsEmployee();
            employee.EmployeeID = 10001;

            GetEmployeeInfo(employee);

            Console.WriteLine("\n员工信息:");
            Console.WriteLine("ID: {0}", employee.EmployeeID);
            Console.WriteLine("工龄:{0}", employee.EmployedYear);
            Console.WriteLine("Alias: {0}", employee.Alias);
            Console.WriteLine("姓名: {0}", employee.DisplayName);
        }

        private static void TestClassBlittalbe()
        {
            ManagedClassBlittable blittableObject = new ManagedClassBlittable();
            blittableObject.IntValue = 1;
            blittableObject.ShortValue = 2;
            blittableObject.FloatValue = 3;
            blittableObject.DoubleValue = 4.5;

            TestStructArgumentByRef(blittableObject);

            Console.WriteLine("\n结构体新数据：int = {0}, short = {1}, float = {2:f6}, double = {3:f6}",
                blittableObject.IntValue, blittableObject.ShortValue, blittableObject.FloatValue, blittableObject.DoubleValue);
        }

        private static void TestPointer2Pointer()
        {
            ManagedClassBlittable outObject;

            TestReturnStructFromArg(out outObject);

            Console.WriteLine("\n结构体新数据：int = {0}, short = {1}, float = {2:f6}, double = {3:f6}",
                outObject.IntValue, outObject.ShortValue, outObject.FloatValue, outObject.DoubleValue);
        }

    }
}
