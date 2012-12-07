

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Nov 17 22:38:41 2008
 */
/* Compiler settings for .\SampleCOMErrorInfo.idl:
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

#ifndef __SampleCOMErrorInfo_h__
#define __SampleCOMErrorInfo_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMarshalErrorInfo_FWD_DEFINED__
#define __IMarshalErrorInfo_FWD_DEFINED__
typedef interface IMarshalErrorInfo IMarshalErrorInfo;
#endif 	/* __IMarshalErrorInfo_FWD_DEFINED__ */


#ifndef __MarshalErrorInfo_FWD_DEFINED__
#define __MarshalErrorInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class MarshalErrorInfo MarshalErrorInfo;
#else
typedef struct MarshalErrorInfo MarshalErrorInfo;
#endif /* __cplusplus */

#endif 	/* __MarshalErrorInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMarshalErrorInfo_INTERFACE_DEFINED__
#define __IMarshalErrorInfo_INTERFACE_DEFINED__

/* interface IMarshalErrorInfo */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMarshalErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C398E746-ADF3-4774-BE25-081642377787")
    IMarshalErrorInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenerateCOMError( 
            /* [in] */ int type) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMarshalErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshalErrorInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshalErrorInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshalErrorInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMarshalErrorInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMarshalErrorInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMarshalErrorInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMarshalErrorInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateCOMError )( 
            IMarshalErrorInfo * This,
            /* [in] */ int type);
        
        END_INTERFACE
    } IMarshalErrorInfoVtbl;

    interface IMarshalErrorInfo
    {
        CONST_VTBL struct IMarshalErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshalErrorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMarshalErrorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMarshalErrorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMarshalErrorInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMarshalErrorInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMarshalErrorInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMarshalErrorInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMarshalErrorInfo_GenerateCOMError(This,type)	\
    (This)->lpVtbl -> GenerateCOMError(This,type)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalErrorInfo_GenerateCOMError_Proxy( 
    IMarshalErrorInfo * This,
    /* [in] */ int type);


void __RPC_STUB IMarshalErrorInfo_GenerateCOMError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMarshalErrorInfo_INTERFACE_DEFINED__ */



#ifndef __SampleCOMErrorInfoLib_LIBRARY_DEFINED__
#define __SampleCOMErrorInfoLib_LIBRARY_DEFINED__

/* library SampleCOMErrorInfoLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SampleCOMErrorInfoLib;

EXTERN_C const CLSID CLSID_MarshalErrorInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("ACCA4072-A575-475E-A2CB-AFD8F3A7A2F9")
MarshalErrorInfo;
#endif
#endif /* __SampleCOMErrorInfoLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


