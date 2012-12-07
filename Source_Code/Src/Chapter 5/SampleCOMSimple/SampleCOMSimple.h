

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Nov 17 23:43:12 2008
 */
/* Compiler settings for .\SampleCOMSimple.idl:
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

#ifndef __SampleCOMSimple_h__
#define __SampleCOMSimple_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISimpleCOMCalculator_FWD_DEFINED__
#define __ISimpleCOMCalculator_FWD_DEFINED__
typedef interface ISimpleCOMCalculator ISimpleCOMCalculator;
#endif 	/* __ISimpleCOMCalculator_FWD_DEFINED__ */


#ifndef __ICOMMTAObj_FWD_DEFINED__
#define __ICOMMTAObj_FWD_DEFINED__
typedef interface ICOMMTAObj ICOMMTAObj;
#endif 	/* __ICOMMTAObj_FWD_DEFINED__ */


#ifndef __SimpleCOMCalculator_FWD_DEFINED__
#define __SimpleCOMCalculator_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleCOMCalculator SimpleCOMCalculator;
#else
typedef struct SimpleCOMCalculator SimpleCOMCalculator;
#endif /* __cplusplus */

#endif 	/* __SimpleCOMCalculator_FWD_DEFINED__ */


#ifndef __COMMTAObj_FWD_DEFINED__
#define __COMMTAObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class COMMTAObj COMMTAObj;
#else
typedef struct COMMTAObj COMMTAObj;
#endif /* __cplusplus */

#endif 	/* __COMMTAObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ISimpleCOMCalculator_INTERFACE_DEFINED__
#define __ISimpleCOMCalculator_INTERFACE_DEFINED__

