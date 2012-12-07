#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalCommonType.tlb" no_namespace

void TestCommonTypes()
{
	// 创建COM对象实例
	IMarshalCommonTypePtr comObj(__uuidof(MarshalCommonTypeObj));
	if (comObj)
	{
		// 封送整数
		//wprintf(L"测试");
		wprintf(L"输入参数在COM中的类型：long，");
		comObj->MarshalInteger(24);
		// 封送字符
		wprintf(L"输入参数在COM中的类型：unsign short，");
		comObj->MarshalChar('C');
		// 封送字符串
		wprintf(L"输入参数在COM中的类型：BSTR，");
		comObj->MarshalString("字符串");
		// 封送DATE时间
		wprintf(L"输入参数在COM中的类型：DATE，");
		comObj->MarshalDate((DATE)39668.833333333336);
		// 封送DECIMAL
		wprintf(L"输入参数在COM中的类型：DECIMAL，");
		DECIMAL dec;
		double d = 2008.88;
		// 构造DECIMAL
		VarDecFromR8(d, &dec);
		comObj->MarshalDecimal(dec);
		// 封送CURRENCY
		wprintf(L"输入参数在COM中的类型：CURRENCY，");
		CURRENCY cur;
		// 构造CURRENCY
		VarCyFromR8(d, &cur);
		comObj->MarshalCurrecny(cur);

		comObj.Release();
	}
}