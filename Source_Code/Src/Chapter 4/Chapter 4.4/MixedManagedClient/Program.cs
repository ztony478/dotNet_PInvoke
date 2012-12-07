using System;
using System.Collections.Generic;
using System.Text;

namespace MixedManagedClient
{
    class Program
    {
        static void Main(string[] args)
        {
            MixedLib.MixedManagedClass managedObj0 = new MixedLib.MixedManagedClass();
            managedObj0.PrintMessage();

            MixedLib.MixedSourceCode managedObj1 = new MixedLib.MixedSourceCode();
            int maxNum = managedObj1.FindBiggestNumber(0, 3, 9);
            Console.WriteLine("The max number among (0, 3, 9) is: {0}", maxNum);

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
