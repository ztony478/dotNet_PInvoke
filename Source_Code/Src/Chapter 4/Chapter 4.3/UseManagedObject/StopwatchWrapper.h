#pragma once

#include <gcroot.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace ManagedUtility;

// 非托管包装类
public class CStopwatchWrapper
{
public:
	CStopwatchWrapper(){}

	CStopwatchWrapper(gcroot<AdvancedStopwatch^> obj)
	{
		m_watch = obj;
	}

	void Start()
	{
		m_watch->Start();
	}

	void Stop()
	{
		m_watch->Stop();
	}

	void Reset()
	{
		m_watch->Reset();
	}

	void Record()
	{
		m_watch->Record();
	}

	INT64* GetRecords(int &recordNumber)
	{
		List<INT64>^ records = m_watch->Records;
		recordNumber = records->Count;
		INT64* arr = new INT64[recordNumber];
		for(int i=0; i<recordNumber; i++)
		{
			arr[i] = records[i];
		}
		return arr;
	}

private:
	gcroot<AdvancedStopwatch^> m_watch;

};