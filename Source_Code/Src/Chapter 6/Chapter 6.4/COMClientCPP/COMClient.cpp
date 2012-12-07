// COMClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#include <locale.h>
#import "mscorlib.tlb"
#import "MarshalCommonType.tlb" no_namespace

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");

	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	 
	// 测试普通数据类型
	wprintf(L"------------------ 测试普通数据类型 ---------------------\n");
	TestCommonTypes();
	wprintf(L"\n");

	// 测试参数方向
	wprintf(L"------------------ 测试参数方向属性 ---------------------\n");
	TestDirection();
	wprintf(L"\n");

	// 测试字符串
	wprintf(L"------------------ 测试字符串 ---------------------\n");
	TestString();
	wprintf(L"\n");

	// 测试SafeArray
	wprintf(L"------------------ 测试SafeArray ---------------------\n");
	TestSafeArray();
	wprintf(L"\n");

	// 测试Variant
	wprintf(L"------------------ 测试Variant ---------------------\n");
	TestVariant();
	wprintf(L"\n");

	// 测试class
	wprintf(L"------------------ 测试class ---------------------\n");
	TestClass();
	wprintf(L"\n");

	// 测试struct
	wprintf(L"------------------ 测试struct ---------------------\n");
	TestStruct();
	wprintf(L"\n");

	// 测试事件
	wprintf(L"------------------ 测试事件 ---------------------\n");
	TestEvent();
	wprintf(L"\n");

	// 测试可选参数
	wprintf(L"------------------ 测试可选参数 ---------------------\n");
	TestOptionalParam();
	wprintf(L"\n");
	
	// 测试集合
	wprintf(L"------------------ 测试集合 ---------------------\n");
	TestCollection();
	wprintf(L"\n");

	::CoUninitialize();

	wprintf(L"\n按任意键退出...\n");
	_getch();

	return 0;
}



