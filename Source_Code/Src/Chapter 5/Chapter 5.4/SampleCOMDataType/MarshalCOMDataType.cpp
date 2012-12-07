// MarshalCOMDataType.cpp : Implementation of CMarshalCOMDataType

#include "stdafx.h"
#include "MarshalCOMDataType.h"
#include "comutil.h"

// CMarshalCOMDataType


STDMETHODIMP CMarshalCOMDataType::MarshalChar(unsigned char inArg, unsigned char* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalCOMChar(CHAR inArg, CHAR* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalBSTR(BSTR inArg, BSTR* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalLPSTR(LPSTR inArg, LPSTR* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalDECIMAL(DECIMAL inArg, DECIMAL* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalCURRENCY(CURRENCY inArg, CURRENCY* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalBoolean(boolean inArg, boolean* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalVariantBool(VARIANT_BOOL inArg, VARIANT_BOOL* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalDATE(DATE inArg, DATE* outArg)
{
	*outArg = inArg;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalCOMVariant(VARIANT inArg, VARIANT* outArg, BSTR* typeDescription)
{
	*outArg = inArg;

	switch(inArg.vt)
	{
	case VT_EMPTY:
		*typeDescription = (CComBSTR)"VT_EMPTY - nothing";
		break;
	case VT_NULL:
		*typeDescription = (CComBSTR)"VT_NULL - SQL style Null";
		break;
	case VT_I2:
		*typeDescription = (CComBSTR)"VT_I2 - 2 byte signed int";
		break;
	case VT_I4:
		*typeDescription = (CComBSTR)"VT_I4 - 4 byte signed int";
		break;
	case VT_R4:
		*typeDescription = (CComBSTR)"VT_R4 - 4 byte real";
		break;
	case VT_R8:
		*typeDescription = (CComBSTR)"VT_R8 - 8 byte real";
		break;
	case VT_CY:
		*typeDescription = (CComBSTR)"VT_CY - currency";
		break;
	case VT_DATE:
		*typeDescription = (CComBSTR)"VT_DATE - date";
		break;
	case VT_BSTR:
		*typeDescription = (CComBSTR)"VT_BSTR - OLE Automation string";
		break;
	case VT_DISPATCH:
		*typeDescription = (CComBSTR)"VT_DISPATCH - IDispatch *";
		break;
	case VT_ERROR:
		*typeDescription = (CComBSTR)"VT_ERROR - SCODE";
		break;
	case VT_BOOL:
		*typeDescription = (CComBSTR)"VT_BOOL - True=-1, False=0";
		break;
	case VT_VARIANT:
		*typeDescription = (CComBSTR)"VT_VARIANT - VARIANT *";
		break;
	case VT_UNKNOWN:
		*typeDescription = (CComBSTR)"VT_UNKNOWN - IUnknown *";
		break;
	case VT_DECIMAL:
		*typeDescription = (CComBSTR)"VT_DECIMAL - 16 byte fixed point";
		break;
	case VT_I1:
		*typeDescription = (CComBSTR)"VT_I1 - signed char";
		break;
	case VT_UI1:
		*typeDescription = (CComBSTR)"VT_UI1 - unsigned char";
		break;
	case VT_UI2:
		*typeDescription = (CComBSTR)"VT_UI2 - unsigned short";
		break;
	case VT_UI4:
		*typeDescription = (CComBSTR)"VT_UI4 - unsigned long";
		break;
	case VT_I8:
		*typeDescription = (CComBSTR)"VT_I8 - signed 64-bit int";
		break;
	case VT_UI8:
		*typeDescription = (CComBSTR)"VT_UI8 - unsigned 64-bit int";
		break;
	case VT_INT:
		*typeDescription = (CComBSTR)"VT_INT - signed machine int";
		break;
	case VT_UINT:
		*typeDescription = (CComBSTR)"VT_UINT - unsigned machine int";
		break;
	case VT_VOID:
		*typeDescription = (CComBSTR)"VT_VOID - C style void";
		break;
	case VT_HRESULT:
		*typeDescription = (CComBSTR)"VT_HRESULT - Standard return type";
		break;
	case VT_PTR:
		*typeDescription = (CComBSTR)"VT_PTR - pointer type";
		break;
	case VT_SAFEARRAY:
		*typeDescription = (CComBSTR)"VT_SAFEARRAY - (use VT_ARRAY in VARIANT)";
		break;
	case VT_CARRAY:
		*typeDescription = (CComBSTR)"VT_CARRAY - C style array";
		break;
	case VT_USERDEFINED:
		*typeDescription = (CComBSTR)"VT_USERDEFINED - user defined type";
		break;
	case VT_LPSTR:
		*typeDescription = (CComBSTR)"VT_LPSTR - null terminated string";
		break;
	case VT_LPWSTR:
		*typeDescription = (CComBSTR)"VT_LPWSTR - wide null terminated string";
		break;
	case VT_RECORD:
		*typeDescription = (CComBSTR)"VT_RECORD -user defined type";
		break;
	case VT_INT_PTR:
		*typeDescription = (CComBSTR)"VT_INT_PTR - signed machine register size width";
		break;
	case VT_UINT_PTR:
		*typeDescription = (CComBSTR)"VT_UINT_PTR - unsigned machine register size width";
		break;
	case VT_FILETIME:
		*typeDescription = (CComBSTR)"VT_FILETIME - FILETIME";
		break;
	case VT_BLOB:
		*typeDescription = (CComBSTR)"VT_BLOB - Length prefixed bytes";
		break;
	case VT_STREAM:
		*typeDescription = (CComBSTR)"VT_STREAM - Name of the stream follows";
		break;
	case VT_STORAGE:
		*typeDescription = (CComBSTR)"VT_STORAGE - Name of the storage follows";
		break;
	case VT_STREAMED_OBJECT:
		*typeDescription = (CComBSTR)"VT_STREAMED_OBJECT - Stream contains an object";
		break;
	case VT_STORED_OBJECT:
		*typeDescription = (CComBSTR)"VT_STORED_OBJECT - Storage contains an object";
		break;
	case VT_BLOB_OBJECT:
		*typeDescription = (CComBSTR)"VT_BLOB_OBJECT - Blob contains an object";
		break;
	case VT_CF:
		*typeDescription = (CComBSTR)"VT_CF - Clipboard format";
		break;
	case VT_CLSID:
		*typeDescription = (CComBSTR)"VT_CLSID - A Class ID";
		break;
	case VT_VERSIONED_STREAM:
		*typeDescription = (CComBSTR)"VT_VERSIONED_STREAM - Stream with a GUID version";
		break;
	case VT_BSTR_BLOB:
		*typeDescription = (CComBSTR)"VT_BSTR_BLOB - Reserved for system use";
		break;
	case VT_VECTOR:
		*typeDescription = (CComBSTR)"VT_VECTOR - simple counted array";
		break;
	case VT_ARRAY:
		*typeDescription = (CComBSTR)"VT_ARRAY - SAFEARRAY*";
		break;
	case VT_BYREF:
		*typeDescription = (CComBSTR)"VT_BYREF - void* for local use";
		break;
	case VT_RESERVED:
		*typeDescription = (CComBSTR)"VT_RESERVED - Reserved";
		break;
	case VT_ILLEGAL:
		*typeDescription = (CComBSTR)"VT_ILLEGAL - Illegal";
		break;
	default:
		*typeDescription = (CComBSTR)"未知类型";
	}

	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::SortArray(SAFEARRAY* inArray, BSTR* mergedResult)
{
	ULONG i, j, min; 
	BSTR BSTRTemp;
	BSTR HUGEP *pBSTR;
	
	SafeArrayAccessData(inArray, (void HUGEP* FAR*)&pBSTR);

	// 第一步，连接个字符串并返回
	_bstr_t tempBuffer;
	for(i = 0; i < inArray->rgsabound[0].cElements; i++)
	{
		tempBuffer += _bstr_t(pBSTR[i]);
		tempBuffer += _bstr_t(L" ");
	}
	*mergedResult = tempBuffer;

	// 第二步，字符串排序
	ULONG cElements = inArray->rgsabound[0].cElements; 
	for (i = 0; i < cElements - 1; i++)
	{
		min = i;
		for (j = i+1; j < cElements; j++)
		{
			if (wcscmp(pBSTR[j], pBSTR[min]) < 0)
				min = j; 
		}

		// Swap array[min] and array[i].
		BSTRTemp = pBSTR[min];
		pBSTR[min] = pBSTR[i];
		pBSTR[i] = BSTRTemp;

	}

	SafeArrayUnaccessData(inArray);


	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalCStylelArray(int inArg[], long elementSize, int* sumOfElements)
{
	int result = 0;
	for(int i = 0; i < elementSize; i++)
	{
		result += inArg[i];
	}

	*sumOfElements = result;
	return S_OK;
}

STDMETHODIMP CMarshalCOMDataType::MarshalStructure(SampleStruct* inArg)
{
	// ID字段自增1
	inArg->ID++;

	// stringName字段添加后缀
	_bstr_t buffer;
	buffer.Attach(inArg->stringName);
	buffer += "_Changed";
	inArg->stringName = buffer.Detach();
	return S_OK;
}
