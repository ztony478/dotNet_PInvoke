using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using CppInteropWrapper;

namespace ExceptionCSharpClient
{
    internal class ExceptionPInvoke
    {
        private const string _dllName = "NativeLib.dll";

        // extern "C" NATIVELIB_API void __cdecl CauseUnmanagedExceptions(int type);
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "CauseUnmanagedExceptions")]
        private extern static void PInvokeCauseUnmanagedExceptions(UnmanagedExceptionType type);

        // extern "C" NATIVELIB_API void __cdecl ThrowUnmanagedExceptions(int type);
        [DllImport(_dllName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "ThrowUnmanagedExceptions")]
        private extern static void PInvokeThrowUnmanagedExceptions(UnmanagedExceptionType type);

        public static void CauseUnmanagedException()
        {
            try
            {
                PInvokeCauseUnmanagedExceptions(UnmanagedExceptionType.DivedeByZero);
            }
            catch(DivideByZeroException e)
            {
                Console.WriteLine("[*]DivideByZeroException: {0}", e.Message);
            }

            try
            {
                PInvokeCauseUnmanagedExceptions(UnmanagedExceptionType.AccessInvalidMemory);
            }
            catch (AccessViolationException e)
            {
                Console.WriteLine("[*]AccessViolationException: {0}", e.Message);
            }
 
        }

        public static void ThrowUnmanagedException()
        {
            try
            {
                PInvokeThrowUnmanagedExceptions(UnmanagedExceptionType.ThrowErrorCode);
            }
            catch (SEHException e)
            {
                Console.WriteLine("[*]ThrowErrorCode: {0}", e.Message);
            }

            try
            {
                PInvokeThrowUnmanagedExceptions(UnmanagedExceptionType.ThrowCustomException);
            }
            catch (SEHException e)
            {
                Console.WriteLine("[*]ThrowCustomException: {0}", e.Message);
            }

            try
            {
                PInvokeThrowUnmanagedExceptions(UnmanagedExceptionType.ThrowStdException);
            }
            catch (SEHException e)
            {
                Console.WriteLine("[*]ThrowStdException: {0}", e.Message);
            }
            
        }
    }
}
