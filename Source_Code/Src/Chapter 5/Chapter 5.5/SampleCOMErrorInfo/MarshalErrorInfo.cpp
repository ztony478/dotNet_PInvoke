// MarshalErrorInfo.cpp : Implementation of CMarshalErrorInfo

#include "stdafx.h"
#include "MarshalErrorInfo.h"


// CMarshalErrorInfo

STDMETHODIMP CMarshalErrorInfo::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMarshalErrorInfo
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMarshalErrorInfo::GenerateCOMError(int type)
{
	HRESULT hr = S_OK;
	switch(type)
	{
	case 1:
		hr = E_POINTER;
		break;
	case 2:
		hr = E_NOTIMPL;
		break;
	case 3:
		hr = E_ACCESSDENIED;
		break;
	case 4:
		hr = E_OUTOFMEMORY;
		break;
	case 5:
		hr = CO_E_CLRNOTAVAILABLE;
		// 相比case 6返回给托管代码的异常，我们可以：
		// 1. 自定义错误信（messege）
		// 2. 给定明确的错误产生的位置。（source）
		GenerateErrorInfo(_uuidof(IMarshalErrorInfo),
			"CMarshalErrorInfo::GenerateCOMError()",
			"参数为5时产生的错误: CO_E_CLRNOTAVAILABLE");
		break;
	case 6:
		hr = CO_E_THREADPOOL_CONFIG;
		break;
	case 7:
		hr = 0x80040310L;
		GenerateErrorInfo(_uuidof(IMarshalErrorInfo),
			"CMarshalErrorInfo::GenerateCOMError()",
			"参数为7时产生的错误");
		break;
	default:
		break;
	}

	return hr;

}

void CMarshalErrorInfo::GenerateErrorInfo(REFGUID rGUID, 
										  _bstr_t source, _bstr_t message)
{
	ICreateErrorInfo* pCreateInfo		= NULL;
	IErrorInfo* pErrorInfo				= NULL;
	// 创建ICreateErrorInfo对象
	CreateErrorInfo(&pCreateInfo);

	// 设置属性值
	pCreateInfo->SetGUID(rGUID);
	pCreateInfo->SetSource(source);
	pCreateInfo->SetDescription(message);

	// 获得pCreateInfo的IErrorInfo接口引用
	pCreateInfo->QueryInterface(IID_IErrorInfo, (void**)&pErrorInfo);

	// 设置IErrorInfo
	SetErrorInfo(0,pErrorInfo);

	// 释放对象
	pErrorInfo->Release();
	pCreateInfo->Release();
}

