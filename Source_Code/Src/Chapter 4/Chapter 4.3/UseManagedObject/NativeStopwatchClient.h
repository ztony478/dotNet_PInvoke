#pragma once

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "StopwatchWrapper.h"

#pragma unmanaged
public class CNativeStopwatchClient
{
public:
	CNativeStopwatchClient(){}

	void SetStopwatcher(CStopwatchWrapper obj)
	{
		m_wrapperObj = obj;
	}

	void GetUserInputRecord()
	{
		int inputChar;
		int actionCount = 0;
		printf("Stopwatch started, click any key to add a time record.\nClick Q to exist...\n");
		m_wrapperObj.Start();
		do
		{
			inputChar = _getch();
			m_wrapperObj.Record();
			actionCount++;
			printf("\rThe number of user input: %d", actionCount);
			inputChar = toupper(inputChar);

		}while(inputChar != 'Q');
		printf("\n");
		m_wrapperObj.Stop();
	}

	void PrintRecord()
	{
		int recordNum = 0;
		INT64* arr = m_wrapperObj.GetRecords(recordNum);
		for(int i=0; i<recordNum; i++)
		{
			printf("Record #%d: %d\n", i+1, arr[i]);
		}
		delete[] arr;
	}

private:
	CStopwatchWrapper m_wrapperObj;
};
#pragma managed