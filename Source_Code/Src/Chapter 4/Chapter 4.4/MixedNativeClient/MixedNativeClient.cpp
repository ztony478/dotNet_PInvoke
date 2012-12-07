// MixedNativeClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <conio.h>
#include "..\MixedLib\MixedNativeClass.h"

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");

	MixedLib::CMixedNativeClass* nativeObj = new MixedLib::CMixedNativeClass();
	nativeObj->PrintMessage();
	
	wprintf(L"\n按任意键退出...\n");
	_getch();

	return 0;
}

