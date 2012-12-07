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
            CMCppWrapper wrapperObj = new CMCppWrapper();

            wrapperObj.PassInt(10);

            wrapperObj.PassString("String from managed code.");

            string retString = wrapperObj.ReturnString();
            Console.WriteLine("Returned String: {0}", retString);

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
