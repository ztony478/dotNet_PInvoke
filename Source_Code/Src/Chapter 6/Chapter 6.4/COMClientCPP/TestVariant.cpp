#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalVariant.tlb" no_namespace named_guids

void TestVariant()
{
	// 创建COM对象实例
	IMarshalVariantPtr comObj(__uuidof(MarshalVariantObj));
	if (comObj)
	{
		VARIANT* varOutArg = new VARIANT();
		
		VARIANT varInt;
		varInt.vt = VT_I4;
		varInt.lVal = 10;
		_bstr_t typeName = comObj->MarshalVariant(varInt, varOutArg);
		wprintf(L"Variant类型：VT_I4, 托管类型：%s\n", (wchar_t*)typeName);

		VARIANT varShort;
		varShort.vt = VT_I2;
		varShort.lVal = 10;
		typeName = comObj->MarshalVariant(varShort, varOutArg);
		wprintf(L"Variant类型：VT_I2, 托管类型：%s\n", (wchar_t*)typeName);

		VARIANT varSingle;
		varSingle.vt = VT_R4;
		varSingle.fltVal = 10.0f;
		typeName = comObj->MarshalVariant(varSingle, varOutArg);
		wprintf(L"Variant类型：VT_R4, 托管类型：%s\n", (wchar_t*)typeName);

		VARIANT varDouble;
		varDouble.vt = VT_R8;
		varDouble.dblVal = 10.0f;
		typeName = comObj->MarshalVariant(varDouble, varOutArg);
		wprintf(L"Variant类型：VT_R4, 托管类型：%s\n", (wchar_t*)typeName);

		VARIANT varDate;
		varDate.vt = VT_DATE;
		varDate.date = (DATE)39668.833333333336;
		typeName = comObj->MarshalVariant(varDate, varOutArg);
		wprintf(L"Variant类型：VT_DATE, 托管类型：%s\n", (wchar_t*)typeName);

		// 构造DECIMAL
		VARIANT varDecimal;
		varDecimal.vt = VT_DECIMAL;
		DECIMAL dec;
		VarDecFromI4(2008, &dec);
		dec.wReserved = VT_DECIMAL;
		varDecimal.decVal = dec;
		typeName = comObj->MarshalVariant(varDecimal, varOutArg);
		wprintf(L"Variant类型：VT_DECIMAL, 托管类型：%s\n", (wchar_t*)typeName);

		VARIANT varString;
		varString.vt = VT_BSTR;
		varString.bstrVal = L"abc";
		typeName = comObj->MarshalVariant(varString, varOutArg);
		wprintf(L"Variant类型：VT_BSTR, 托管类型：%s\n", (wchar_t*)typeName);
		
		// .NET对特殊Variant类型的支持
		// 1. CurrencyWrapper
		// 构造CURRENCY
		VARIANT varCurrency;
		varCurrency.vt = VT_CY;
		CY cy;
		VarCyFromI4(2008, &cy);
		varCurrency.cyVal = cy;
		typeName = comObj->MarshalVariantCurrency(varDecimal, varOutArg);
		wprintf(L"Variant类型：VT_CY, 托管类型：%s, 传出参数类型：%d(VT_DECIMAL)\n", (wchar_t*)typeName, varOutArg->vt);

		// 使用CurrencyWrapper
		typeName = comObj->MarshalVariantCurrencyWrapper(varDecimal, varOutArg);
		wprintf(L"Variant类型：VT_CY, 托管类型：%s, 传出参数类型(CurrencyWrapper)：%d(VT_CY)\n", (wchar_t*)typeName, varOutArg->vt);

		// 2. BSTRWrapper
		_variant_t ret = comObj->MarshalVariantStringNull();
		wprintf(L"返回Null字符串，vt类型为：%d(VT_EMPTY)\n", ret.vt);

		// 使用BSTRWrapper
		ret = comObj->MarshalVariantStringNullWrapper();
		wprintf(L"返回Null字符串(BSTRWrapper)，vt类型为：%d(VT_BSTR)\n", ret.vt);

		ret = comObj->MarshalVariantStringNonNullWrapper();
		wprintf(L"返回普通字符串(BSTRWrapper)，vt类型为：%d(VT_BSTR)\n", ret.vt);

		// 3. 使用VARIANT封送类
		IDemoItemExPtr inValue(__uuidof(DemoItemExObj));
		inValue->IntValue = 1;
		inValue->StringValue = L"黄际洲";

		VARIANT* inArg = new VARIANT();
		// 由于这里传递到托管代码中的对象是COM接口对象
		// 因此要保存为VT_UNKNOWN或者VT_DISPATCH
		// 本例中将使用VT_DISPATCH，并采用对应的pdispVal字段存放数据
		// 如果使用VT_UNKNOWN，则应采用其对应的punkVal字段存放数据
		inArg->vt = VT_UNKNOWN;
		inArg->punkVal = inValue;

		wprintf(L"作者%d 姓名：%s\n", inValue->IntValue, (wchar_t*)inValue->StringValue);

		VARIANT *outArg = new VARIANT();
		outArg->vt = VT_UNKNOWN;
		outArg->punkVal = NULL;

		comObj->MarshalVariantClass(inArg, outArg);
		
		// 使用QueryInterface查询接口找回的VARIANT中的对象
		IDemoItemExPtr outPtr;
		HRESULT hr = outArg->punkVal->QueryInterface(IID_IDemoItemEx, (LPVOID*)&outPtr);
		if(SUCCEEDED(hr))
		{
			wprintf(L"作者%d 姓名：%s\n", outPtr->IntValue, (wchar_t*)outPtr->StringValue);
		}

		delete inArg;
		delete outArg;

		delete varOutArg;

		comObj.Release();
	}
}