using System;
using System.Collections.Generic;
using System.Text;

namespace CreateInstanceByPInvoke
{
    class Program
    {
        static void Main(string[] args)
        {
            CreateInstanceByPInvokeClass.DoTest();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
