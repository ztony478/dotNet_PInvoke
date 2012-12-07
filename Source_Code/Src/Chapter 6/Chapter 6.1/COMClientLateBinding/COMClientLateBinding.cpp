// COMClientLateBinding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "LateBinding.tlb" no_namespace

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");

	wprintf(L"------------------ 利用ClassInterface定义COM - 后期绑定 ------------------\n");

	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	// 根据progID查询CLSID
	CLSID clsid;
	CLSIDFromProgID(L"LateBinding.WeatherManager", &clsid);

	// 创建对象实例
	IDispatch* pIDispatch = NULL;
	CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,
		IID_IDispatch, (void**)&pIDispatch);

	// 1. 调用GetTemperatureCELSIUS方法
	// 获取方法的dispID
	DISPID dispId;
	OLECHAR* methodName = L"GetTemperatureCELSIUS";
	pIDispatch->GetIDsOfNames(IID_NULL, &methodName, 1,
		GetUserDefaultLCID(), &dispId);

	// 构造GetTemperatureCELSIUS方法的参数
	DISPPARAMS param;	
	param.cArgs = 0;
	param.rgvarg = NULL;
	param.cNamedArgs = 0;
	param.rgdispidNamedArgs = NULL;

	// 存放结果的变量
	VARIANT varCTemp;
	VariantInit(&varCTemp);
	
	// 调用方法
	HRESULT hr = pIDispatch->Invoke(dispId, IID_NULL,
		GetUserDefaultLCID(), DISPATCH_METHOD, &param,
		&varCTemp, NULL, NULL);

	wprintf(L"获取摄氏温度：%.2f\n", varCTemp.dblVal);

	// 2. 调用ConvertCelsius2Fahrenheit方法
	methodName = L"ConvertCelsius2Fahrenheit";
	pIDispatch->GetIDsOfNames(IID_NULL, &methodName, 1,
		GetUserDefaultLCID(), &dispId);

	// 构造ConvertCelsius2Fahrenheit方法的参数
	VARIANTARG cTemp[1];
	VariantInit(&cTemp[0]);
	cTemp[0].vt = VT_R8;
	cTemp[0].dblVal = varCTemp.dblVal;
	
	param.cArgs = 1;
	param.rgvarg = (VARIANTARG*)&cTemp;
	param.cNamedArgs = 0;
	param.rgdispidNamedArgs = NULL;

	// 存放结果的变量
	VARIANT varFTemp;
	VariantInit(&varFTemp);

	// 调用方法
	hr = pIDispatch->Invoke(dispId, IID_NULL,
		GetUserDefaultLCID(), DISPATCH_METHOD, &param,
		&varFTemp, NULL, NULL);

	wprintf(L"换算华氏温度：%.2f\n", varFTemp.dblVal);

	// 3. 调用OperationCount属性
	methodName = L"OperationCount";
	pIDispatch->GetIDsOfNames(IID_NULL, &methodName, 1,
		GetUserDefaultLCID(), &dispId);

	// 构造get_OperationCount方法的参数
	param.cArgs = 0;
	param.rgvarg = NULL;
	param.cNamedArgs = 0;
	param.rgdispidNamedArgs = NULL;

	// 存放结果的变量
	VARIANT varCount;
	VariantInit(&varCount);

	// 调用方法
	hr = pIDispatch->Invoke(dispId, IID_NULL,
		GetUserDefaultLCID(), DISPATCH_METHOD, &param,
		&varCount, NULL, NULL);

	wprintf(L"共执行函数调用%d次。\n", varCount.lVal);

	// 释放对象
	pIDispatch->Release();
	::CoUninitialize();

	wprintf(L"\n按任意键退出...\n");
	_getch();
	return 0;

}

