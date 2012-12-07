using System;
using System.Collections.Generic;
using System.Text;

namespace PInvokeBestPractice
{
    class Program
    {
        static void Main(string[] args)
        {
            // 采用最佳实践所提倡的方式调用MessageBeep方法
            Console.WriteLine("Wait for the system sound ...");
            NativeSound.MessageBeep(BeepTypes.MB_ICONEXCLAMATION);

            Console.WriteLine();

            // 使用不同的类型来测试GetVersionInfoEx的性能
            PerformanceTest perf = new PerformanceTest();
            perf.PerfTest(1000 * 1000);
            perf.ExplicitLayoutTest(1000 * 1000);

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }
}
