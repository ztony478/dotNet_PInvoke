// COMMTAObj.h : Declaration of the CCOMMTAObj

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMSimple.h"




// CCOMMTAObj

class ATL_NO_VTABLE CCOMMTAObj :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCOMMTAObj, &CLSID_COMMTAObj>,
	public IDispatchImpl<ICOMMTAObj, &IID_ICOMMTAObj, &LIBID_SampleCOMSimpleLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCOMMTAObj()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMMTAOBJ)


BEGIN_COM_MAP(CCOMMTAObj)
	COM_INTERFACE_ENTRY(ICOMMTAObj)
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

	STDMETHOD(AddIntegers)(int num0, int num1, int* result);
	STDMETHOD(ProcessString)(BSTR inString, BSTR* outString);
};

OBJECT_ENTRY_AUTO(__uuidof(COMMTAObj), CCOMMTAObj)
