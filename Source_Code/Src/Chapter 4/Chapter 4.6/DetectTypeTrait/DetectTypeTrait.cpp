// DetectTypeTrait.cpp : main project file.

#include "stdafx.h"
#include "..\..\Chapter 4.4\MixedLib\MixedNativeClass.h"
#include "..\..\Chapter 4.4\MixedLib\MixedManagedClass.h"

using namespace System;

void DetectTypeTraits()
{
	bool result = __is_class(MixedLib::CMixedNativeClass);
	Console::WriteLine("CMixedNativeClass is native class? {0}", result);
	result = __is_class(MixedLib::MixedManagedClass);
	Console::WriteLine("MixedManagedClass is native class? {0}", result);
	result = __is_ref_class(MixedLib::CMixedNativeClass);
	Console::WriteLine("CMixedNativeClass is managed class? {0}", result);
	result = __is_ref_class(MixedLib::MixedManagedClass);
	Console::WriteLine("MixedManagedClass is managed class? {0}", result);
}

int main(array<System::String ^> ^args)
{
	DetectTypeTraits();

	Console::WriteLine("\r\n按任意键退出...");
	Console::Read();

	return 0;
}
