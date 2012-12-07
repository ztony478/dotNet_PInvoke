using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMErrorInfo.Interop;
using System.Runtime.InteropServices;

namespace COMMarshalErrorInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMErrorInfo();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMErrorInfo()
        {
            MarshalErrorInfoClass comObj = new MarshalErrorInfoClass();

            for (int i = 0; i < 8; i++)
            {
                try
                {
                    comObj.GenerateCOMError(i);
                    Console.WriteLine("\n第{0}次调用没有异常。", i);
                }
                catch (Exception e)
                {
                    int hResult = Marshal.GetHRForException(e);
                    Console.WriteLine("\n第{0}次调用抛出异常：类型：{1}。HRESULT = 0x{2:X}。\n消息：{3}。\n代码：{4}",
                        i, e.GetType().Name, hResult, e.Message, e.Source);
                }
            }
        }
    }
}
