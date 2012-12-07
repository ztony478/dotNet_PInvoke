using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace ManagedMultiplyCaller
{
    class Program
    {
        static void Main(string[] args)
        {
            MultiplyManagedCaller.MultiplyTest();
        }
    }


    class MultiplyManagedCaller
    {
        //Unmanaged function
        //int __stdcall Multiply(int factorA, int factorB);

        //声明非托管函数
        [DllImport("NativeLib.dll")]
        static extern int Multiply(int factorA, int factorB);

        public static void MultiplyTest()
        {
            //调用非托管函数
            int factorA = 100, factorB = 8;
            int result = Multiply(factorA, factorB);

            //打印结果
            Console.WriteLine(string.Format("{0} * {1} = {2} ", factorA, factorB, result));

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }

}
