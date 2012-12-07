#pragma once

// 创建_com_ptr_t智能指针
#import "SampleCOMSimple.tlb" no_namespace

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MCppCOMWrapperLib
{
	// 定义托管C++包装类
	public ref class MCppCOMWrapper
	{
	public:
		String^ ProcessString(String^ managedString)
		{
			String^ result	= String::Empty;
			// 获得一个对COM对象的引用
			ICOMMTAObjPtr comObj(__uuidof(COMMTAObj));
			if (!comObj)
			{
				return L"创建COM对象失败";
			}

			// 将System.String对象封送成BSTR
			IntPtr pBSTR = Marshal::StringToBSTR(managedString);
			BSTR inBSTR = static_cast<BSTR>(pBSTR.ToPointer());
			
			// 调用COM对象方法
			_bstr_t pResultBSTR = comObj->ProcessString(inBSTR);
			// 释放封送到非托管内存的BSTR字符串
			Marshal::FreeBSTR(pBSTR);
			// 为返回结果生成System.String实例，并返回
			result = gcnew System::String((wchar_t*)pResultBSTR);
			return result;
		}
	};
}
