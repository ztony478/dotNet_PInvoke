using System;
using System.Collections.Generic;
using System.Text;


namespace Handles
{
    class Program
    {
        static void Main(string[] args)
        {
            HandleRefSample hRef = new HandleRefSample();
            SafeHandleSample safeHandle = new SafeHandleSample();
            UnsafeHandleSample unsafeHandle = new UnsafeHandleSample();

            hRef.Test();
            safeHandle.Test();
            unsafeHandle.Test();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }
}
