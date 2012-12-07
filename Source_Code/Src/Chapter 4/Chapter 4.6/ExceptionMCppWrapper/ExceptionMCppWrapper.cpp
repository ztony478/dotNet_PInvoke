// ExceptionMCppWrapper.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "ExceptionMCppWrapper.h"
#include "..\..\NativeLib\NativeLib.h"
#include <exception>

//ThrowUnmanagedExceptions

namespace CppInteropWrapper
{
	void ThrowUnmanagedExceptionWrapperClass::CallUnmanagedException(UnmanagedExceptionType type)
	{
		try
		{
			ThrowUnmanagedExceptions((int)type);
		}
		catch(int e)
		{
			throw gcnew WrapperException(e.ToString(), e);
		}
		catch(CUnmanagedException& e)
		{
			throw gcnew WrapperException(gcnew String(e.GetErrorMessage()), e.GetErrorCode());
		}
		catch(std::exception& e)
		{
			throw gcnew WrapperException(gcnew String(e.what()), 0);
		}
	}
}