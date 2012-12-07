// MarshalCOMEvent.h : Declaration of the CMarshalCOMEvent

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMEvent.h"
#include "_IMarshalCOMEventEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMarshalCOMEvent

class ATL_NO_VTABLE CMarshalCOMEvent :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMarshalCOMEvent, &CLSID_MarshalCOMEvent>,
	public IConnectionPointContainerImpl<CMarshalCOMEvent>,
	public CProxy_IMarshalCOMEventEvents<CMarshalCOMEvent>,
	public IDispatchImpl<IMarshalCOMEvent, &IID_IMarshalCOMEvent, &LIBID_SampleCOMEventLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMarshalCOMEvent()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MARSHALCOMEVENT)


BEGIN_COM_MAP(CMarshalCOMEvent)
	COM_INTERFACE_ENTRY(IMarshalCOMEvent)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CMarshalCOMEvent)
	CONNECTION_POINT_ENTRY(__uuidof(_IMarshalCOMEventEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(ChangeStringValue)(BSTR originalString);
};

OBJECT_ENTRY_AUTO(__uuidof(MarshalCOMEvent), CMarshalCOMEvent)
