#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalDirection.tlb" no_namespace

void TestDirection()
{
	// 创建COM对象实例
	IMarshalDirectionPtr comObj(__uuidof(MarshalDirectionObj));
	if (comObj)
	{
		long intInArg = 10;
		long intOutArg = 0;

		comObj->IntegerDefault(intInArg, intOutArg);
		wprintf(L"方法: IntegerDefault  intInArg = %d intOutArg = %d\n", intInArg, intOutArg);

		intOutArg = 0;
		comObj->IntegerInOut(intInArg, intOutArg);
		wprintf(L"方法: IntegerInOut    intInArg = %d intOutArg = %d\n", intInArg, intOutArg);

		intOutArg = 0;
		comObj->IntegerRef(intInArg, &intOutArg);
		wprintf(L"方法: IntegerRef      intInArg = %d intOutArg = %d\n", intInArg, intOutArg); 

		intOutArg = 0;
		comObj->IntegerRefIn(intInArg, &intOutArg);
		wprintf(L"方法: IntegerRefIn    intInArg = %d, intOutArg = %d\n", intInArg, intOutArg);

		intOutArg = 0;
		comObj->IntegerOut(intInArg, &intOutArg);
		wprintf(L"方法: IntegerOut      intInArg = %d, intOutArg = %d\n", intInArg, intOutArg);


		BSTR strInArg = L"一二三";
		BSTR strOutArg = L"未赋值";

		comObj->StringDefault(strInArg, strOutArg);
		wprintf(L"方法: StringDefault   strInArg = %s, strOutArg = %s\n", strInArg, strOutArg);

		strOutArg = L"未赋值";
		comObj->StringInOut(strInArg, strOutArg);
		wprintf(L"方法: StringInOut     strInArg = %s, strOutArg = %s\n", strInArg, strOutArg);

		strOutArg = L"未赋值";
		comObj->StringRef(strInArg, &strOutArg);
		wprintf(L"方法: StringRef       strInArg = %s, strOutArg = %s\n", strInArg, strOutArg); 

		strOutArg = L"未赋值";
		comObj->StringRefIn(strInArg, &strOutArg);
		wprintf(L"方法: StringRefIn     strInArg = %s, strOutArg = %s\n", strInArg, strOutArg);

		strOutArg = L"未赋值";
		comObj->StringOut(strInArg, &strOutArg);
		wprintf(L"方法: StringOut       strInArg = %s, strOutArg = %s\n", strInArg, strOutArg);
		
		comObj.Release();
	}
}