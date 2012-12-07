// SimpleCOMCalculator.h : Declaration of the CSimpleCOMCalculator

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMSimple.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CSimpleCOMCalculator

class ATL_NO_VTABLE CSimpleCOMCalculator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleCOMCalculator, &CLSID_SimpleCOMCalculator>,
	public IDispatchImpl<ISimpleCOMCalculator, &IID_ISimpleCOMCalculator, &LIBID_SampleCOMSimpleLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSimpleCOMCalculator()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SIMPLECOMCALCULATOR)


BEGIN_COM_MAP(CSimpleCOMCalculator)
	COM_INTERFACE_ENTRY(ISimpleCOMCalculator)
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

	STDMETHOD(Add)(int num0, int num1, int* result);
	STDMETHOD(Subtract)(int num0, int num1, int* result);
	STDMETHOD(Multiply)(int num0, int num1, int* result);
	STDMETHOD(Divide)(int num0, int num1, double* result);
	STDMETHOD(Factorial)(int* n);
};

OBJECT_ENTRY_AUTO(__uuidof(SimpleCOMCalculator), CSimpleCOMCalculator)
