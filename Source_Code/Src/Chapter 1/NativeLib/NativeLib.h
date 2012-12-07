/******1.2小节所用****************/
extern "C" __declspec(dllexport) void __stdcall PrintMsg(const char* msg);

/******1.4小节所用****************/
extern "C" __declspec(dllexport) int __stdcall Multiply(int factorA, int factorB);

/******1.6小节所用****************/
extern "C" __declspec(dllexport) void __stdcall PrintMsgByFlag(void* data, int flag);

/******1.7小节所用****************/
extern "C" __declspec(dllexport) void ReverseAnsiString(char* rawString, char* reversedString);
extern "C" __declspec(dllexport) void ReverseUnicodeString(wchar_t* rawString, wchar_t* reversedString);

extern "C" __declspec(dllexport) void __cdecl ReverseStringA(char* rawString, char* reversedString);
extern "C" __declspec(dllexport) void __cdecl ReverseStringW(wchar_t* rawString, wchar_t* reversedString);

/******1.8小节所用****************/
extern "C" __declspec(dllexport) int __stdcall Divide(int numerator, int denominator);
extern "C" __declspec(dllexport) void UnmanagedExceptionFromCpp();
extern "C" __declspec(dllexport) void UnmanagedExcetionViaRaiseException();
extern "C" __declspec(dllexport) void UnmanagedExcetionViaRaiseExceptionNoRegular();

/******1.9小节所用****************/
extern "C" __declspec(dllexport) wchar_t* GetStringMalloc();
extern "C" __declspec(dllexport) wchar_t* GetStringNew();
extern "C" __declspec(dllexport) wchar_t* GetStringCoTaskMemAlloc();

extern "C" __declspec(dllexport) void FreeMallocMemory(void* pbuffer);
extern "C" __declspec(dllexport) void FreeNewMemory(void* pbuffer);
extern "C" __declspec(dllexport) void FreeCoTaskMemAllocMemory(void* pBuffer);

/******1.11小节所用****************/
extern "C" __declspec(dllexport) bool IsAsciiNonblittable(char asciiChar);
extern "C" __declspec(dllexport) int IsAsciiBlittable(__int8 asciiChar);
extern "C" __declspec(dllexport) void UnmanagedTest();
extern "C" __declspec(dllexport) bool IsWasciiNonblittable(wchar_t wasciiChar);
//extern "C" __declspec(dllexport) int IsWasciiBlittable(__int16 wasciiChar);