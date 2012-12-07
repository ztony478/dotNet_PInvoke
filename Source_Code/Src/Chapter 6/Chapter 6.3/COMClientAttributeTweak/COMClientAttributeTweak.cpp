// COMClientAttributeTweak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "AttributeTweakCOM.tlb" no_namespace

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");

	wprintf(L"------------------ 利用属性控制生成的类型库元数据 ------------------\n");

	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	ITweakCOMPtr comObj(__uuidof(TweakCOMObj));

	if(comObj)
	{
		wprintf(L"调用ExposedMethod方法\n");
		comObj->ExposedMethod();

		wprintf(L"访问DemoProperty属性的值\n");
		int result = comObj->DemoProperty;

		// 对属性的赋值语句会导致编译器错误
		// 因为该属性的put方法，被设置为ComVisible(false)
		//comObj->DemoProperty = 0;

		comObj.Release();
	}

	::CoUninitialize();

	wprintf(L"\n按任意键退出...\n");
	_getch();

	return 0;
}

