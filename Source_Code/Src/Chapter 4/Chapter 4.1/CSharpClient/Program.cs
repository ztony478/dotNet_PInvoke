using System;
using System.Collections.Generic;
using System.Text;
using CppInteropWrapper;

namespace CSharpClient
{
    class Program
    {
        static void Main(string[] args)
        {

            int resultNumber = 0;

            // 创建Managed C++对象实例
	        WrapperClass wrapperObj = new WrapperClass();
        	
            // 调用乘法方法（P/Invoke)
	        resultNumber = wrapperObj.MultiplyNumbers_PInvoke(2, 3);
            Console.WriteLine("乘法（P/Invoke）：2x3 = {0}", resultNumber);

	        // 调用乘法方法（C++ Interop)
	        resultNumber = wrapperObj.MultiplyNumbers_CppInterop(4, 5);
            Console.WriteLine("乘法（C++ Interop）：4x5 = {0}", resultNumber);

	        // 翻转字符串方法(P/Invoke)
	        wrapperObj.ReverseString_PInvoke();

	        // 翻转字符串方法(C++ Interop)
	        wrapperObj.ReverseString_CppInterop();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
