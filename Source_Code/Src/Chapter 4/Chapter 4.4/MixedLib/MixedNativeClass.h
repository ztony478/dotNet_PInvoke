#pragma once

namespace MixedLib
{
	#pragma unmanaged
	class __declspec(dllexport) CMixedNativeClass
	{
	public:
		CMixedNativeClass(void) {}
		~CMixedNativeClass(void) {}
		void PrintMessage(void);
	};
	#pragma managed
}
