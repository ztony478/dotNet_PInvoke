

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Nov 17 22:38:28 2008
 */
/* Compiler settings for .\SampleCOMDataType.idl:
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

#ifndef __SampleCOMDataType_h__
#define __SampleCOMDataType_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMarshalCOMDataType_FWD_DEFINED__
#define __IMarshalCOMDataType_FWD_DEFINED__
typedef interface IMarshalCOMDataType IMarshalCOMDataType;
#endif 	/* __IMarshalCOMDataType_FWD_DEFINED__ */


#ifndef __MarshalCOMDataType_FWD_DEFINED__
#define __MarshalCOMDataType_FWD_DEFINED__

#ifdef __cplusplus
typedef class MarshalCOMDataType MarshalCOMDataType;
#else
typedef struct MarshalCOMDataType MarshalCOMDataType;
#endif /* __cplusplus */

#endif 	/* __MarshalCOMDataType_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_SampleCOMDataType_0000 */
/* [local] */ 

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("56CE11B6-E5CA-400f-B1E8-D7C5DDB6D053") struct _SampleStruct
    {
    /* [helpstring] */ short ID;
    /* [helpstring] */ BSTR stringName;
    } 	SampleStruct;



extern RPC_IF_HANDLE __MIDL_itf_SampleCOMDataType_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_SampleCOMDataType_0000_v0_0_s_ifspec;

#ifndef __IMarshalCOMDataType_INTERFACE_DEFINED__
#define __IMarshalCOMDataType_INTERFACE_DEFINED__

