using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMSimple.Interop;
using System.Threading;

namespace COMThreadApartment
{
    class Program
    {
        //[MTAThread]
        [STAThread]
        static void Main(string[] args)
        {
            Console.WriteLine("初始Apartment为: {0}",
                Thread.CurrentThread.GetApartmentState());

            int result = 0;

            // 调用STA COM对象
            SimpleCOMCalculatorClass staObj
                = new SimpleCOMCalculatorClass();
            result = staObj.Add(3, 5);
            Console.WriteLine("STA对象方法：3 + 5 = {0}, Threading: {1}",
                result, Thread.CurrentThread.GetApartmentState());

            // 调用MTA COM对象
            COMMTAObjClass mtaObj
                = new COMMTAObjClass();
            result = mtaObj.AddIntegers(3, 5);
            Console.WriteLine("MTA对象方法: 3 + 5 = {0}, Threading: {1}",
                result, Thread.CurrentThread.GetApartmentState());

            // 使用SetApartmentState设置Apartment
            try
            {
                Thread.CurrentThread.SetApartmentState(
                    ApartmentState.MTA);
                Console.WriteLine(
                    "调用SetApartmentState方法: {0}", ApartmentState.MTA);
            }
            catch (InvalidOperationException e)
            {
                Console.WriteLine(
                    "SetApartmentState抛出异常信息: {0}",
                    e.Message);
            }

            // 使用TrySetApartmentState设置Apartment
            try
            {
                bool changeStatus =
                    Thread.CurrentThread.TrySetApartmentState(
                        ApartmentState.MTA);
                Console.WriteLine(
                    "TrySetApartmentState返回结果: 设置{0}",
                    changeStatus ? "成功" : "失败");
            }
            catch (InvalidOperationException e)
            {
                Console.WriteLine(
                    "TrySetApartmentStates抛出异常信息: {0}",
                    e.Message);
            }

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