/* interface ISimpleCOMCalculator */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISimpleCOMCalculator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB1DE569-9B3D-491F-8EFC-25478CFBF172")
    ISimpleCOMCalculator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Subtract( 
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Multiply( 
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Divide( 
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ double *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Factorial( 
            /* [out][in] */ int *n) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleCOMCalculatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleCOMCalculator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleCOMCalculator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleCOMCalculator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISimpleCOMCalculator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISimpleCOMCalculator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISimpleCOMCalculator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISimpleCOMCalculator * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ISimpleCOMCalculator * This,
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Subtract )( 
            ISimpleCOMCalculator * This,
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Multiply )( 
            ISimpleCOMCalculator * This,
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Divide )( 
            ISimpleCOMCalculator * This,
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ double *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Factorial )( 
            ISimpleCOMCalculator * This,
            /* [out][in] */ int *n);
        
        END_INTERFACE
    } ISimpleCOMCalculatorVtbl;

    interface ISimpleCOMCalculator
    {
        CONST_VTBL struct ISimpleCOMCalculatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleCOMCalculator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISimpleCOMCalculator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISimpleCOMCalculator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISimpleCOMCalculator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISimpleCOMCalculator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISimpleCOMCalculator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISimpleCOMCalculator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISimpleCOMCalculator_Add(This,num0,num1,result)	\
    (This)->lpVtbl -> Add(This,num0,num1,result)

#define ISimpleCOMCalculator_Subtract(This,num0,num1,result)	\
    (This)->lpVtbl -> Subtract(This,num0,num1,result)

#define ISimpleCOMCalculator_Multiply(This,num0,num1,result)	\
    (This)->lpVtbl -> Multiply(This,num0,num1,result)

#define ISimpleCOMCalculator_Divide(This,num0,num1,result)	\
    (This)->lpVtbl -> Divide(This,num0,num1,result)

#define ISimpleCOMCalculator_Factorial(This,n)	\
    (This)->lpVtbl -> Factorial(This,n)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimpleCOMCalculator_Add_Proxy( 
    ISimpleCOMCalculator * This,
    /* [in] */ int num0,
    /* [in] */ int num1,
    /* [retval][out] */ int *result);


void __RPC_STUB ISimpleCOMCalculator_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimpleCOMCalculator_Subtract_Proxy( 
    ISimpleCOMCalculator * This,
    /* [in] */ int num0,
    /* [in] */ int num1,
    /* [retval][out] */ int *result);


void __RPC_STUB ISimpleCOMCalculator_Subtract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimpleCOMCalculator_Multiply_Proxy( 
    ISimpleCOMCalculator * This,
    /* [in] */ int num0,
    /* [in] */ int num1,
    /* [retval][out] */ int *result);


void __RPC_STUB ISimpleCOMCalculator_Multiply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimpleCOMCalculator_Divide_Proxy( 
    ISimpleCOMCalculator * This,
    /* [in] */ int num0,
    /* [in] */ int num1,
    /* [retval][out] */ double *result);


void __RPC_STUB ISimpleCOMCalculator_Divide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimpleCOMCalculator_Factorial_Proxy( 
    ISimpleCOMCalculator * This,
    /* [out][in] */ int *n);


void __RPC_STUB ISimpleCOMCalculator_Factorial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISimpleCOMCalculator_INTERFACE_DEFINED__ */


#ifndef __ICOMMTAObj_INTERFACE_DEFINED__
#define __ICOMMTAObj_INTERFACE_DEFINED__

/* interface ICOMMTAObj */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICOMMTAObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24CD8CB8-A1B3-4D6B-93EB-17F40B609210")
    ICOMMTAObj : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddIntegers( 
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessString( 
            /* [in] */ BSTR inString,
            /* [retval][out] */ BSTR *outString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICOMMTAObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICOMMTAObj * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICOMMTAObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICOMMTAObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICOMMTAObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICOMMTAObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICOMMTAObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICOMMTAObj * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddIntegers )( 
            ICOMMTAObj * This,
            /* [in] */ int num0,
            /* [in] */ int num1,
            /* [retval][out] */ int *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessString )( 
            ICOMMTAObj * This,
            /* [in] */ BSTR inString,
            /* [retval][out] */ BSTR *outString);
        
        END_INTERFACE
    } ICOMMTAObjVtbl;

    interface ICOMMTAObj
    {
        CONST_VTBL struct ICOMMTAObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICOMMTAObj_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICOMMTAObj_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICOMMTAObj_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICOMMTAObj_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICOMMTAObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICOMMTAObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICOMMTAObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICOMMTAObj_AddIntegers(This,num0,num1,result)	\
    (This)->lpVtbl -> AddIntegers(This,num0,num1,result)

#define ICOMMTAObj_ProcessString(This,inString,outString)	\
    (This)->lpVtbl -> ProcessString(This,inString,outString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOMMTAObj_AddIntegers_Proxy( 
    ICOMMTAObj * This,
    /* [in] */ int num0,
    /* [in] */ int num1,
    /* [retval][out] */ int *result);


void __RPC_STUB ICOMMTAObj_AddIntegers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOMMTAObj_ProcessString_Proxy( 
    ICOMMTAObj * This,
    /* [in] */ BSTR inString,
    /* [retval][out] */ BSTR *outString);


void __RPC_STUB ICOMMTAObj_ProcessString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICOMMTAObj_INTERFACE_DEFINED__ */



#ifndef __SampleCOMSimpleLib_LIBRARY_DEFINED__
#define __SampleCOMSimpleLib_LIBRARY_DEFINED__

/* library SampleCOMSimpleLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SampleCOMSimpleLib;

EXTERN_C const CLSID CLSID_SimpleCOMCalculator;

#ifdef __cplusplus

class DECLSPEC_UUID("C7386CE7-47B0-43C4-82D4-5FFA7A359EEA")
SimpleCOMCalculator;
#endif

EXTERN_C const CLSID CLSID_COMMTAObj;

#ifdef __cplusplus

class DECLSPEC_UUID("D1CBDEC0-EBF9-49AA-917F-F99E836EA741")
COMMTAObj;
#endif
#endif /* __SampleCOMSimpleLib_LIBRARY_DEFINED__ */

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


