#pragma once
#include <stdio.h>

#pragma unmanaged

// 非托管回调函数定义
typedef int (__cdecl *PCallbackFunc)(int num0, int num1);

// 使用回调的函数的类
class CCallbackClient
{
public:
	void UseCallback(PCallbackFunc pFunc, int num0, int num1)
	{
		if (pFunc)
		{
			int result = (*pFunc)(num0, num1);
			printf("The calculate result on two numbers (%d, %d): %d\n", num0, num1, result);
		}
	}
};

#pragma managed