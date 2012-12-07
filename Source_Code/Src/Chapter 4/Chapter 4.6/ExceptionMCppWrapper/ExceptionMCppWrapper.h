#pragma once

using namespace System;

namespace CppInteropWrapper
{

	// 托管异常类，用于封装由非托管代码产生的异常信息
	public ref class WrapperException 
		: public ApplicationException
	{
	public:
		WrapperException(String^ message, int errorCode) 
			: ApplicationException(message)
		{
			m_ErrorCode = errorCode;
		};

		property int ErrorCode
		{
			int get() { return m_ErrorCode; };
		}
	private:
		int m_ErrorCode; 
	};

	// 定义非托管异常的枚举类型
	public enum class UnmanagedExceptionType
	{
		DivedeByZero,
		AccessInvalidMemory,
		ThrowErrorCode,
		ThrowCustomException,
		ThrowStdException
	};

	// 定义调用ThrowUnmanagedExceptions方法的包装类
	public ref class ThrowUnmanagedExceptionWrapperClass
	{
	public:
		static void CallUnmanagedException(UnmanagedExceptionType type);
	};

}