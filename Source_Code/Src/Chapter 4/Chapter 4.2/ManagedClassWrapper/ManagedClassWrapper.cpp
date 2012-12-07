// ManagedClassWrapper.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "ManagedClassWrapper.h"
#include "..\..\NativeLib\NativeLib.h"

using namespace System::Runtime::InteropServices;	// needed for Marshal

namespace CppInteropWrapper
{
	CMCppWrapper::CMCppWrapper()
		: m_pUnmanagedObj(NULL)
	{
		this->m_pUnmanagedObj = new CUnmanagedClass();
	}

	CMCppWrapper::~CMCppWrapper()
	{
		delete this->m_pUnmanagedObj;
		this->m_pUnmanagedObj = NULL;
	}

	void CMCppWrapper::PassInt(int intValue)
	{
		this->m_pUnmanagedObj->PassInt(intValue);
	}

	void CMCppWrapper::PassString(String^ strValue)
	{
		IntPtr pString = Marshal::StringToHGlobalAnsi(strValue);
		try
		{
			char* pchString = static_cast<char *>(pString.ToPointer());
			this->m_pUnmanagedObj->PassString(pchString);
		}
		finally
		{
			Marshal::FreeHGlobal(pString);
		}
	}

	String^ CMCppWrapper::ReturnString()
	{
		char* pchValue = this->m_pUnmanagedObj->ReturnString();
		String^ strValue = Marshal::PtrToStringAnsi(static_cast<IntPtr>(pchValue));
		delete[] pchValue;
		pchValue = NULL;
		return strValue;
	}
}
