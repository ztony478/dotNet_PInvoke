// MarshalCOMHRESULT.h : Declaration of the CMarshalCOMHRESULT

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMErrorResult.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMarshalCOMHRESULT

class ATL_NO_VTABLE CMarshalCOMHRESULT :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMarshalCOMHRESULT, &CLSID_MarshalCOMHRESULT>,
	public IDispatchImpl<IMarshalCOMHRESULT, &IID_IMarshalCOMHRESULT, &LIBID_SampleCOMErrorResultLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMarshalCOMHRESULT()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MARSHALCOMHRESULT)


BEGIN_COM_MAP(CMarshalCOMHRESULT)
	COM_INTERFACE_ENTRY(IMarshalCOMHRESULT)
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

	STDMETHOD(GenerateHRESULTs)(int type);
	STDMETHOD(ReturnHRESULTs)(int type, HRESULT* hResult);
};

OBJECT_ENTRY_AUTO(__uuidof(MarshalCOMHRESULT), CMarshalCOMHRESULT)
