// COMClientEarlyBinding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "EarlyBinding.tlb" no_namespace

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");

	wprintf(L"------------------ 利用ClassInterface定义COM - 早邦定 ------------------\n");

	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	_WeatherManagerPtr comObj(__uuidof(WeatherManager));

	if(comObj)
	{
		double cTemp = comObj->GetTemperatureCELSIUS();
		wprintf(L"获取摄氏温度：%.2f\n", cTemp);

		double fTemp = comObj->ConvertCelsius2Fahrenheit(cTemp);
		wprintf(L"换算华氏温度：%.2f\n", fTemp);

		int count = comObj->OperationCount;
		wprintf(L"共执行函数调用%d次。\n", count);

		comObj.Release();
	}

	::CoUninitialize();

	wprintf(L"\n按任意键退出...\n");
	_getch();

	return 0;
}

