using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.Reflection;

namespace DynamicPInvoke
{
    class DynamicPInvokeViaLoadLib
    {
        [DllImport("NativeLibForDynamicPInvoke.dll")]
        static extern int Multiply(int factorA, int factorB);

        public static void Test()
        {
            string currentDirectory = 
                Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

            string dllPath = Path.Combine(currentDirectory, 
               @"nativelibfordynamicpinvoke\NativeLibForDynamicPInvoke.dll");
            IntPtr dllAddr = Win32API.LoadLibrary(dllPath);

            if (dllAddr == IntPtr.Zero)
            {
                throw new DllNotFoundException(
                    string.Format("Can not load {0}, please check.", dllPath));
            }

            //调用非托管函数
            int factorA = 100, factorB = 8;
            int result = Multiply(factorA, factorB);

            //打印结果
            Console.WriteLine(string.Format("{0} * {1} = {2} ", factorA, factorB, result));
        }

    }

}
     