// UseManagedObject.cpp : main project file.

#include "stdafx.h"
#include <locale.h>
#include <conio.h>
#include "NativeStopwatchClient.h"

int main(array<System::String ^> ^args)
{
	_wsetlocale(LC_ALL, L"chs");
	
	// 创建托管类实例
	AdvancedStopwatch^ watch = gcnew AdvancedStopwatch();
	// 创建Wrapper类示例
	CStopwatchWrapper wrapper(watch);

	// 创建非托管类实例
	CNativeStopwatchClient program;
	program.SetStopwatcher(wrapper);
	program.GetUserInputRecord();
	program.PrintRecord();

	wprintf(L"\n按任意键退出...\n");
	_getch();

	return 0;
}
