using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.Reflection;
using System.Reflection.Emit;

namespace DynamicPInvoke
{
    class DynamicPInvokeViaEmit
    {
        public static void Test()
        {
            string currentDirectory = 
                Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string dllPath = Path.Combine(currentDirectory, 
                @"nativelibfordynamicpinvoke\NativeLibForDynamicPInvoke.dll");

            //定义参数和返回值的类型
            Type[] parameterTypes = new Type[] { typeof(int), typeof(int) };
            int factorA = 100, factorB = 8;
            Type returnType = typeof(int);
            
            //设置参数的值
            object[] parameterValues = { factorA, factorB };

            // 设置函数入口点，必须是经过名称重整后的函数名
            // 原因在于非托管DLL使用的调用约定是__stdcall
            // 如果使用Multiply，将会抛出一个如下的异常
            //Unhandled Exception: System.Reflection.TargetInvocationException: Exception has
            //been thrown by the target of an invocation. ---> System.EntryPointNotFoundException: 
            //Unable to find an entry point named 'Multiply' in DLL 'D:\nativelibfordynamicpinvoke\
            //NativeLibForDynamicPInvoke.dll'.
            string entryPoint = "_Multiply@8";

            //设置DllImport的字段
            CallingConvention nativeCallConv = CallingConvention.StdCall;
            CharSet nativeCharSet = CharSet.Ansi;

            //设置方法的修饰符，至少需要设置static和extern
            MethodAttributes methodAttr = 
                MethodAttributes.Static
                | MethodAttributes.Public
                | MethodAttributes.PinvokeImpl;

            //进行动态平台调用
            object result = DynamicDllFunctionInvoke(
                dllPath, 
                entryPoint, 
                methodAttr, 
                nativeCallConv,
                nativeCharSet, 
                returnType, 
                parameterTypes, 
                parameterValues
                );

            //打印结果
            Console.WriteLine(
                string.Format("{0} * {1} = {2} ", 
                factorA, 
                factorB, 
                result)
                );
        }

        public static object DynamicDllFunctionInvoke(
            string dllPath,
            string entryPoint,
            MethodAttributes methodAttr,
            CallingConvention nativeCallConv,
            CharSet nativeCharSet,
            Type returnType,
            Type[] parameterTypes,
            object[] parameterValues
            )
        {
            string dllName = Path.GetFileNameWithoutExtension(dllPath);
            // 创建一个动态程序集(assembly)和模块(module)
            AssemblyName assemblyName = new AssemblyName();
            assemblyName.Name = string.Format("A{0}{1}", 
                dllName, 
                Guid.NewGuid().ToString( "N" )
                );
            AssemblyBuilder dynamicAssembly =
              AppDomain.CurrentDomain.DefineDynamicAssembly(
              assemblyName, AssemblyBuilderAccess.Run);
            ModuleBuilder dynamicModule =
              dynamicAssembly.DefineDynamicModule(
              string.Format("M{0}{1}", 
              dllName, 
              Guid.NewGuid().ToString("N"))
              );

            // 使用指定的信息创建平台调用签名
            MethodBuilder dynamicMethod = 
                dynamicModule.DefinePInvokeMethod(
                entryPoint,
                dllPath,
                methodAttr,
                CallingConventions.Standard,
                returnType,
                parameterTypes,
                nativeCallConv,
                nativeCharSet
                );

            // 创建函数
            dynamicModule.CreateGlobalFunctions();

            // 获得平台调用的方法
            MethodInfo methodInfo = 
                dynamicModule.GetMethod(entryPoint, parameterTypes);
            // 调用非托管函数并获得返回的结果
            object result = methodInfo.Invoke(null, parameterValues);
            return result;
        }

    }
}


 class DynamicPInvokeViaEmit
    {
        public static void Test()
        {
            string currentDirectory = 
                Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string dllPath = Path.Combine(currentDirectory, 
                @"nativelibfordynamicpinvoke\NativeLibForDynamicPInvoke.dll");

            //定义参数和返回值的类型
            Type[] parameterTypes = new Type[] { typeof(int), typeof(int) };
            int factorA = 100, factorB = 8;
            Type returnType = typeof(int);
            
            //设置参数的值
            object[] parameterValues = { factorA, factorB };

            // 设置函数入口点，必须是经过名称重整后的函数名
            // 原因在于非托管DLL使用的调用约定是__stdcall
            // 如果使用Multiply，将会抛出一个如下的异常
            //Unhandled Exception: System.Reflection.TargetInvocationException: Exception has
            //been thrown by the target of an invocation. ---> System.EntryPointNotFoundException: 
            //Unable to find an entry point named 'Multiply' in DLL 'D:\nativelibfordynamicpinvoke\
            //NativeLibForDynamicPInvoke.dll'.
            string entryPoint = "_Multiply@8";

            //设置DllImport的字段
            CallingConvention nativeCallConv = CallingConvention.StdCall;
            CharSet nativeCharSet = CharSet.Ansi;

            //设置方法的修饰符，至少需要设置static和extern
            MethodAttributes methodAttr = 
                MethodAttributes.Static
                | MethodAttributes.Public
                | MethodAttributes.PinvokeImpl;

            //进行动态平台调用
            object result = DynamicDllFunctionInvoke(
                dllPath, 
                entryPoint, 
                methodAttr, 
                nativeCallConv,
                nativeCharSet, 
                returnType, 
                parameterTypes, 
                parameterValues
                );

            //打印结果
            Console.WriteLine(
                string.Format("{0} * {1} = {2} ", 
                factorA, 
                factorB, 
                result)
                );
        }

        public static object DynamicDllFunctionInvoke(
            string dllPath,
            string entryPoint,
            MethodAttributes methodAttr,
            CallingConvention nativeCallConv,
            CharSet nativeCharSet,
            Type returnType,
            Type[] parameterTypes,
            object[] parameterValues
            )
        {
            string dllName = Path.GetFileNameWithoutExtension(dllPath);
            // 创建一个动态程序集(assembly)和模块(module)
            AssemblyName assemblyName = new AssemblyName();
            assemblyName.Name = string.Format("A{0}{1}", 
                dllName, 
                Guid.NewGuid().ToString( "N" )
                );
            AssemblyBuilder dynamicAssembly =
              AppDomain.CurrentDomain.DefineDynamicAssembly(
              assemblyName, AssemblyBuilderAccess.Run);
            ModuleBuilder dynamicModule =
              dynamicAssembly.DefineDynamicModule(
              string.Format("M{0}{1}", 
              dllName, 
              Guid.NewGuid().ToString("N"))
              );

            // 使用指定的信息创建平台调用签名
            MethodBuilder dynamicMethod = 
                dynamicModule.DefinePInvokeMethod(
                entryPoint,
                dllPath,
                methodAttr,
                CallingConventions.Standard,
                returnType,
                parameterTypes,
                nativeCallConv,
                nativeCharSet
                );

            // 创建函数
            dynamicModule.CreateGlobalFunctions();

            // 获得平台调用的方法
            MethodInfo methodInfo = 
                dynamicModule.GetMethod(entryPoint, parameterTypes);
            // 调用非托管函数并获得返回的结果
            object result = methodInfo.Invoke(null, parameterValues);
            return result;
        }

    }