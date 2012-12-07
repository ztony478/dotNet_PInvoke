

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ISimpleCOMCalculator,0xFB1DE569,0x9B3D,0x491F,0x8E,0xFC,0x25,0x47,0x8C,0xFB,0xF1,0x72);


MIDL_DEFINE_GUID(IID, IID_ICOMMTAObj,0x24CD8CB8,0xA1B3,0x4D6B,0x93,0xEB,0x17,0xF4,0x0B,0x60,0x92,0x10);


MIDL_DEFINE_GUID(IID, LIBID_SampleCOMSimpleLib,0x59C84564,0x8D03,0x4D55,0xB3,0x22,0x08,0xDF,0xC0,0x18,0x90,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_SimpleCOMCalculator,0xC7386CE7,0x47B0,0x43C4,0x82,0xD4,0x5F,0xFA,0x7A,0x35,0x9E,0xEA);


MIDL_DEFINE_GUID(CLSID, CLSID_COMMTAObj,0xD1CBDEC0,0xEBF9,0x49AA,0x91,0x7F,0xF9,0x9E,0x83,0x6E,0xA7,0x41);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



