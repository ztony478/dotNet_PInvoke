using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace COMLateBinding
{
    class Program
    {
        static void Main(string[] Args)
        {
            // 通过ProgID返回COM对象类型
            Type comType = Type.GetTypeFromProgID(
                "SampleCOMSimple.SimpleCOMCalculator.1");

            // 也可以通过CLSID返回COM对象类型
            //Guid clsid = new Guid("C7386CE7-47B0-43C4-82D4-5FFA7A359EEA");
            //Type comType = Type.GetTypeFromCLSID(clsid);

            // 创建COM对象实例
            Object comObj = Activator.CreateInstance(comType);

            // 设置方法参数
            Object[] methodArgs = { 6, 4 };

            // 调用加法
            Object result = comType.InvokeMember(
                "Add", BindingFlags.InvokeMethod, null,
                comObj, methodArgs);

            Console.WriteLine("运算：{0} + {1} = {2}",
                methodArgs[0], methodArgs[1], result);

            // 调用减法
            result = comType.InvokeMember(
                "Subtract", BindingFlags.InvokeMethod, null,
                comObj, methodArgs);

            Console.WriteLine("运算：{0} - {1} = {2}",
                methodArgs[0], methodArgs[1], result);

            // 调用乘法
            result = comType.InvokeMember(
                "Multiply", BindingFlags.InvokeMethod, null,
                comObj, methodArgs);

            Console.WriteLine("运算：{0} * {1} = {2}",
                methodArgs[0], methodArgs[1], result);

            // 调用除法
            result = comType.InvokeMember(
                "Divide", BindingFlags.InvokeMethod, null,
                comObj, methodArgs);

            Console.WriteLine("运算：{0} / {1} = {2}",
                methodArgs[0], methodArgs[1], result);

            // 调用阶乘方法
            // 由于参数需要从方法中返回结果，要使用ParameterModifier
            ParameterModifier paramMod = new ParameterModifier(1);
            paramMod[0] = true;

            int factorialArg = 4;
            Object[] methodArgs1 = { factorialArg };
            result = comType.InvokeMember(
                "Factorial", BindingFlags.InvokeMethod, null,
                comObj, methodArgs1, new ParameterModifier[] { paramMod },
                null, null);
            Console.WriteLine("运算：!{0} = {1}",
                            factorialArg, methodArgs1[0]);

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }
    }
}
