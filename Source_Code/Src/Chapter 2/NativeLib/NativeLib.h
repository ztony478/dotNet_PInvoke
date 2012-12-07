// 下面的#ifdef代码段使用宏定义的方式，简化了导出动态链接库函数的声明。该动态链接库中所有
// 的文件都会按照编译器选项中指定的NATIVELIB_EXPORTS符号进行编译。
#ifdef NATIVELIB_EXPORTS
#define NATIVELIB_API __declspec(dllexport)
#else
#define NATIVELIB_API __declspec(dllimport)
#endif

#include "NameEntityFinder.h"

// 字符串示例
extern "C"
{
	NATIVELIB_API void __cdecl TestStringArgumentsFixLength(const wchar_t* inString, wchar_t* outString, int bufferSize);
	NATIVELIB_API void __cdecl TestStringArgumentOut(int id, wchar_t** ppString);
	NATIVELIB_API void __cdecl TestStringMarshalArguments(const char* inAnsiString, const wchar_t* inUnicodeString, wchar_t* outUnicodeString, int outBufferSize);
	NATIVELIB_API wchar_t* __cdecl TestStringAsResult(int id);
	NATIVELIB_API BSTR __cdecl TestBSTRString(BSTR* ppString);
}

// 结构体示例
typedef struct _SIMPLESTRUCT
{
	int    intValue;
	short  shortValue;
	float  floatValue;
	double doubleValue;
} SIMPLESTRUCT, *PSIMPLESTRUCT;

typedef struct _MSEMPLOYEE
{
	UINT  employeeID;
	short employedYear;
	char* displayName; 
	char* alias; 
} MSEMPLOYEE, *PMSEMPLOYEE;

typedef struct _MSEMPLOYEE2
{
	UINT employeeID;
	short employedYear;
	char displayName[255]; 
	char alias[255]; 
} MSEMPLOYEE2, *PMSEMPLOYEE2;

typedef struct _MSEMPLOYEE_EX
{
	UINT     employeeID;
	wchar_t* displayName; 
	char*    alias; 
	bool     isInRedmond;
	short    employedYear;
	BOOL     isFamale;
	
} MSEMPLOYEE_EX, *PMSEMPLOYEE_EX;

#pragma pack(1)
typedef struct _MSEMPLOYEE_EX2
{
    UINT      EmployeeID;       //4 bytes
    USHORT    EmployedYear;     //2 bytes
    BYTE      CurrentLevel;     //1 bytes
    wchar_t*  Alias;            //4 bytes
    wchar_t*  DisplayName;      //4 bytes
    wchar_t*  OfficeAddress;    //4 bytes
    wchar_t*  OfficePhone;      //4 bytes
    wchar_t*  Title;            //4 bytes
	USHORT    RegionId;         //4 bytes
    int       ZipCode;          //4 bytes
    double    CurrentSalary;    //8 bytes
} MSEMPLOYEE_EX2, *PMSEMPLOYEE_EX2;
#pragma pack() 

typedef struct _PERSONNAME
{
	char* first;
	char* last;
	char* displayName;
} PERSONNAME, *PPERSONNAME;

typedef struct _PERSON
{
	PPERSONNAME pName;
	int age; 
} PERSON, *PPERSON;

typedef struct _PERSON2
{
	PERSONNAME name;
	int age; 
} PERSON2, *PPERSON2;

typedef union _SIMPLEUNION
{
    int i;
    double d;
} SIMPLEUNION, *PSIMPLEUNION;

typedef union _SIMPLEUNION2
{
    int i;
    char str[128];
} SIMPLEUNION2, *PSIMPLEUNION2;

extern "C"
{
	NATIVELIB_API void __cdecl TestStructArgumentByVal(SIMPLESTRUCT simpleStruct);
	NATIVELIB_API void __cdecl TestStructArgumentByRef(PSIMPLESTRUCT ppStruct);
	NATIVELIB_API PSIMPLESTRUCT __cdecl TestReturnStruct(void);
	NATIVELIB_API PSIMPLESTRUCT __cdecl TestReturnNewStruct(void);
	NATIVELIB_API void __cdecl FreeStruct(PSIMPLESTRUCT pStruct);
	NATIVELIB_API void __cdecl TestReturnStructFromArg(PSIMPLESTRUCT* pStruct);
	NATIVELIB_API void __cdecl GetEmployeeInfo(PMSEMPLOYEE pEmployee);
	NATIVELIB_API void __cdecl GetEmployeeInfo2(PMSEMPLOYEE2 pEmployee);
	NATIVELIB_API void __cdecl GetEmployeeInfoEx(PMSEMPLOYEE_EX pEmployee);
	NATIVELIB_API void __cdecl GetEmployeeInfoEx2(PMSEMPLOYEE_EX2 pEmployee);
	NATIVELIB_API void __stdcall PrintEmployeeInfoEx(MSEMPLOYEE_EX pEmployee);
	NATIVELIB_API void __cdecl TestUnion(SIMPLEUNION u, int type);
	NATIVELIB_API void __cdecl TestUnion2(SIMPLEUNION2 u, int type);
	NATIVELIB_API void __cdecl TestStructInStructByVal(PPERSON2 pPerson);
	NATIVELIB_API void __cdecl TestStructInStructByRef(PPERSON pPerson);
}

// 类示例
extern "C"
{
	NATIVELIB_API void __cdecl TestPointer2Pointer(PMSEMPLOYEE* ppStruct);
}

// 数组示例
extern "C"
{
	NATIVELIB_API UINT __cdecl TestArrayOfChar(char charArray[], int arraySize);
	NATIVELIB_API int __cdecl TestArrayOfInt(int intArray[], int arraySize);
	NATIVELIB_API void __cdecl TestArrayOfString(char* ppStrArray[], int size);
	NATIVELIB_API int __cdecl TestRefArrayOfString(void** strArray, int* size);
}

// 综合示例
DECLARE_HANDLE(NAMEFINDERHANDLE);

extern "C"
{
	// 创建对象，并返回一个句柄
	NATIVELIB_API NAMEFINDERHANDLE CreateNameFinderInstance(__in NameEntityType type);
	// 初始化对象，比如一些模型和运行时依赖的数据
	NATIVELIB_API bool Initialize(__in NAMEFINDERHANDLE hHandle, __in_z const wchar_t* resourcePath);
	// 根据给定的一段文字，返回其中包含的各种名字
	NATIVELIB_API bool FindNames(
		__in NAMEFINDERHANDLE hHandle,
		__in_z const wchar_t* text, 
		__out PNAMEENTITY* nameArray,
		__out UINT* arraySize);

	// 释放对象资源
	NATIVELIB_API void UnInitialize(__in NAMEFINDERHANDLE hHandle);
	// 销毁对象
	NATIVELIB_API void DestroyInstance(__in NAMEFINDERHANDLE hHandle);
}

void ShowNativeStructSize(size_t size);
void ReverseAnsiStringInPlace(char* rawString);
