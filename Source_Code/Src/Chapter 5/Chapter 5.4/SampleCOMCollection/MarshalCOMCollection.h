// MarshalCOMCollection.h : Declaration of the CMarshalCOMCollection

#pragma once
#include "resource.h"       // main symbols

#include "SampleCOMCollection.h"
#include <vector>
#include <comutil.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


namespace BSTRColl
{
	class _CopyPolicy;

	// 使用vector作为存放字符串的容器
	typedef std::vector<_bstr_t>					ContainerType;

	// 使用IEnumVARIANT作为枚举器以兼容VB
	typedef VARIANT									EnumeratorExposedType;
	typedef IEnumVARIANT							EnumeratorInterface;

	// 用BSTR作为集合接口暴露出来
	typedef VARIANT									CollectionExposedType;
	typedef IMarshalCOMCollection					CollectionInterface;

	typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), EnumeratorExposedType,
		_CopyPolicy, ContainerType > EnumeratorType;

	typedef ICollectionOnSTLImpl< CollectionInterface, ContainerType, CollectionExposedType,
		_CopyPolicy, EnumeratorType > CollectionType;

	class _CopyPolicy
	{
	public:

		static HRESULT copy(VARIANT* pVarDest, const _bstr_t* bstrIceCreamFlavor)
		{
			CComVariant varFlavor((TCHAR *)(*bstrIceCreamFlavor)); 

			return ::VariantCopy(pVarDest,&varFlavor);
		}

		static void init(VARIANT* pVar) 
		{
			pVar->vt = VT_EMPTY;
		}

		static void destroy(VARIANT* pVar) 
		{
			VariantClear(pVar);
		}

	};

}; // namespace BSTRColl;

// CMarshalCOMCollection
class ATL_NO_VTABLE CMarshalCOMCollection :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMarshalCOMCollection, &CLSID_MarshalCOMCollection>,
	public IDispatchImpl<BSTRColl::CollectionType, &IID_IMarshalCOMCollection, &LIBID_SampleCOMCollectionLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMarshalCOMCollection()
	{

	}

	DECLARE_REGISTRY_RESOURCEID(IDR_MARSHALCOMCOLLECTION)


	BEGIN_COM_MAP(CMarshalCOMCollection)
		COM_INTERFACE_ENTRY(IMarshalCOMCollection)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_coll.push_back(_bstr_t(_T("《编程之美》")));
		m_coll.push_back(_bstr_t(_T("《编程珠玑》")));
		m_coll.push_back(_bstr_t(_T("《Beautiful Code》")));
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(AddElement)(BSTR elem);
};

OBJECT_ENTRY_AUTO(__uuidof(MarshalCOMCollection), CMarshalCOMCollection)
