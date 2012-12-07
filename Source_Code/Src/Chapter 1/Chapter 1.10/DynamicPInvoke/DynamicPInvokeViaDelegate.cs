using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.Reflection;

namespace DynamicPInvoke
{
    class DynamicPInvokeViaDelegate
    {
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        delegate int MultiplyDelegate(int factorA, int factorB);

        public static void Test()
        {
            string entryPoint = "_Multiply@8";
            string currentDirectory = 
                Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            string dllPath = Path.Combine(currentDirectory, 
                    @"nativelibfordynamicpinvoke\NativeLibForDynamicPInvoke.dll");
            
            //动态加载需要平台调用的非托管DLL
            IntPtr dllAddr = Win32API.LoadLibrary(dllPath);
            if (dllAddr == IntPtr.Zero)
            {
                throw new DllNotFoundException(string.Format("Can not load {0}, please check.", 
                    dllPath));
            }

            //获得需要调用的函数的地址
            IntPtr procAddr = Win32API.GetProcAddress(dllAddr, entryPoint);
            if (procAddr == IntPtr.Zero)
            {
                throw new EntryPointNotFoundException(
                    string.Format("Can not find entry point \"{0}\" in dll \"{1}\", please check.", 
                    entryPoint, dllPath));
            }

            //使用代理来封送函数指针
            MultiplyDelegate multiplyDelegate =
                (MultiplyDelegate)Marshal.GetDelegateForFunctionPointer(
                procAddr, typeof(MultiplyDelegate));

            //调用非托管函数
            int factorA = 100, factorB = 8;
            int result = multiplyDelegate(factorA, factorB);

            //释放加载的DLL
            bool isFree = Win32API.FreeLibrary(dllAddr);
            if (isFree)
            {
                Console.WriteLine("Successfully  free {0}.",
                    Path.GetFileName(dllPath));
            }
            else
            {
                throw new Exception(string.Format("Can not free {0}.",
                    Path.GetFileName(dllPath)));
            }

            //打印结果
            Console.WriteLine(string.Format("{0} * {1} = {2} ", factorA, factorB, result));
        }

    }
}
