#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalStructure.tlb" no_namespace

void TestClass()
{
	// 创建COM对象实例
	IMarshalClassPtr comObj(__uuidof(MarshalClassObj));
	if (comObj)
	{
		IDataClassPtr pObj = comObj->CreateInstance();
		wprintf(L"创建Class对象：obj->IntegerValue = %d, obj->StringValue = %s\n", pObj->IntegerValue, (wchar_t*)pObj->StringValue);

		comObj->UpdateInstance(pObj);
		wprintf(L"修改Class对象：obj->IntegerValue = %d, obj->StringValue = %s\n", pObj->IntegerValue, (wchar_t*)pObj->StringValue);

		comObj.Release();
	}
}