using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace ImprovePerformance
{
    class UsingIntPtr
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

            IntPtr reversedStringPtr = Marshal.AllocHGlobal(rawString.Length * 2);
            UnmanagedFuction.ReverseString(rawString, reversedStringPtr);
            string reversedString = Marshal.PtrToStringAnsi(reversedStringPtr);

            //运行一定数量级的测试次数，对比性能
            const int testCycle = 600000;

            //用于记时
            Stopwatch stopWatch = new Stopwatch();

            //测试Nonblittable函数
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

            //测试blittable函数
            stopWatch.Reset();
            stopWatch.Start();
            for (int i = 0; i < testCycle; i++)
            {   
                UnmanagedFuction.ReverseString(rawString, reversedStringPtr);
                string newReversedString = Marshal.PtrToStringAnsi(reversedStringPtr);
            }
            Marshal.FreeHGlobal(reversedStringPtr);
            stopWatch.Stop();
            Console.WriteLine(
                "Call ReverseString with IntPtr as param type {0} times, "
                + "take {1} milliseconds",
                testCycle, stopWatch.ElapsedMilliseconds);

            Console.WriteLine("Press any key to exit");
            Console.Read();
        }

    }
}
