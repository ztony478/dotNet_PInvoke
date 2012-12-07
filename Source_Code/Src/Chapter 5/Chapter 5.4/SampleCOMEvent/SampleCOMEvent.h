

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Nov 17 22:38:17 2008
 */
/* Compiler settings for .\SampleCOMEvent.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SampleCOMEvent_h__
#define __SampleCOMEvent_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMarshalCOMEvent_FWD_DEFINED__
#define __IMarshalCOMEvent_FWD_DEFINED__
typedef interface IMarshalCOMEvent IMarshalCOMEvent;
#endif 	/* __IMarshalCOMEvent_FWD_DEFINED__ */


#ifndef ___IMarshalCOMEventEvents_FWD_DEFINED__
#define ___IMarshalCOMEventEvents_FWD_DEFINED__
typedef interface _IMarshalCOMEventEvents _IMarshalCOMEventEvents;
#endif 	/* ___IMarshalCOMEventEvents_FWD_DEFINED__ */


#ifndef __MarshalCOMEvent_FWD_DEFINED__
#define __MarshalCOMEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class MarshalCOMEvent MarshalCOMEvent;
#else
typedef struct MarshalCOMEvent MarshalCOMEvent;
#endif /* __cplusplus */

#endif 	/* __MarshalCOMEvent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMarshalCOMEvent_INTERFACE_DEFINED__
#define __IMarshalCOMEvent_INTERFACE_DEFINED__

/* interface IMarshalCOMEvent */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMarshalCOMEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01ECCC68-8A82-4EF3-9049-9AD5D936765E")
    IMarshalCOMEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeStringValue( 
            /* [in] */ BSTR originalString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMarshalCOMEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshalCOMEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshalCOMEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshalCOMEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMarshalCOMEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMarshalCOMEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMarshalCOMEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMarshalCOMEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeStringValue )( 
            IMarshalCOMEvent * This,
            /* [in] */ BSTR originalString);
        
        END_INTERFACE
    } IMarshalCOMEventVtbl;

    interface IMarshalCOMEvent
    {
        CONST_VTBL struct IMarshalCOMEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshalCOMEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMarshalCOMEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMarshalCOMEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMarshalCOMEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMarshalCOMEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMarshalCOMEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMarshalCOMEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMarshalCOMEvent_ChangeStringValue(This,originalString)	\
    (This)->lpVtbl -> ChangeStringValue(This,originalString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMEvent_ChangeStringValue_Proxy( 
    IMarshalCOMEvent * This,
    /* [in] */ BSTR originalString);


void __RPC_STUB IMarshalCOMEvent_ChangeStringValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMarshalCOMEvent_INTERFACE_DEFINED__ */



#ifndef __SampleCOMEventLib_LIBRARY_DEFINED__
#define __SampleCOMEventLib_LIBRARY_DEFINED__

/* library SampleCOMEventLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SampleCOMEventLib;

#ifndef ___IMarshalCOMEventEvents_DISPINTERFACE_DEFINED__
#define ___IMarshalCOMEventEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMarshalCOMEventEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IMarshalCOMEventEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8A7FF4CA-A9B1-4367-A35C-1D1BCC526F30")
    _IMarshalCOMEventEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMarshalCOMEventEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMarshalCOMEventEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMarshalCOMEventEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMarshalCOMEventEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMarshalCOMEventEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMarshalCOMEventEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMarshalCOMEventEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMarshalCOMEventEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IMarshalCOMEventEventsVtbl;

    interface _IMarshalCOMEventEvents
    {
        CONST_VTBL struct _IMarshalCOMEventEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMarshalCOMEventEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IMarshalCOMEventEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IMarshalCOMEventEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IMarshalCOMEventEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IMarshalCOMEventEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IMarshalCOMEventEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IMarshalCOMEventEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMarshalCOMEventEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MarshalCOMEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("91192C15-C17C-4BA4-A7E0-EC380C216FD6")
MarshalCOMEvent;
#endif
#endif /* __SampleCOMEventLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


