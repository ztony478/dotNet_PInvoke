using System;
using System.Collections.Generic;
using System.Text;
using CppInteropWrapper;

namespace ExceptionCSharpClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("----- P/Invoke, Runtime Exception -----");
            ExceptionPInvoke.CauseUnmanagedException();

            Console.WriteLine("\n----- P/Invoke, Thrown Exception -----");
            ExceptionPInvoke.ThrowUnmanagedException();

            Console.WriteLine("\n----- Cpp Interop, Thrown Exception -----");
            TestMCppWrapperException();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void TestMCppWrapperException()
        {
            try
            {
                ThrowUnmanagedExceptionWrapperClass.CallUnmanagedException(UnmanagedExceptionType.ThrowErrorCode);
            }
            catch (WrapperException ex)
            {
                Console.WriteLine("[*]WrapperException: Message-{0}, ErrorCode-{1}", ex.Message, ex.ErrorCode);
            }

            try
            {
                ThrowUnmanagedExceptionWrapperClass.CallUnmanagedException(UnmanagedExceptionType.ThrowCustomException);
            }
            catch (WrapperException ex)
            {
                Console.WriteLine("[*]WrapperException: Message-{0}, ErrorCode-{1}", ex.Message, ex.ErrorCode);
            }

            try
            {
                ThrowUnmanagedExceptionWrapperClass.CallUnmanagedException(UnmanagedExceptionType.ThrowStdException);
            }
            catch (WrapperException ex)
            {
                Console.WriteLine("[*]WrapperException: Message-{0}, ErrorCode-{1}", ex.Message, ex.ErrorCode);
            }
        }
    }
}
