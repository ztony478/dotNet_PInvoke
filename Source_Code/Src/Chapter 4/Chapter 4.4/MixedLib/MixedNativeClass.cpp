#include "StdAfx.h"
#include "MixedNativeClass.h"
#include <stdio.h>

namespace MixedLib
{
	#pragma unmanaged
	void CMixedNativeClass::PrintMessage(void)
	{
		printf("Native class method called.\n");
	}
	#pragma managed
}
