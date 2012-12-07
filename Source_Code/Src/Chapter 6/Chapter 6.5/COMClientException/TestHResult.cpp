#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "Exception2HRESULT.tlb" no_namespace

void TestHResult()
{
	// 创建COM对象实例
	IExceptions2HResultPtr comObj(__uuidof(Exceptions2HResultObj));
	if (comObj)
	{
		HRESULT hr;
		wprintf(L"1. 调用方法：ThrowExceptionForHR() - 参数errorCode = S_FALSE (1) ...\n");
		hr = comObj->ThrowExceptionForHR(1);
		wprintf(L"HRESULT返回值：0x%x\n", hr);
		wprintf(L"\n");

		wprintf(L"2. 调用方法：ReturnHResult() - 参数为(1) ...\n");
		hr = comObj->ReturnHResult(1);
		wprintf(L"HRESULT返回值：0x%x\n", hr);
		wprintf(L"\n");

		wprintf(L"3. 调用方法：ReturnHResult() - 参数为(-1) ...\n");
		hr = comObj->ReturnHResult(-1);
		wprintf(L"HRESULT返回值：0x%x\n", hr);
		wprintf(L"\n");

		comObj.Release();
	}
}