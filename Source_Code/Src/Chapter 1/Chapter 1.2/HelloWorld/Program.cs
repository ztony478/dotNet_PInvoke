using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace HelloWorld
{
    class Program
    {
        // Unmanaged function
        //void __stdcall PrintMsg(const char* msg);
        [DllImport("NativeLib.dll")]
        static extern void PrintMsg(string msg);

        static void Main(string[] args)
        {
            PrintMsg("Hello world!");

            //Win32APIConsoleHelloWorld.SayHelloWorld();

            //Win32APIWindowHelloWorld.SayHelloWorld();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }
}
