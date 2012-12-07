// MarshalCOMDataType.h : Declaration of the CMarshalCOMDataType

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMDataType.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMarshalCOMDataType

class ATL_NO_VTABLE CMarshalCOMDataType :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMarshalCOMDataType, &CLSID_MarshalCOMDataType>,
	public IDispatchImpl<IMarshalCOMDataType, &IID_IMarshalCOMDataType, &LIBID_SampleCOMDataTypeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMarshalCOMDataType()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MARSHALCOMDATATYPE)


BEGIN_COM_MAP(CMarshalCOMDataType)
	COM_INTERFACE_ENTRY(IMarshalCOMDataType)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(MarshalChar)(unsigned char inArg, unsigned char* outArg);
	STDMETHOD(MarshalCOMChar)(CHAR inArg, CHAR* outArg);
	STDMETHOD(MarshalBSTR)(BSTR inArg, BSTR* outArg);
	STDMETHOD(MarshalLPSTR)(LPSTR inArg, LPSTR* outArg);
	STDMETHOD(MarshalDECIMAL)(DECIMAL inArg, DECIMAL* outArg);
	STDMETHOD(MarshalCURRENCY)(CURRENCY inArg, CURRENCY* outArg);
	STDMETHOD(MarshalBoolean)(boolean inArg, boolean* outArg);
	STDMETHOD(MarshalVariantBool)(VARIANT_BOOL inArg, VARIANT_BOOL* outArg);
	STDMETHOD(MarshalDATE)(DATE inArg, DATE* outArg);
	STDMETHOD(MarshalCOMVariant)(VARIANT inArg, VARIANT* outArg, BSTR* typeDescription);
	STDMETHOD(SortArray)(SAFEARRAY* inArray, BSTR* mergedResult);
	STDMETHOD(MarshalCStylelArray)(int inArg[], long elementSize, int* sumOfElements);
	STDMETHOD(MarshalStructure)(SampleStruct* inArg);
};

OBJECT_ENTRY_AUTO(__uuidof(MarshalCOMDataType), CMarshalCOMDataType)
