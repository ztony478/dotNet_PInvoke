using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace ImprovePerformance
{
    class UnicodeANSIConversionTest
    {
        public static void PerfTest()
        {
            // 为了创建一个公平的测试环境，在进行
            // 正式对比测试前，至少要对非托管函数
            // 进行一次平台调用，以便完成加载非托
            // 管DLL，查找函数入口点等过程
            char testChar = 'h';
            bool nonblittableResult = UnmanagedFuction.IsAsciiNonblittable(testChar);
            Console.WriteLine(
                "{0} is{1} an ASCII character.",
                testChar, nonblittableResult ? "" : " not");

            bool blittableResult = UnmanagedFuction.IsWasciiNonblittable(testChar);
            Console.WriteLine(
                "{0} is{1} an ASCII character.",
                testChar, blittableResult ? "" : " not");

            //运行一定数量级的测试次数，对比性能
            const int testCycle = 600000;
            bool isAscii = false;

            //用于记时
            Stopwatch stopWatch = new Stopwatch();

            //测试Nonblittable函数IsAsciiNonblittable
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {
                isAscii = UnmanagedFuction.IsAsciiNonblittable('c');
            }
            stopWatch.Stop();
            Console.WriteLine(
                "Call nonblittable function IsAsciiNonblittable {0} times, "
                + "take {1} milliseconds",
                testCycle, stopWatch.ElapsedMilliseconds);

            //测试Nonblittable函数IsWasciiNonblittable
            stopWatch.Reset();
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {
                isAscii = UnmanagedFuction.IsWasciiNonblittable('c');
            }
            stopWatch.Stop();
            Console.WriteLine(
                "Call nonblittable function IsWasciiNonblittable {0} times, "
                + "take {1} milliseconds",
                testCycle, stopWatch.ElapsedMilliseconds);
        }
    }
}
