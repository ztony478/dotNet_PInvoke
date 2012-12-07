using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace CallingConventionDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintfWrapper.printf("%i + %i = %i\n", 8, 18, 8+18);
            PrintfWrapper.printf("Hello! Your name is %s, your id is %s\n", "James", "Num007");

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }

    public class PrintfWrapper
    {
        [DllImport("msvcrt.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int printf(string format, int num1, int num2, int result);
        [DllImport("msvcrt.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int printf(string format, string name, string id);
    }


}
