using System;
using System.Runtime.InteropServices;

namespace HelloWorld
{
    class Win32APIConsoleHelloWorld
    {
        [DllImport("msvcrt.dll")]
        static extern int puts(string msg);
        [DllImport("msvcrt.dll")]
        static extern int _flushall();

        public static void SayHelloWorld()
        {
            puts("Hello world!");
            _flushall();
        }

    }
}
