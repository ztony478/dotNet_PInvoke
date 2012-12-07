using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace ImprovePerformance
{
    class ExplicitlyNameMethod
    {
        public static void PerfTest()
        {
            // 为了创建一个公平的测试环境，在进行
            // 正式对比测试前，至少要对非托管函数
            // 进行一次平台调用，以便完成加载非托
            // 管DLL，查找函数入口点等过程
            string rawString = "Bill";
            StringBuilder sb = new StringBuilder(rawString.Length);
            UnmanagedFuction.ReverseString(rawString, sb);

            StringBuilder sbW = new StringBuilder(rawString.Length);
            UnmanagedFuction.ReverseStringA(rawString, sbW);

            //运行一定数量级的测试次数，对比性能
            const int testCycle = 600000;

            //用于记时
            Stopwatch stopWatch = new Stopwatch();

            //测试未设置ExactSpelling的非托管函数
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {
                sb = new StringBuilder(rawString.Length);
                UnmanagedFuction.ReverseString(rawString, sb);
            }
            stopWatch.Stop();
            Console.WriteLine(
                "Call ReverseString {0} times, "
                + "take {1} milliseconds",
                testCycle, stopWatch.ElapsedMilliseconds);

            //测试设置ExactSpelling = true的非托管函数
            stopWatch.Reset();
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {
                sbW = new StringBuilder(rawString.Length);
                UnmanagedFuction.ReverseStringA(rawString, sbW);
            }
            stopWatch.Stop();
            Console.WriteLine(
                "Call ReverseStringA {0} times, "
                + "take {1} milliseconds",
                testCycle, stopWatch.ElapsedMilliseconds);
        }

    }
}

