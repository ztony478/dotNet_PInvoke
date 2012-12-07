using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using SampleCOMSimple.Interop;

namespace ReleaseCOMObject
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            ReleaseCOMObject();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void ReleaseCOMObject()
        {
            SimpleCOMCalculatorClass comObj = new SimpleCOMCalculatorClass();
            int integer = 5;
            Console.Write("!{0} = ", integer);
            try
            {
                comObj.Factorial(ref integer);
                // 显示COM方法调用结果
                Console.WriteLine("{0}", integer);
            }
            finally
            {
                // 显式释放COM对象
                Console.WriteLine("调用Marshal.ReleaseComObject()释放COM对象...");
                int referenceCount = Marshal.ReleaseComObject(comObj);
                Console.WriteLine("COM对象目前的引用计数为：{0}", referenceCount);
            }
            
            Console.WriteLine("再次调用COM对象的方法Add()：");
            try
            {
                int result = comObj.Add(3, 5);
                Console.WriteLine("3 + 5 = {0}", result);
            }
            catch (Exception e)
            {
                Console.WriteLine("异常抛出：{0}\n消息：{1}", e.GetType().Name, e.Message);
            }
        }
    }
}
