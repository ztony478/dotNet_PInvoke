// CppInterop_MarshalStructure.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>

using namespace System;

#pragma unmanaged
struct NativeIntArray
{
	int elemCount;
	int* intArray;
	int* evenNumberCount;
};

void CalculateEvenCount(NativeIntArray* pArray)
{
	printf("[unmanaged] element count = %d\n", pArray->elemCount);
	int count = 0;
	for(int i = 0; i < pArray->elemCount; i++)
	{
		printf("element[%d] = %d\n", i, pArray->intArray[i]);
		if(pArray->intArray[i] % 2 == 0)
		{
			count++;
		}
	}
	*(pArray->evenNumberCount) = count;
}
#pragma managed

int main(array<System::String ^> ^args)
{
	NativeIntArray* pArray = new NativeIntArray();
	pArray->elemCount = 6;
	pArray->intArray = new int[pArray->elemCount];
	pArray->evenNumberCount = new int;
	*(pArray->evenNumberCount) = 0;

	Console::WriteLine("[managed] element count = {0}", pArray->elemCount);
	Random^ r = gcnew Random(DateTime::Now.Second);
	for(int i=0; i<pArray->elemCount; i++)
	{
		pArray->intArray[i] = r->Next(1, 100);
		Console::WriteLine("element[{0}] = {1}", i, pArray->intArray[i]);
	}

	CalculateEvenCount(pArray);
	Console::WriteLine("There are {0} even number(s) in array.", *(pArray->evenNumberCount));

	// 释放
	delete[] pArray->intArray;
	delete pArray->evenNumberCount;
	delete pArray;

	Console::WriteLine("\r\n按任意键退出...");
	Console::Read();
	return 0;
}
