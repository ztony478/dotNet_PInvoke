#pragma once

using namespace System::Runtime::InteropServices;

// 定义托管委托
[UnmanagedFunctionPointer(CallingConvention::Cdecl)]
public delegate int CallbackDelegate(int num0, int num1);

public ref class CallBack_Delegate
{
public:
	void TestCallback(void);
private:
	// 对回调的实现
	int CallBack_Add(int num0, int num1);
};