/* interface IMarshalCOMDataType */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMarshalCOMDataType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E64E631-81B5-4947-A24C-C2459C13D7A1")
    IMarshalCOMDataType : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalChar( 
            /* [in] */ unsigned char inArg,
            /* [out][in] */ unsigned char *outAtg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalCOMChar( 
            /* [in] */ CHAR inArg,
            /* [out][in] */ CHAR *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalBSTR( 
            /* [in] */ BSTR inArg,
            /* [out][in] */ BSTR *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalLPSTR( 
            /* [in] */ LPSTR inArg,
            /* [out][in] */ LPSTR *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalDECIMAL( 
            /* [in] */ DECIMAL inArg,
            /* [out][in] */ DECIMAL *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalCURRENCY( 
            /* [in] */ CURRENCY inArg,
            /* [out][in] */ CURRENCY *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalBoolean( 
            /* [in] */ boolean inArg,
            /* [out][in] */ boolean *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalVariantBool( 
            /* [in] */ VARIANT_BOOL inArg,
            /* [out][in] */ VARIANT_BOOL *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalDATE( 
            /* [in] */ DATE inArg,
            /* [out][in] */ DATE *outArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalCOMVariant( 
            /* [in] */ VARIANT inArg,
            /* [out] */ VARIANT *outArg,
            /* [retval][out] */ BSTR *typeDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SortArray( 
            /* [out][in] */ SAFEARRAY * inArray,
            /* [retval][out] */ BSTR *mergedResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalCStylelArray( 
            /* [size_is][length_is][in] */ int inArg[  ],
            /* [in] */ long elementSize,
            /* [retval][out] */ int *sumOfElements) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarshalStructure( 
            /* [out][in] */ SampleStruct *inArg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMarshalCOMDataTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshalCOMDataType * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshalCOMDataType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshalCOMDataType * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMarshalCOMDataType * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMarshalCOMDataType * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMarshalCOMDataType * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMarshalCOMDataType * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalChar )( 
            IMarshalCOMDataType * This,
            /* [in] */ unsigned char inArg,
            /* [out][in] */ unsigned char *outAtg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalCOMChar )( 
            IMarshalCOMDataType * This,
            /* [in] */ CHAR inArg,
            /* [out][in] */ CHAR *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalBSTR )( 
            IMarshalCOMDataType * This,
            /* [in] */ BSTR inArg,
            /* [out][in] */ BSTR *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalLPSTR )( 
            IMarshalCOMDataType * This,
            /* [in] */ LPSTR inArg,
            /* [out][in] */ LPSTR *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalDECIMAL )( 
            IMarshalCOMDataType * This,
            /* [in] */ DECIMAL inArg,
            /* [out][in] */ DECIMAL *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalCURRENCY )( 
            IMarshalCOMDataType * This,
            /* [in] */ CURRENCY inArg,
            /* [out][in] */ CURRENCY *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalBoolean )( 
            IMarshalCOMDataType * This,
            /* [in] */ boolean inArg,
            /* [out][in] */ boolean *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalVariantBool )( 
            IMarshalCOMDataType * This,
            /* [in] */ VARIANT_BOOL inArg,
            /* [out][in] */ VARIANT_BOOL *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalDATE )( 
            IMarshalCOMDataType * This,
            /* [in] */ DATE inArg,
            /* [out][in] */ DATE *outArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalCOMVariant )( 
            IMarshalCOMDataType * This,
            /* [in] */ VARIANT inArg,
            /* [out] */ VARIANT *outArg,
            /* [retval][out] */ BSTR *typeDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SortArray )( 
            IMarshalCOMDataType * This,
            /* [out][in] */ SAFEARRAY * inArray,
            /* [retval][out] */ BSTR *mergedResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalCStylelArray )( 
            IMarshalCOMDataType * This,
            /* [size_is][length_is][in] */ int inArg[  ],
            /* [in] */ long elementSize,
            /* [retval][out] */ int *sumOfElements);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarshalStructure )( 
            IMarshalCOMDataType * This,
            /* [out][in] */ SampleStruct *inArg);
        
        END_INTERFACE
    } IMarshalCOMDataTypeVtbl;

    interface IMarshalCOMDataType
    {
        CONST_VTBL struct IMarshalCOMDataTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshalCOMDataType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMarshalCOMDataType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMarshalCOMDataType_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMarshalCOMDataType_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMarshalCOMDataType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMarshalCOMDataType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMarshalCOMDataType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMarshalCOMDataType_MarshalChar(This,inArg,outAtg)	\
    (This)->lpVtbl -> MarshalChar(This,inArg,outAtg)

#define IMarshalCOMDataType_MarshalCOMChar(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalCOMChar(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalBSTR(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalBSTR(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalLPSTR(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalLPSTR(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalDECIMAL(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalDECIMAL(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalCURRENCY(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalCURRENCY(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalBoolean(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalBoolean(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalVariantBool(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalVariantBool(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalDATE(This,inArg,outArg)	\
    (This)->lpVtbl -> MarshalDATE(This,inArg,outArg)

#define IMarshalCOMDataType_MarshalCOMVariant(This,inArg,outArg,typeDescription)	\
    (This)->lpVtbl -> MarshalCOMVariant(This,inArg,outArg,typeDescription)

#define IMarshalCOMDataType_SortArray(This,inArray,mergedResult)	\
    (This)->lpVtbl -> SortArray(This,inArray,mergedResult)

#define IMarshalCOMDataType_MarshalCStylelArray(This,inArg,elementSize,sumOfElements)	\
    (This)->lpVtbl -> MarshalCStylelArray(This,inArg,elementSize,sumOfElements)

#define IMarshalCOMDataType_MarshalStructure(This,inArg)	\
    (This)->lpVtbl -> MarshalStructure(This,inArg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalChar_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ unsigned char inArg,
    /* [out][in] */ unsigned char *outAtg);


void __RPC_STUB IMarshalCOMDataType_MarshalChar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalCOMChar_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ CHAR inArg,
    /* [out][in] */ CHAR *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalCOMChar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalBSTR_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ BSTR inArg,
    /* [out][in] */ BSTR *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalBSTR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalLPSTR_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ LPSTR inArg,
    /* [out][in] */ LPSTR *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalLPSTR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalDECIMAL_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ DECIMAL inArg,
    /* [out][in] */ DECIMAL *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalDECIMAL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalCURRENCY_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ CURRENCY inArg,
    /* [out][in] */ CURRENCY *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalCURRENCY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalBoolean_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ boolean inArg,
    /* [out][in] */ boolean *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalBoolean_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalVariantBool_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ VARIANT_BOOL inArg,
    /* [out][in] */ VARIANT_BOOL *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalVariantBool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalDATE_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ DATE inArg,
    /* [out][in] */ DATE *outArg);


void __RPC_STUB IMarshalCOMDataType_MarshalDATE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalCOMVariant_Proxy( 
    IMarshalCOMDataType * This,
    /* [in] */ VARIANT inArg,
    /* [out] */ VARIANT *outArg,
    /* [retval][out] */ BSTR *typeDescription);


void __RPC_STUB IMarshalCOMDataType_MarshalCOMVariant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_SortArray_Proxy( 
    IMarshalCOMDataType * This,
    /* [out][in] */ SAFEARRAY * inArray,
    /* [retval][out] */ BSTR *mergedResult);


void __RPC_STUB IMarshalCOMDataType_SortArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalCStylelArray_Proxy( 
    IMarshalCOMDataType * This,
    /* [size_is][length_is][in] */ int inArg[  ],
    /* [in] */ long elementSize,
    /* [retval][out] */ int *sumOfElements);


void __RPC_STUB IMarshalCOMDataType_MarshalCStylelArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMarshalCOMDataType_MarshalStructure_Proxy( 
    IMarshalCOMDataType * This,
    /* [out][in] */ SampleStruct *inArg);


void __RPC_STUB IMarshalCOMDataType_MarshalStructure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMarshalCOMDataType_INTERFACE_DEFINED__ */



#ifndef __SampleCOMDataTypeLib_LIBRARY_DEFINED__
#define __SampleCOMDataTypeLib_LIBRARY_DEFINED__

/* library SampleCOMDataTypeLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SampleCOMDataTypeLib;

EXTERN_C const CLSID CLSID_MarshalCOMDataType;

#ifdef __cplusplus

class DECLSPEC_UUID("5B8818EA-0BDE-46E6-B99B-FD149BF61422")
MarshalCOMDataType;
#endif
#endif /* __SampleCOMDataTypeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


