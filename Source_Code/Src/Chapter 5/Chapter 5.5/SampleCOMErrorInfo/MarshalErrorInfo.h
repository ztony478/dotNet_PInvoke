// MarshalErrorInfo.h : Declaration of the CMarshalErrorInfo

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMErrorInfo.h"
#include "comutil.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMarshalErrorInfo

class ATL_NO_VTABLE CMarshalErrorInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMarshalErrorInfo, &CLSID_MarshalErrorInfo>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMarshalErrorInfo, &IID_IMarshalErrorInfo, &LIBID_SampleCOMErrorInfoLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMarshalErrorInfo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MARSHALERRORINFO)


BEGIN_COM_MAP(CMarshalErrorInfo)
	COM_INTERFACE_ENTRY(IMarshalErrorInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(GenerateCOMError)(int type);

private:
	void GenerateErrorInfo(REFGUID rGUID, _bstr_t source, _bstr_t message);
};

OBJECT_ENTRY_AUTO(__uuidof(MarshalErrorInfo), CMarshalErrorInfo)
