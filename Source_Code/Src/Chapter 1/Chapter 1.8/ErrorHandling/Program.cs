using System;
using System.Collections.Generic;
using System.Text;

namespace ErrorHandling
{
    class Program
    {
        static void Main(string[] args)
        {
            //Managed side errors
            DLLErrorDemo.TestNonDll();
            EntryPointErrorDemo1.TestNonFunction();
            EntryPointErrorDemo2.TestNonFunctionWithWrongParamType();
            CharSetErrorDemo.Test();

            // Unmaged side errors
            IncorrectParamTest.Test();
            DivideByZeroTest.Test();
            UnallocatedBuffer.Test();
            UnmanageException.TestCppException();
            UnmanageException.TestCStyleException();
            UnmanageException.TestCStyleExceptionNoRegular();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }

}
