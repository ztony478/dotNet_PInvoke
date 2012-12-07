#include "StdAfx.h"
#include "CallBack_Delegate.h"
#include "NativeCallback.h"

using namespace System;
using namespace System::Runtime::InteropServices;

void CallBack_Delegate::TestCallback(void)
{
	// 用成员函数CallBack_Add实例化委托对象
	CallbackDelegate^ cbDelegate = gcnew CallbackDelegate(this, 
		&CallBack_Delegate::CallBack_Add);
	// GCHandle可以防止委托对象被回收
	GCHandle gchDelegate = GCHandle::Alloc(cbDelegate);
	// 封送委托对象
	IntPtr pFunc 
		= Marshal::GetFunctionPointerForDelegate(cbDelegate);
	// 将指针转化为PCallbackFunc型
	PCallbackFunc pcbFunc 
		= static_cast<PCallbackFunc>(pFunc.ToPointer());
	// 调用实例方法
	CCallbackClient client;
	client.UseCallback(pcbFunc, 1, 2);
	// 释放GCHandle对象，允许垃圾回收器释放委托对象
	gchDelegate.Free();
}

// 该回调函数实现两个整数的加和计算
int CallBack_Delegate::CallBack_Add(int num0, int num1)
{
	return num0 + num1;
}
