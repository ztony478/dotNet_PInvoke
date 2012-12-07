using System;
using System.Collections.Generic;
using System.Text;

namespace ImprovePerformance
{
    class Program
    {
        static void Main(string[] args)
        {
            ExplicitlyNameMethod.PerfTest();

            BlittableNonBlittableCompare.PerfTest();

            UnicodeANSIConversionTest.PerfTest();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }
}
