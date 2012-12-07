using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMErrorResult.Interop;
using System.Runtime.InteropServices;

namespace COMMarshalHRESULT
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMHRESULT();

            Console.WriteLine();

            MarshalCOMReturnHRESULT();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMHRESULT()
        {
            MarshalCOMHRESULTClass comObj = new MarshalCOMHRESULTClass();

            for (int i = 0; i < 8; i++)
            {
                try
                {
                    comObj.GenerateHRESULTs(i);
                    Console.WriteLine("\n第{0}次调用没有异常。", i);
                }
                catch (Exception e)
                {
                    int hResult = Marshal.GetHRForException(e);
                    Console.WriteLine("\n第{0}次调用抛出异常：类型：{1}。HRESULT = 0x{2:X}",
                        i, e.GetType().Name, hResult);
                }
            }
        }

        private static void MarshalCOMReturnHRESULT()
        {
            MarshalCOMHRESULTClass comObj = new MarshalCOMHRESULTClass();

            for (int i = 0; i < 8; i++)
            {
                int hResult;
                try
                {
                    hResult = comObj.ReturnHRESULTs(i);
                    Console.WriteLine("\n第{0}次调用没有异常。HRESULT = 0x{1:X}", i, hResult);
                }
                catch (Exception e)
                {
                    hResult = Marshal.GetHRForException(e);
                    Console.WriteLine("\n第{0}次调用抛出异常：类型：{1}。HRESULT = 0x{2:X}",
                        i, e.GetType().Name, hResult);
                }
            }
        }

    }
}
