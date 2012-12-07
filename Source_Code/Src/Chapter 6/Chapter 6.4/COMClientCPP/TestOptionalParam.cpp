#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalOptionalParam.tlb" no_namespace

void TestOptionalParam()
{
	// 创建COM对象实例
	IMarshalOptionalPtr comObj(__uuidof(MarshalOptionalObj));
	if (comObj)
	{
        // 用于向方法传递可选参数的VARIANT值 
		VARIANT varOptional;
		varOptional.vt = VT_ERROR;
		varOptional.scode = DISP_E_PARAMNOTFOUND; 
		
		int result = comObj->AddVariantOptional(1, varOptional);
		wprintf(L"一个参数结果：%d\n", result);
		
		result = comObj->AddVariantOptional(1, 2);
		wprintf(L"两个参数结果：%d\n", result);

		comObj.Release();
	}
}