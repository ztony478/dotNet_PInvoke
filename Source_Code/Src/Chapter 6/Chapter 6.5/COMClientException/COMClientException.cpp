// COMClientException.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#include <locale.h>
#import "mscorlib.tlb"

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");

	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	// 测试异常
	wprintf(L"------------------ 测试异常 ---------------------\n");
	TestException();
	wprintf(L"\n");

	// 测试返回HRESULT
	wprintf(L"------------------ 测试返回HRESULT ---------------------\n");
	TestHResult();
	wprintf(L"\n");
	
	::CoUninitialize();

	wprintf(L"\n按任意键退出...\n");
	_getch();

	return 0;
}

