// CppInterop_MarshalArray.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <vcclr.h>

using namespace System;

#pragma unmanaged

void NativeChangeIntArray(int* intArray, int count)
{
	printf("(unmanaged) recieved int array:\n");
	for (int i=0; i<count; i++)
	{
		printf("element[%d] = %d\n", i, intArray[i]);
		intArray[i] += 10;
	}
}

#pragma managed

int main(array<System::String ^> ^args)
{
	array<int>^ intArray = gcnew array<int>(5);

	Console::WriteLine("(managed) int array created:");
	for (int i=0; i<intArray->Length; i++)
	{
		intArray[i] = i;
		Console::WriteLine("element[{0}] = {1}", i, intArray[i]);
	}

	pin_ptr<int> pArray = &intArray[0];
	NativeChangeIntArray(pArray, intArray->Length);

	Console::WriteLine("(managed) int array changed to:");
	for (int i=0; i<intArray->Length; i++)
	{
		Console::WriteLine("element[{0}] = {1}", i, intArray[i]);
	}

	Console::WriteLine("\r\n按任意键退出...");
	Console::Read();

	return 0;
}
