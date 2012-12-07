using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMDataType.Interop;

namespace COMMarshalSafeArray
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMSafeArray();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMSafeArray()
        {
            MarshalCOMDataTypeClass comObj = new MarshalCOMDataTypeClass();
            string[] stringArray = new string[] { "This", "is", "a", "SAFEARRAY", "sample" };

            Console.WriteLine("初始字符串数组：");
            foreach (string str in stringArray)
            {
                Console.WriteLine(str);
            }

            string result = comObj.SortArray(stringArray);
            Console.WriteLine("\n调用返回结果：{0}", result);
            Console.WriteLine("\n排序后的字符串数组：");
            foreach (string str in stringArray)
            {
                Console.WriteLine(str);
            }
        }
    }
}
