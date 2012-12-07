using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace COMCalculatorClient
{
    [ComImport]
    [Guid("C7386CE7-47B0-43C4-82D4-5FFA7A359EEA")]
    public class SimpleCOMCalculatorWrapper
    {
    }

    [ComImport]
    [CoClass(typeof(SimpleCOMCalculatorWrapper))]
    [Guid("FB1DE569-9B3D-491F-8EFC-25478CFBF172")]
    public interface ISimpleCOMCalculatorWrapper
    {
        [DispId(1)]
        int Add(int num0, int num1);
    }

    public class CreateInstanceByCustomeWrapperClass
    {
        public static void DoTest()
        {
            SimpleCOMCalculatorWrapper obj = new SimpleCOMCalculatorWrapper();
            ISimpleCOMCalculatorWrapper intf = obj as ISimpleCOMCalculatorWrapper;
            if (null != intf)
            {
                int result = intf.Add(1, 2);
                Console.WriteLine("\n用自定义包装类创建COM对象。计算器：1 + 2 = {1}",
                    obj.GetType().Name, result);
            }
        }
    }

}
