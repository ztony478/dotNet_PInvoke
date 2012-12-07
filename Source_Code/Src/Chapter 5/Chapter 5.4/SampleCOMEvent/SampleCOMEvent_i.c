

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IMarshalCOMEvent,0x01ECCC68,0x8A82,0x4EF3,0x90,0x49,0x9A,0xD5,0xD9,0x36,0x76,0x5E);


MIDL_DEFINE_GUID(IID, LIBID_SampleCOMEventLib,0xB5F7D422,0x9663,0x45F5,0xA0,0xC1,0xFD,0x1C,0xB0,0x94,0xE7,0xE8);


MIDL_DEFINE_GUID(IID, DIID__IMarshalCOMEventEvents,0x8A7FF4CA,0xA9B1,0x4367,0xA3,0x5C,0x1D,0x1B,0xCC,0x52,0x6F,0x30);


MIDL_DEFINE_GUID(CLSID, CLSID_MarshalCOMEvent,0x91192C15,0xC17C,0x4BA4,0xA7,0xE0,0xEC,0x38,0x0C,0x21,0x6F,0xD6);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



