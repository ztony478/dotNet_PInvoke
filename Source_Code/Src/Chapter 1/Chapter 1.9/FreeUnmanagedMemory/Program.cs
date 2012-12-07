using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace FreeUnmanagedMemory
{
    class Program
    {
        //Unmanaged function 
        //wchar_t* GetStringMalloc();
        [DllImport("NativeLib.dll", 
            CallingConvention = CallingConvention.Cdecl, 
            CharSet = CharSet.Unicode
            )]
        static extern string GetStringMalloc();

        //Unmanaged function 
        //wchar_t* GetStringMalloc();
        [DllImport("NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Unicode,
           EntryPoint = "GetStringMalloc"
            )]
        static extern IntPtr GetStringMallocViaIntPtr();

        //Unmanaged function 
        //wchar_t* GetStringNew();
        [DllImport("NativeLib.dll", 
            CallingConvention = CallingConvention.Cdecl, 
            CharSet = CharSet.Unicode
            )]
        static extern IntPtr GetStringNew();

        //Unmanaged function 
        //wchar_t* GetStringCoTaskMemAlloc();
        [DllImport("NativeLib.dll", 
            CallingConvention = CallingConvention.Cdecl, 
            CharSet = CharSet.Unicode
            )]
        static extern string GetStringCoTaskMemAlloc();

        //Unmanaged function 
        //wchar_t* GetStringCoTaskMemAlloc();
        [DllImport("NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Unicode,
            EntryPoint = "GetStringCoTaskMemAlloc"
            )]
        static extern IntPtr GetStringCoTaskMemAllocViaIntPtr();

        //Unmanaged function 
        //void FreeMallocMemory(void* pbuffer);
        [DllImport("NativeLib.dll", 
            CallingConvention = CallingConvention.Cdecl, 
            CharSet = CharSet.Unicode
            )]
        static extern void FreeMallocMemory(IntPtr pbuffer);

        //Unmanaged function 
        //void FreeMallocMemory(void* pbuffer);
        [DllImport("NativeLib.dll", 
            CallingConvention = CallingConvention.Cdecl, 
            CharSet = CharSet.Unicode
            )]
        static extern void FreeMallocMemory(string pbuffer);

        //Unmanaged function 
        //void FreeNewMemory(void* pbuffer);
        [DllImport("NativeLib.dll", 
            CallingConvention = CallingConvention.Cdecl, 
            CharSet = CharSet.Unicode
            )]
        static extern void FreeNewMemory(IntPtr pbuffer);

        //Unmanaged function 
        //void FreeCoTaskMemAllocMemory(void* pbuffer);
        [DllImport("NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Unicode
            )]
        static extern void FreeCoTaskMemAllocMemory(IntPtr pbuffer);        

        static void Main(string[] args)
        {
            //ReturnStringMemoryLeakTest();

            //MemoryReleaseTestViaCoTaskMemAlloc();

            //GetStringMallocViaIntPtrTest();

            //GetStringNewViaIntPtrTest();

            MemoryReleaseTestViaIntPtrCoTaskMemAlloc();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        /// <summary>
        /// 将指向字符串的指针封送成托管的string类型，
        /// 会引起内存泄漏
        /// </summary>
        static void ReturnStringMemoryLeakTest()
        {
            string stringFromMalloc = GetStringMalloc();
            //试图释放已经被封送成托管类型的string
            // 会失败的
            //FreeMallocMemory(stringFromMalloc);
        }

        /// <summary>
        /// 采用修改非托管函数的内存分配
        /// 方法来释放非托管内存
        /// </summary>
        static void MemoryReleaseTestViaCoTaskMemAlloc()
        {  
            string stringViaCoTaskMemAlloc = GetStringCoTaskMemAlloc();
        }

        static void GetStringMallocViaIntPtrTest()
        {
            IntPtr stringPtr = GetStringMallocViaIntPtr();
            //获得string
            string stringFromMalloc = Marshal.PtrToStringUni(stringPtr);

            //调用非托管函数以释放掉非托管内存
            FreeMallocMemory(stringPtr);
        }

        static void GetStringNewViaIntPtrTest()
        {
            IntPtr stringPtr = GetStringNew();
            //获得string
            string stringFromNew = Marshal.PtrToStringUni(stringPtr);

            //调用非托管函数以释放掉非托管内存
            FreeNewMemory(stringPtr);
        }

        static void MemoryReleaseTestViaIntPtrCoTaskMemAlloc()
        {
            IntPtr coTaskMemAllocIntPtr = GetStringCoTaskMemAllocViaIntPtr();
            //获得string
            string stringFromCoTaskMemAlloc = Marshal.PtrToStringUni(coTaskMemAllocIntPtr);

            //调用能够释放由CoTaskMemAlloc分配的内存
            //的非托管函数来释放掉非托管内存
            FreeCoTaskMemAllocMemory(coTaskMemAllocIntPtr);

            //或者直接调用Marshal.FreeCoTaskMem释放掉非托管内存
            //Marshal.FreeCoTaskMem(coTaskMemAllocIntPtr);
        }

    }
}

