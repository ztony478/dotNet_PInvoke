// CppInterop_MarshalString.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <vcclr.h>

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged
class CMarshalString
{
public:
	static char* CMarshalString::ReverseStringAnsi(const char *str)
	{
		size_t length = strlen(str);
		char* newBuffer = new char[length+1];
		strcpy_s(newBuffer, length+1, str);
		return _strrev(newBuffer);
	}

	static wchar_t* CMarshalString::ReverseStringUnicode(const wchar_t *str)
	{
		size_t length = wcslen(str);
		wchar_t* newBuffer = new wchar_t[length+1];
		wcscpy_s(newBuffer, length+1, str);
		return _wcsrev(newBuffer);
	}
};
#pragma managed

public ref class MarshalStringWrapper
{
public:
	String^ MarshalStringAnsi(String^ inputString)
	{

		// 将托管字符串封送为非托管Ansi字符串
		IntPtr pStrPtr
			= Marshal::StringToHGlobalAnsi(inputString);
		const char* pStr 
			= static_cast<char*>(pStrPtr.ToPointer());
		// 将指针传递给非托管方法
		char* pNewStr 
			= CMarshalString::ReverseStringAnsi(pStr);
		// 根据返回值生成托管字符串
		String^ retString = gcnew String(pNewStr);
		// 释放作为非托管函数返回的字符串内存
		delete [] pNewStr;
		// 释放封送到非托管内存中的Ansi字符串
		Marshal::FreeHGlobal(pStrPtr);

		return retString;
	}

	String^ MarshalStringUnicode(String^ inputString)
	{
		// 用PtrToStringChars获得指向托管字符串的内部指针
		// pin_ptr可以锁定内存，避免被垃圾回收器释放
		pin_ptr<const wchar_t> pStr 
			= PtrToStringChars(inputString);
		// 将指针传递给非托管方法
		wchar_t* pNewStr 
			= CMarshalString::ReverseStringUnicode(pStr);
		// 根据返回值生成托管字符串
		String^ retString = gcnew String(pNewStr);
		// 释放作为非托管函数返回的字符串内存
		delete [] pNewStr;

		return retString;
	}
};

int main(array<System::String ^> ^args)
{
	MarshalStringWrapper^ wrapperObj = gcnew MarshalStringWrapper();
	String^ inputString;
	String^ resultString;

	// 测试Unicode版本
	inputString = "Test Unicode";
	Console::WriteLine("\n原始字符串：{0}", inputString);
	resultString = wrapperObj->MarshalStringUnicode(inputString);
	Console::WriteLine("结果字符串：{0}", resultString);

	// 测试Ansi版本
	inputString = "Test Ansi";
	Console::WriteLine("\n原始字符串：{0}", inputString);
	resultString = wrapperObj->MarshalStringAnsi(inputString);
	Console::WriteLine("结果字符串：{0}", resultString);

	Console::WriteLine("\r\n按任意键退出...");
	Console::Read();

    return 0;
}
