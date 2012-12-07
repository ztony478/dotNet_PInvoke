using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace AnsiUnicodeSample
{
    class Program
    {
        static void Main(string[] args)
        {

            /****************Ansi 6 demos******************/
            // 使用默认CharSet的示例，能够正确运行
            DefaultCharSetDemo.Test();

            // 显式地指定CharSet为CharSet.Ansi的示例，能够正确运行
            CharSetAsAnsiDemo.Test();

            // 使用默认CharSet，但指定EntryPoint为GetUserNameA
            // 的示例, 能够正确运行
            DefaultCharSetAndEntryPointSpecifiedDemo.Test();

            //显式地指定CharSet为CharSet.Ansi，且指定
            // EntryPoint为GetUserNameA的示例，能够正确运行
            CharSetAsAnsiAndEntryPointSpecifiedDemo.Test();

            // 指定EntryPoint为GetUserNameA，但却指定CharSet
            // 为CharSet.Unicode，则会产生错误的结果
            CharSetAndEntryPointMismatchDemo.Test();

            // 指定EntryPoint为GetUserNameA，但却指定CharSet
            // 为CharSet.Auto，在Windows XP下运行，会产生错误的结果            
            CharSetAsAutoAndEntryPointDemo.Test();


            /****************Unicode 5 demos******************/
            // 显式地指定CharSet为CharSet.Unicode的示例，能够正确运行
            CharSetAsUnicodeDemo.Test();

            // 显式地指定CharSet为CharSet.Unicode，且EntryPoint为GetUserNameW，能够正确运行
            CharSetAsUnicodeAndEntryPointMatchedDemo.Test();

            // 指定EntryPoint为GetUserNameW，但却指定CharSet
            // 为CharSet.Ansi，则会产生错误的结果
            CharSetAsUnicodeAndEntryPointMismatchDemo.Test();

            // 指定EntryPoint为GetUserNameW，同时指定CharSet
            // 为CharSet.Auto，在Windows XP下，能够正确运行
            CharSetAsAutoAndEntryPointSpecifiedDemo.Test();

            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("\r\n以下测试方法用于演示抛出异常的情况");
            Console.ResetColor();

            // 设置ExactSpelling为true，同时指定CharSet
            // 为CharSet.Unicode，会抛出异常
            CharSetAsUnicodeButWithExactSpellingTrueDemo.Test();

            // 指定CharSet为CharSet.Unicode，但是却修改了函
            // 数名称，会抛出异常
            CharSetAsUnicodeButWithModifiedRootFunctionNameDemo.Test();


            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	

        }
        


    }
}
