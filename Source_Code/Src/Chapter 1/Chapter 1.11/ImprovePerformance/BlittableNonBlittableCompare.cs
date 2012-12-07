using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace ImprovePerformance
{
    class BlittableNonBlittableCompare
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

            testChar = '和';
            int blittableResult = UnmanagedFuction.IsAsciiBlittable((byte)testChar);
            Console.WriteLine(
                "{0} is{1} an ASCII character.",
                testChar, blittableResult != 0 ? "" : " not");

            //运行一定数量级的测试次数，对比性能
            const int testCycle = 600000;
            bool isAscii = false;

            //用于记时
            Stopwatch stopWatch = new Stopwatch();

            //测试Nonblittable函数
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

            //测试blittable函数
            stopWatch.Reset();
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {
                isAscii = (UnmanagedFuction.IsAsciiBlittable((byte)'c') != 0);
            }
            stopWatch.Stop();
            Console.WriteLine(
                "Call blittable function IsAsciiBlittable {0} times, "
                + "take {1} milliseconds",
                testCycle, stopWatch.ElapsedMilliseconds);

            // 只使用托管代码进行相同的测试
            stopWatch.Reset();
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {
                isAscii = ((byte)'c' < 0x80);
            }
            stopWatch.Stop();
            Console.WriteLine(
                "Only using managed code to do same test, "
                + "take {0} milliseconds",
                stopWatch.ElapsedMilliseconds);

            // 只使用非托管代码进行相同的测试
            stopWatch.Reset();
            stopWatch.Start();
            UnmanagedFuction.UnmanagedTest();
            stopWatch.Stop();
            Console.WriteLine(
                "Only using unmanaged code to do same test, "
                + "take {0} milliseconds",
                stopWatch.ElapsedMilliseconds);
        }

    }
}