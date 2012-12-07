using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMDataType.Interop;
using System.Runtime.InteropServices;

namespace COMMarshalCStyleArray
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCStyleArray();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCStyleArray()
        {
            int[] intArray = new int[] { 1, 3, 5, 7, 9 };

            Console.WriteLine("整数数组中的元素为：");
            foreach (int i in intArray)
            {
                Console.WriteLine(i);
            }

            // 创建COM对象的示例
            MarshalCOMDataTypeClass comObj = new MarshalCOMDataTypeClass();

            // 计算整数数组在非托管内存中所占内存的大小
            int bufferSize = Marshal.SizeOf(typeof(int)) * intArray.Length;

            // 为整数数组分配非托管内存
            IntPtr pArray = Marshal.AllocCoTaskMem(bufferSize);

            // 将整数数组封送到非托管内存中
            Marshal.Copy(intArray, 0, pArray, intArray.Length);

            // 调用COM方法，返回数组元素之和
            int sum = comObj.MarshalCStylelArray(pArray, intArray.Length);

            // 释放非托管内存
            Marshal.FreeCoTaskMem(pArray);

            Console.WriteLine("\n数组中元素之和为：{0}", sum);

        }
    }
}
