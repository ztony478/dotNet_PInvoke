#pragma once

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace CppInteropWrapper
{
	//declare unmanaged functions for PInvoke usage
	[DllImport("NativeLib.dll", 
		CharSet=CharSet::Unicode, EntryPoint="ReverseString")]
	extern void PInvokeReverseString(
		String^ rawString, StringBuilder^ result, int bufferSize);

	[DllImport("NativeLib.dll", EntryPoint="MultiplyTwoNumbers")]
	extern int PInvokeMultiplyNumbers(int numberA, int numberB);

	//C++ wrapper for unmanaged function tests
	public ref class WrapperClass
	{
	public:
		int MultiplyNumbers_PInvoke(int numA, int numB);
		int MultiplyNumbers_CppInterop(int numA, int numB);
		void ReverseString_PInvoke(void);
		void ReverseString_CppInterop(void);
	};
}