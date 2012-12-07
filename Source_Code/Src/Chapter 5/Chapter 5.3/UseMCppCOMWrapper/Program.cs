using System;
using System.Collections.Generic;
using System.Text;
using MCppCOMWrapperLib;

namespace UseMCppCOMWrapper
{
    class Program
    {
        static void Main(string[] args)
        {
            MCppCOMWrapper wrapperObj = new MCppCOMWrapper();
            string inString = "输入字符串";
            string outString = wrapperObj.ProcessString(inString);

            Console.WriteLine("初始时字符串为：{0}", inString);
            Console.WriteLine("修改后字符串为：{0}", outString);

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
