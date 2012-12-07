#pragma once

using namespace System;

namespace MixedLib
{
	public ref class MixedManagedClass
	{
	public:
		MixedManagedClass(void) {}
		~MixedManagedClass(void) {}
		void PrintMessage(void)
		{
			Console::WriteLine("Managed class method called.");
		}

	};
}