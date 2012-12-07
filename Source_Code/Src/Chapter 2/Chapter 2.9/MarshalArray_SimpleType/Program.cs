using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace MarshalArray
{
    class Program
    {
        private const string _dllName = "NativeLib.dll";

        // 简单数组示例
        // UINT __cdecl TestArrayOfChar(char charArray[], int arraySize);
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private extern static uint TestArrayOfChar([In, Out] char[] charArray, int arraySize);

        // int __cdecl TestArrayOfInt(int intArray[], int arraySize);
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl)]
        private extern static int TestArrayOfInt(int[] intArray, int arraySize);

        // 字符串数组示例
        // void __cdecl TestArrayOfString(char* ppStrArray[], int size)
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        private extern static void TestArrayOfString([In, Out] string[] charArray, int arraySize);

        // int __cdecl TestRefArrayOfString(void** strArray, int* size)
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        private extern static int TestRefArrayOfString(out IntPtr charArray, out int arraySize);

        static void Main(string[] args)
        {
            TestCharArray();

            TestIntArray();

            TestStringArray();

            TestRefStringArray();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        private static void TestCharArray()
        {
            char[] charArray = new char[] { 'a', '1', 'b', '2', 'c', '3', '4' };
            Console.WriteLine("\n调用前字符数组元素为：");
            foreach (char c in charArray)
            {
                Console.Write("{0} ", c);
            }

            uint digitCount = TestArrayOfChar(charArray, charArray.Length);

            Console.WriteLine("\n调用前字符数组中数字个数为：{0}", digitCount);

            Console.WriteLine("\n调用后字符数组元素为：");
            foreach (char c in charArray)
            {
                Console.Write("{0} ", c);
            }
        }

        private static void TestIntArray()
        {
            int[] intArray = new int[] { 1, 2, 3, 4, 5, 6, 7 };
            Console.WriteLine("\n\n调用前整数数组元素为：");
            foreach (int i in intArray)
            {
                Console.Write("{0} ", i);
            }

            int sum = TestArrayOfInt(intArray, intArray.Length);

            Console.WriteLine("\n调用前整数数组中所有元素之和为：{0}", sum);

            Console.WriteLine("\n调用后整数数组元素为：");
            foreach (int i in intArray)
            {
                Console.Write("{0} ", i);
            }

            Console.WriteLine();
        }

        private static void TestStringArray()
        {
            string[] strings = new string[] { 
                "This is the first string.",
                "Those are brown horse.",
                "The quick brown fox jumps over a lazy dog." };

            Console.WriteLine("\n原始字符串数组中的元素为：");
            foreach (string originalString in strings)
            {
                Console.WriteLine(originalString);
            }

            TestArrayOfString(strings, strings.Length);

            Console.WriteLine("修改后字符串数组中的元素为：");
            foreach (string reversedString in strings)
            {
                Console.WriteLine(reversedString);
            }
        }

        private static void TestRefStringArray()
        {
            IntPtr arrayPtr;

            // 因为数组是在非托管代码内分配的，所以需要通过返回值或参数给出
            // 在这里arraySize和returnCount的返回值应该是一样的
            int arraySize;
            int returnCount = TestRefArrayOfString(out arrayPtr, out arraySize);
            // 根据返回值确定字符串数量，在托管代码中声明相对应的指针数组
            IntPtr[] arrayPtrs = new IntPtr[returnCount];
            // 将非托管数组中的内容拷贝到托管代码中
            Marshal.Copy(arrayPtr, arrayPtrs, 0, returnCount);

            Console.WriteLine("\n返回的字符串数组中元素的个数为：{0}", returnCount);
            Console.WriteLine("字符串元素：");
            // 声明字符串数组，用于存放最终的结果
            string[] strings = new string[returnCount];
            for (int i = 0; i < returnCount; i++)
            {
                strings[i] = Marshal.PtrToStringUni(arrayPtrs[i]);
                // 释放非托管字符串内存
                Marshal.FreeCoTaskMem(arrayPtrs[i]);
                Console.WriteLine("#{0}: {1}", i, strings[i]);
            }

            // 释放非托管字符串数组内存
            Marshal.FreeCoTaskMem(arrayPtr);
        }
    }
}
