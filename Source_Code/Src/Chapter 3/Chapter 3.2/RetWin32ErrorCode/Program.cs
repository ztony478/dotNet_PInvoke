using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace RetWin32ErrorCode
{
    class Program
    {
        static void Main(string[] args)
        {

            //RetErrorCodeDemo.TestErrorCode();

            RetErrorCodeDemo.TestFormatErrorMsg();

            RetErrorCodeDemo.TestErrorMsgByWin32Exception();

            RetErrorCodeDemo.TestErrorMsgByWin32ExceptionDefault();

            //WithoutSetLastErrorDemo.Test();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

    }
}
