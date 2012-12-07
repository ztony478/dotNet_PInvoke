using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMSimple.Interop;

namespace COMCalculatorClient
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            CreateInstanceByWrapper();

            CreateInstanceByCustomWrapper();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        static void CreateInstanceByWrapper()
        {
            int num0 = 6, num1 = 4;

            SimpleCOMCalculatorClass calcObj = new SimpleCOMCalculatorClass();

            Console.WriteLine("运算：{0} + {1} = {2}",
                num0, num1, calcObj.Add(num0, num1));

            Console.WriteLine("运算：{0} - {1} = {2}",
                num0, num1, calcObj.Subtract(num0, num1));

            ISimpleCOMCalculator calcInterfaceObj = new SimpleCOMCalculatorClass();

            Console.WriteLine("运算：{0} * {1} = {2}",
                num0, num1, calcInterfaceObj.Multiply(num0, num1));

            Console.WriteLine("运算：{0} / {1} = {2}",
                num0, num1, calcInterfaceObj.Divide(num0, num1));

            int factorialResult = num1;
            calcInterfaceObj.Factorial(ref factorialResult);
            Console.WriteLine("运算：!{0} = {1}",
                            num1, factorialResult);

        }

        static void CreateInstanceByCustomWrapper()
        {
            CreateInstanceByCustomeWrapperClass.DoTest();
        }
    }
}
