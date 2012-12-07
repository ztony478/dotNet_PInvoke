using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMDataType.Interop;
using System.Runtime.InteropServices;

namespace COMMarshalVariant
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMVariant();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMVariant()
        {
            MarshalCOMDataTypeClass comObj = new MarshalCOMDataTypeClass();

            object outArg = null;
            string description = string.Empty;

            uint uintArg = 10;
            description = comObj.MarshalCOMVariant(uintArg, out outArg);
            Console.WriteLine("VARIANT - uint: {0}, {1}, {2}",
                uintArg.GetType().Name, outArg.GetType().Name, description);

            double doubleArg = 10.0;
            description = comObj.MarshalCOMVariant(doubleArg, out outArg);
            Console.WriteLine("VARIANT - double: {0}, {1}, {2}",
                doubleArg.GetType().Name, outArg.GetType().Name, description);

            string stringArg = "字符串";
            description = comObj.MarshalCOMVariant(stringArg, out outArg);
            Console.WriteLine("VARIANT - string: {0}, {1}, {2}",
                stringArg.GetType().Name, outArg.GetType().Name, description);

            decimal decimalArg = 10.20m;
            description = comObj.MarshalCOMVariant(decimalArg, out outArg);
            Console.WriteLine("VARIANT - decimal: {0}, {1}, {2}",
                decimalArg.GetType().Name, outArg.GetType().Name, description);

            CurrencyWrapper currencyArg = new CurrencyWrapper(10.20m);
            description = comObj.MarshalCOMVariant(currencyArg, out outArg);
            Console.WriteLine("VARIANT - currency: {0}, {1}, {2}",
                currencyArg.GetType().Name, outArg.GetType().Name, description);

            DateTime dateArg = new DateTime(2008, 8, 8);
            description = comObj.MarshalCOMVariant(dateArg, out outArg);
            Console.WriteLine("VARIANT - date: {0}, {1}, {2}",
                dateArg.GetType().Name, outArg.GetType().Name, description);

            object objectArg = new object();
            description = comObj.MarshalCOMVariant(objectArg, out outArg);
            Console.WriteLine("VARIANT - object: {0}, {1}, {2}",
                objectArg.GetType().Name, outArg.GetType().Name, description);

            object nullArg = null;
            description = comObj.MarshalCOMVariant(nullArg, out outArg);
            Console.WriteLine("VARIANT - null: {0}, {1}, {2}",
                "null", outArg == null ? "null" : outArg.GetType().Name, description);

            IntPtr intptrArg = IntPtr.Zero;
            description = comObj.MarshalCOMVariant(intptrArg, out outArg);
            Console.WriteLine("VARIANT - IntPtr: {0}, {1}, {2}",
                intptrArg.GetType().Name, outArg.GetType().Name, description);
        }
    }
}
