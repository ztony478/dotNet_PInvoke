using System;
using System.Collections.Generic;
using System.Text;

namespace DynamicPInvoke
{
    class Program
    {
        static void Main(string[] args)
        {
            //DynamicPInvokeViaLoadLib.Test();

            //DynamicPInvokeViaEmit.Test();

            DynamicPInvokeViaDelegate.Test();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }

}
