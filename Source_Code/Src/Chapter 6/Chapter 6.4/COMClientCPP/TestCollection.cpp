#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalCollection.tlb" no_namespace named_guids

void TestCollection()
{
	// 创建COM对象实例
	IMarshalCollectionPtr comObj(__uuidof(MarshalCollectionObj));
	if (comObj)
	{
		// 创建第一个数据
		IDemoItemPtr value1(__uuidof(DemoItemObj));
		value1->IntValue = 1;
		value1->StringValue = L"黄际洲";

		VARIANT* var1 = new VARIANT();
		// 由于这里传递到托管代码中的对象是COM接口对象
		// 因此要保存为VT_UNKNOWN或者VT_DISPATCH
		// 本例中将使用VT_DISPATCH，并采用对应的pdispVal字段存放数据
		// 如果使用VT_UNKNOWN，则应采用其对应的punkVal字段存放数据
		var1->vt = VT_DISPATCH;
		var1->pdispVal = value1;

		// 创建第二个数据
		IDemoItemPtr value2(__uuidof(DemoItemObj));
		value2->IntValue = 2;
		value2->StringValue = L"崔晓源";

		VARIANT* var2 = new VARIANT();
		var2->vt = VT_DISPATCH;
		var2->pdispVal = value2;

		// 加入集合
		comObj->Add(_variant_t(var1));
		comObj->Add(_variant_t(var2));
		
		// 枚举集合中的元素
		IEnumVARIANTPtr pEnum = comObj->GetEnumerator();
		VARIANT item;
		// 每次取回1个结果
		ULONG expectedItemCount = 1;
		ULONG returnedItemCount;
		while(S_OK == pEnum->Next(expectedItemCount, &item, &returnedItemCount))
		{
			if(expectedItemCount == returnedItemCount)	
			{
				IDemoItemPtr pItem;
				HRESULT hr = item.pdispVal->QueryInterface(IID_IDemoItem, (LPVOID*)&pItem);
				wprintf(L"作者%d 姓名：%s\n", pItem->IntValue, (wchar_t*)pItem->StringValue);
			}
		}

		// 释放对象
		value1.Release();
		delete var1;

		value2.Release();
		delete var2;

		comObj.Release();
	}
}