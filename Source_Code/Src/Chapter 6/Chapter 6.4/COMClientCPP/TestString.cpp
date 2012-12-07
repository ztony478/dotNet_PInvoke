#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalString.tlb" no_namespace

void TestString()
{
	// 创建COM对象实例
	IMarshalStringPtr comObj(__uuidof(MarshalStringObj));
	if (comObj)
	{
		BSTR strInArg = L"一二三";
		
		BSTR strRefArg = L"未赋值";
		comObj->StringRef(strInArg, &strRefArg);
		wprintf(L"方法: StringRef            strInArg = %s, strResult = %s\n", strInArg, strRefArg);

		BSTR strOutArg = L"未赋值";
		comObj->StringOut(strInArg, &strOutArg);
		wprintf(L"方法: StringOut            strInArg = %s, strResult = %s\n", strInArg, strOutArg);

		BSTR strReturn = comObj->StringReturn(strInArg);
		wprintf(L"方法: StringReturn         strInArg = %s, strResult = %s\n", strInArg, strReturn);

		// 注意分配的内存不能只做清空操作，否则在托管代码中StringBuilder的Capacity为0
		// Capacity的大小是由内存中的数据长度决定的。本例中，虽然分配100个双字节的空间，
		// 但在封送到托管代码中的Capacity为80
		wchar_t* pbuffer = new wchar_t[100];
		wmemset(pbuffer, 0, 100);
		wmemset(pbuffer, L'a', 80);
		comObj->StringStringBuilder(strInArg, pbuffer);
		wprintf(L"方法: StringStringBuilder  strInArg = %s, strResult = %s\n", strInArg, pbuffer);
		delete[] pbuffer;

		wchar_t* pResult = comObj->StringCStyle(L"一二三");
		wprintf(L"方法: StringCStyle         strInArg = %s, strResult = %s\n", strInArg, pResult);
		// 必须释放返回的内存空间
		CoTaskMemFree(pResult);

		comObj.Release();
	}
}