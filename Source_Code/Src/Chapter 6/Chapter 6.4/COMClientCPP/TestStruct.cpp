#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalStructure.tlb" no_namespace

void TestStruct()
{
	// 创建COM对象实例
	IMarshalStructPtr comObj(__uuidof(MarshalStructObj));
	if (comObj)
	{
		DataStruct obj = comObj->CreateInstance();
		wprintf(L"创建Struct对象：obj.IntegerValue = %d, obj.StringValue = %s\n", obj.IntegerValue, (wchar_t*)obj.StringValue);

		comObj->UpdateInstance(&obj);
		wprintf(L"修改Struct对象：obj.IntegerValue = %d, obj.StringValue = %s\n", obj.IntegerValue, (wchar_t*)obj.StringValue);

		comObj.Release();
	}
}