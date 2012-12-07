

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Nov 17 22:38:38 2008
 */
/* Compiler settings for .\SampleCOMErrorResult.idl:
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

#ifndef __SampleCOMErrorResult_h__
#define __SampleCOMErrorResult_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMarshalCOMHRESULT_FWD_DEFINED__
#define __IMarshalCOMHRESULT_FWD_DEFINED__
typedef interface IMarshalCOMHRESULT IMarshalCOMHRESULT;
#endif 	/* __IMarshalCOMHRESULT_FWD_DEFINED__ */


#ifndef __MarshalCOMHRESULT_FWD_DEFINED__
#define __MarshalCOMHRESULT_FWD_DEFINED__

#ifdef __cplusplus
typedef class MarshalCOMHRESULT MarshalCOMHRESULT;
#else
typedef struct MarshalCOMHRESULT MarshalCOMHRESULT;
#endif /* __cplusplus */

#endif 	/* __MarshalCOMHRESULT_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMarshalCOMHRESULT_INTERFACE_DEFINED__
#define __IMarshalCOMHRESULT_INTERFACE_DEFINED__

/* interface IMarshalCOMHRESULT */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMarshalCOMHRESULT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40711F12-768E-4BBA-A0F4-2D0A085DC4DC")
    IMarshalCOMHRESULT : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenerateHRESULTs( 
            /* [in] */ int type) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReturnHRESULTs( 
            /* [in] */ int type,
            /* [retval][out] */ HRESULT *hResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMarshalCOMHRESULTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshalCOMHRESULT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshalCOMHRESULT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshalCOMHRESULT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMarshalCOMHRESULT * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMarshalCOMHRESULT * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMarshalCOMHRESULT * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMarshalCOMHRESULT * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateHRESULTs )( 
            IMarshalCOMHRESULT * This,
            /* [in] */ int type);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnHRESULTs )( 
            IMarshalCOMHRESULT * This,
            /* [in] */ int type,
            /* [retval][out] */ HRESULT *hResult);
        
        END_INTERFACE
    } IMarshalCOMHRESULTVtbl;

    interface IMarshalCOMHRESULT
    {
        CONST_VTBL struct IMarshalCOMHRESULTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshalCOMHRESULT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMarshalCOMHRESULT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMarshalCOMHRESULT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMarshalCOMHRESULT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMarshalCOMHRESULT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMarshalCOMHRESULT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMarshalCOMHRESULT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMarshalCOMHRESULT_GenerateHRESULTs(This,type)	\
    (This)->lpVtbl -> GenerateHRESULTs(This,type)

#define IMarshalCOMHRESULT_ReturnHRESULTs(This,type,hResult)	\
    (This)->lpVtbl -> ReturnHRESULTs(This,type,hResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMHRESULT_GenerateHRESULTs_Proxy( 
    IMarshalCOMHRESULT * This,
    /* [in] */ int type);


void __RPC_STUB IMarshalCOMHRESULT_GenerateHRESULTs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMHRESULT_ReturnHRESULTs_Proxy( 
    IMarshalCOMHRESULT * This,
    /* [in] */ int type,
    /* [retval][out] */ HRESULT *hResult);


void __RPC_STUB IMarshalCOMHRESULT_ReturnHRESULTs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMarshalCOMHRESULT_INTERFACE_DEFINED__ */



#ifndef __SampleCOMErrorResultLib_LIBRARY_DEFINED__
#define __SampleCOMErrorResultLib_LIBRARY_DEFINED__

/* library SampleCOMErrorResultLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SampleCOMErrorResultLib;

EXTERN_C const CLSID CLSID_MarshalCOMHRESULT;

#ifdef __cplusplus

class DECLSPEC_UUID("6FFFE22E-8011-4C8F-AEE2-2388AABA5367")
MarshalCOMHRESULT;
#endif
#endif /* __SampleCOMErrorResultLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


