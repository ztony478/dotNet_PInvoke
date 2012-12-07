#include "StdAfx.h"
#include "WrapperClass.h"
#include "..\..\NativeLib\NativeLib.h"

namespace CppInteropWrapper
{

	// 通过P/Invoke调用函数MultiplyTwoNumbers
	int WrapperClass::MultiplyNumbers_PInvoke(int numA, int numB)
	{
		return PInvokeMultiplyNumbers(numA, numB);
	}

	// 通过c++ Interop调用函数MultiplyTwoNumbers
	int WrapperClass::MultiplyNumbers_CppInterop(int numA, int numB)
	{
		return MultiplyTwoNumbers(numA, numB);
	}

	// 通过P/Invoke调用函数ReverseString
	void WrapperClass::ReverseString_PInvoke()
	{
		// 创建StringBuilder作为字符串缓冲区
		String^ rawString = L"String_PInvoke";
		StringBuilder^ buf  = gcnew StringBuilder(rawString->Length);
		int bufferSize = buf->Capacity + 1;
		
		// P/Invoke调用ReverseString函数
		PInvokeReverseString(rawString, buf, bufferSize);
		Console::WriteLine("翻转字符串结果（P/Invoke）：{0} -> {1}", rawString, buf->ToString());
	}

	// 通过c++ Interop调用函数ReverseString
	void WrapperClass::ReverseString_CppInterop()
	{
		wchar_t* buf = new wchar_t[500];
		// c++ Interop调用ReverseString函数
		ReverseString(L"String_CppInterop", buf, 500);

		// 根据返回值创建System.String的实例
		String^ result = gcnew String(buf);
		
		delete [] buf;
		Console::WriteLine("翻转字符串结果（C++ Interop）：{0} -> {1}", "String_CppInterop", result);
	}

}
