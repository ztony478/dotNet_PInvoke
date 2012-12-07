

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "SampleCOMDataType.h"

#define TYPE_FORMAT_STRING_SIZE   1147                              
#define PROC_FORMAT_STRING_SIZE   449                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMarshalCOMDataType_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMarshalCOMDataType_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, float, double or hyper in -Oif or -Oicf.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure MarshalChar */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x1e ),	/* 30 */
/* 12 */	NdrFcShort( 0x21 ),	/* 33 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 16 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter outAtg */

/* 22 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 28 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 30 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 32 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalCOMChar */

/* 34 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 36 */	NdrFcLong( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 44 */	NdrFcShort( 0x1e ),	/* 30 */
/* 46 */	NdrFcShort( 0x21 ),	/* 33 */
/* 48 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 50 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 52 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 54 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter outArg */

/* 56 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 58 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 60 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Return value */

/* 62 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 64 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 66 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalBSTR */

/* 68 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 70 */	NdrFcLong( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x9 ),	/* 9 */
/* 76 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 84 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 86 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 88 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter outArg */

/* 90 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 92 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 94 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalLPSTR */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0xa ),	/* 10 */
/* 110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 118 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 120 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 122 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Parameter outArg */

/* 124 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 126 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 128 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 132 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalDECIMAL */

/* 136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0xb ),	/* 11 */
/* 144 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 146 */	NdrFcShort( 0x54 ),	/* 84 */
/* 148 */	NdrFcShort( 0x3c ),	/* 60 */
/* 150 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 152 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 156 */	NdrFcShort( 0x46 ),	/* Type Offset=70 */

	/* Parameter outArg */

/* 158 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 160 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 162 */	NdrFcShort( 0x46 ),	/* Type Offset=70 */

	/* Return value */

/* 164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 166 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalCURRENCY */

/* 170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0xc ),	/* 12 */
/* 178 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 180 */	NdrFcShort( 0x44 ),	/* 68 */
/* 182 */	NdrFcShort( 0x34 ),	/* 52 */
/* 184 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 186 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 190 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Parameter outArg */

/* 192 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 196 */	NdrFcShort( 0x54 ),	/* Type Offset=84 */

	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalBoolean */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0xd ),	/* 13 */
/* 212 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 214 */	NdrFcShort( 0x1e ),	/* 30 */
/* 216 */	NdrFcShort( 0x21 ),	/* 33 */
/* 218 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 224 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter outArg */

/* 226 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 230 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Return value */

/* 232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalVariantBool */

/* 238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0xe ),	/* 14 */
/* 246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 248 */	NdrFcShort( 0x20 ),	/* 32 */
/* 250 */	NdrFcShort( 0x22 ),	/* 34 */
/* 252 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 254 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 258 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter outArg */

/* 260 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 264 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalDATE */

/* 272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0xf ),	/* 15 */
/* 280 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 282 */	NdrFcShort( 0x34 ),	/* 52 */
/* 284 */	NdrFcShort( 0x2c ),	/* 44 */
/* 286 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter inArg */

/* 288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter outArg */

/* 294 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 302 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalCOMVariant */

/* 306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x10 ),	/* 16 */
/* 314 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 320 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter inArg */

/* 322 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 326 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */

	/* Parameter outArg */

/* 328 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 330 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 332 */	NdrFcShort( 0x434 ),	/* Type Offset=1076 */

	/* Parameter typeDescription */

/* 334 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 336 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 338 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Return value */

/* 340 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 342 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SortArray */

/* 346 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x11 ),	/* 17 */
/* 354 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 360 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter inArray */

/* 362 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 364 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 366 */	NdrFcShort( 0x44a ),	/* Type Offset=1098 */

	/* Parameter mergedResult */

/* 368 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 370 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 372 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Return value */

/* 374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 376 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalCStylelArray */

/* 380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x12 ),	/* 18 */
/* 388 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	NdrFcShort( 0x24 ),	/* 36 */
/* 394 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter inArg */

/* 396 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	NdrFcShort( 0x454 ),	/* Type Offset=1108 */

	/* Parameter elementSize */

/* 402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sumOfElements */

/* 408 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 416 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MarshalStructure */

/* 420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x13 ),	/* 19 */
/* 428 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 434 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter inArg */

/* 436 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 438 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 440 */	NdrFcShort( 0x46a ),	/* Type Offset=1130 */

	/* Return value */

/* 442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x12, 0x0,	/* FC_UP */
/*  8 */	NdrFcShort( 0xc ),	/* Offset= 12 (20) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 20 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 22 */	NdrFcShort( 0x8 ),	/* 8 */
/* 24 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (10) */
/* 26 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 28 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 30 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x4 ),	/* 4 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (6) */
/* 40 */	
			0x11, 0x0,	/* FC_RP */
/* 42 */	NdrFcShort( 0x6 ),	/* Offset= 6 (48) */
/* 44 */	
			0x13, 0x0,	/* FC_OP */
/* 46 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (20) */
/* 48 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x4 ),	/* 4 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (44) */
/* 58 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 60 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 62 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 68 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 70 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 72 */	NdrFcShort( 0x10 ),	/* 16 */
/* 74 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 76 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 78 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 80 */	
			0x11, 0x0,	/* FC_RP */
/* 82 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (70) */
/* 84 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 86 */	NdrFcShort( 0x8 ),	/* 8 */
/* 88 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 90 */	
			0x11, 0x0,	/* FC_RP */
/* 92 */	NdrFcShort( 0xfff8 ),	/* Offset= -8 (84) */
/* 94 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 96 */	0x3,		/* FC_SMALL */
			0x5c,		/* FC_PAD */
/* 98 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 100 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 102 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 104 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 106 */	
			0x12, 0x0,	/* FC_UP */
/* 108 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (1038) */
/* 110 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 112 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 114 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 116 */	NdrFcShort( 0x2 ),	/* Offset= 2 (118) */
/* 118 */	NdrFcShort( 0x10 ),	/* 16 */
/* 120 */	NdrFcShort( 0x2f ),	/* 47 */
/* 122 */	NdrFcLong( 0x14 ),	/* 20 */
/* 126 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 128 */	NdrFcLong( 0x3 ),	/* 3 */
/* 132 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 134 */	NdrFcLong( 0x11 ),	/* 17 */
/* 138 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 140 */	NdrFcLong( 0x2 ),	/* 2 */
/* 144 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 146 */	NdrFcLong( 0x4 ),	/* 4 */
/* 150 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 152 */	NdrFcLong( 0x5 ),	/* 5 */
/* 156 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 158 */	NdrFcLong( 0xb ),	/* 11 */
/* 162 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 164 */	NdrFcLong( 0xa ),	/* 10 */
/* 168 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 170 */	NdrFcLong( 0x6 ),	/* 6 */
/* 174 */	NdrFcShort( 0xffa6 ),	/* Offset= -90 (84) */
/* 176 */	NdrFcLong( 0x7 ),	/* 7 */
/* 180 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 182 */	NdrFcLong( 0x8 ),	/* 8 */
/* 186 */	NdrFcShort( 0xff4c ),	/* Offset= -180 (6) */
/* 188 */	NdrFcLong( 0xd ),	/* 13 */
/* 192 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (406) */
/* 194 */	NdrFcLong( 0x9 ),	/* 9 */
/* 198 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (424) */
/* 200 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 204 */	NdrFcShort( 0xee ),	/* Offset= 238 (442) */
/* 206 */	NdrFcLong( 0x24 ),	/* 36 */
/* 210 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (974) */
/* 212 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 216 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (974) */
/* 218 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 222 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (978) */
/* 224 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 228 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (982) */
/* 230 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 234 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (986) */
/* 236 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 240 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (990) */
/* 242 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 246 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (994) */
/* 248 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 252 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (998) */
/* 254 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 258 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (982) */
/* 260 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 264 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (986) */
/* 266 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 270 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (1002) */
/* 272 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 276 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (998) */
/* 278 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 282 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (1006) */
/* 284 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 288 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (1010) */
/* 290 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 294 */	NdrFcShort( 0x2d0 ),	/* Offset= 720 (1014) */
/* 296 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 300 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (1018) */
/* 302 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 306 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (1022) */
/* 308 */	NdrFcLong( 0x10 ),	/* 16 */
/* 312 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 314 */	NdrFcLong( 0x12 ),	/* 18 */
/* 318 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 320 */	NdrFcLong( 0x13 ),	/* 19 */
/* 324 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 326 */	NdrFcLong( 0x15 ),	/* 21 */
/* 330 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 332 */	NdrFcLong( 0x16 ),	/* 22 */
/* 336 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 338 */	NdrFcLong( 0x17 ),	/* 23 */
/* 342 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 344 */	NdrFcLong( 0xe ),	/* 14 */
/* 348 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (70) */
/* 350 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 354 */	NdrFcShort( 0x2a4 ),	/* Offset= 676 (1030) */
/* 356 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 360 */	NdrFcShort( 0x2a2 ),	/* Offset= 674 (1034) */
/* 362 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 366 */	NdrFcShort( 0x268 ),	/* Offset= 616 (982) */
/* 368 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 372 */	NdrFcShort( 0x266 ),	/* Offset= 614 (986) */
/* 374 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 378 */	NdrFcShort( 0x264 ),	/* Offset= 612 (990) */
/* 380 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 384 */	NdrFcShort( 0x25a ),	/* Offset= 602 (986) */
/* 386 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 390 */	NdrFcShort( 0x254 ),	/* Offset= 596 (986) */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x0 ),	/* Offset= 0 (396) */
/* 398 */	NdrFcLong( 0x1 ),	/* 1 */
/* 402 */	NdrFcShort( 0x0 ),	/* Offset= 0 (402) */
/* 404 */	NdrFcShort( 0xffff ),	/* Offset= -1 (403) */
/* 406 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 418 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 420 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 422 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 424 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 426 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 436 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 438 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 440 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 442 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 444 */	NdrFcShort( 0x2 ),	/* Offset= 2 (446) */
/* 446 */	
			0x12, 0x0,	/* FC_UP */
/* 448 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (956) */
/* 450 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 452 */	NdrFcShort( 0x18 ),	/* 24 */
/* 454 */	NdrFcShort( 0xa ),	/* 10 */
/* 456 */	NdrFcLong( 0x8 ),	/* 8 */
/* 460 */	NdrFcShort( 0x58 ),	/* Offset= 88 (548) */
/* 462 */	NdrFcLong( 0xd ),	/* 13 */
/* 466 */	NdrFcShort( 0x78 ),	/* Offset= 120 (586) */
/* 468 */	NdrFcLong( 0x9 ),	/* 9 */
/* 472 */	NdrFcShort( 0x94 ),	/* Offset= 148 (620) */
/* 474 */	NdrFcLong( 0xc ),	/* 12 */
/* 478 */	NdrFcShort( 0xbc ),	/* Offset= 188 (666) */
/* 480 */	NdrFcLong( 0x24 ),	/* 36 */
/* 484 */	NdrFcShort( 0x114 ),	/* Offset= 276 (760) */
/* 486 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 490 */	NdrFcShort( 0x130 ),	/* Offset= 304 (794) */
/* 492 */	NdrFcLong( 0x10 ),	/* 16 */
/* 496 */	NdrFcShort( 0x148 ),	/* Offset= 328 (824) */
/* 498 */	NdrFcLong( 0x2 ),	/* 2 */
/* 502 */	NdrFcShort( 0x160 ),	/* Offset= 352 (854) */
/* 504 */	NdrFcLong( 0x3 ),	/* 3 */
/* 508 */	NdrFcShort( 0x178 ),	/* Offset= 376 (884) */
/* 510 */	NdrFcLong( 0x14 ),	/* 20 */
/* 514 */	NdrFcShort( 0x190 ),	/* Offset= 400 (914) */
/* 516 */	NdrFcShort( 0xffff ),	/* Offset= -1 (515) */
/* 518 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 520 */	NdrFcShort( 0x4 ),	/* 4 */
/* 522 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 528 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 530 */	NdrFcShort( 0x4 ),	/* 4 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x1 ),	/* 1 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	0x12, 0x0,	/* FC_UP */
/* 542 */	NdrFcShort( 0xfdf6 ),	/* Offset= -522 (20) */
/* 544 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 546 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 548 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 554 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 556 */	NdrFcShort( 0x4 ),	/* 4 */
/* 558 */	NdrFcShort( 0x4 ),	/* 4 */
/* 560 */	0x11, 0x0,	/* FC_RP */
/* 562 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (518) */
/* 564 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 566 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 568 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 580 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 582 */	NdrFcShort( 0xff50 ),	/* Offset= -176 (406) */
/* 584 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 586 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x6 ),	/* Offset= 6 (598) */
/* 594 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 596 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 598 */	
			0x11, 0x0,	/* FC_RP */
/* 600 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (568) */
/* 602 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 614 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 616 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (424) */
/* 618 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 620 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x6 ),	/* Offset= 6 (632) */
/* 628 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 630 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 632 */	
			0x11, 0x0,	/* FC_RP */
/* 634 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (602) */
/* 636 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 638 */	NdrFcShort( 0x4 ),	/* 4 */
/* 640 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 646 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 648 */	NdrFcShort( 0x4 ),	/* 4 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x1 ),	/* 1 */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	0x12, 0x0,	/* FC_UP */
/* 660 */	NdrFcShort( 0x17a ),	/* Offset= 378 (1038) */
/* 662 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 664 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 666 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x6 ),	/* Offset= 6 (678) */
/* 674 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 676 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 678 */	
			0x11, 0x0,	/* FC_RP */
/* 680 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (636) */
/* 682 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 684 */	NdrFcLong( 0x2f ),	/* 47 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 694 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 696 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 698 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 700 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 702 */	NdrFcShort( 0x1 ),	/* 1 */
/* 704 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 706 */	NdrFcShort( 0x4 ),	/* 4 */
/* 708 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 710 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 712 */	NdrFcShort( 0x10 ),	/* 16 */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0xa ),	/* Offset= 10 (726) */
/* 718 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 720 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 722 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (682) */
/* 724 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 726 */	
			0x12, 0x0,	/* FC_UP */
/* 728 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (700) */
/* 730 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 732 */	NdrFcShort( 0x4 ),	/* 4 */
/* 734 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 740 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 742 */	NdrFcShort( 0x4 ),	/* 4 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	0x12, 0x0,	/* FC_UP */
/* 754 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (710) */
/* 756 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 758 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 760 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x6 ),	/* Offset= 6 (772) */
/* 768 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 770 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 772 */	
			0x11, 0x0,	/* FC_RP */
/* 774 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (730) */
/* 776 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 780 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 782 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 784 */	NdrFcShort( 0x10 ),	/* 16 */
/* 786 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 788 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 790 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (776) */
			0x5b,		/* FC_END */
/* 794 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 796 */	NdrFcShort( 0x18 ),	/* 24 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0xa ),	/* Offset= 10 (810) */
/* 802 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 804 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 806 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (782) */
/* 808 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 810 */	
			0x11, 0x0,	/* FC_RP */
/* 812 */	NdrFcShort( 0xff0c ),	/* Offset= -244 (568) */
/* 814 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 816 */	NdrFcShort( 0x1 ),	/* 1 */
/* 818 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 824 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 830 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 832 */	NdrFcShort( 0x4 ),	/* 4 */
/* 834 */	NdrFcShort( 0x4 ),	/* 4 */
/* 836 */	0x12, 0x0,	/* FC_UP */
/* 838 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (814) */
/* 840 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 842 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 844 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 846 */	NdrFcShort( 0x2 ),	/* 2 */
/* 848 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 854 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 858 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 860 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 862 */	NdrFcShort( 0x4 ),	/* 4 */
/* 864 */	NdrFcShort( 0x4 ),	/* 4 */
/* 866 */	0x12, 0x0,	/* FC_UP */
/* 868 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (844) */
/* 870 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 872 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 874 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 876 */	NdrFcShort( 0x4 ),	/* 4 */
/* 878 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 884 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 888 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 890 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 892 */	NdrFcShort( 0x4 ),	/* 4 */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	0x12, 0x0,	/* FC_UP */
/* 898 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (874) */
/* 900 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 902 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 904 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 908 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 914 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 918 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 920 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 922 */	NdrFcShort( 0x4 ),	/* 4 */
/* 924 */	NdrFcShort( 0x4 ),	/* 4 */
/* 926 */	0x12, 0x0,	/* FC_UP */
/* 928 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (904) */
/* 930 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 932 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 934 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 938 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 940 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 942 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 946 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 948 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 950 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 952 */	NdrFcShort( 0xffee ),	/* Offset= -18 (934) */
/* 954 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 956 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 958 */	NdrFcShort( 0x28 ),	/* 40 */
/* 960 */	NdrFcShort( 0xffee ),	/* Offset= -18 (942) */
/* 962 */	NdrFcShort( 0x0 ),	/* Offset= 0 (962) */
/* 964 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 966 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 968 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 970 */	NdrFcShort( 0xfdf8 ),	/* Offset= -520 (450) */
/* 972 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 974 */	
			0x12, 0x0,	/* FC_UP */
/* 976 */	NdrFcShort( 0xfef6 ),	/* Offset= -266 (710) */
/* 978 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 980 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 982 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 984 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 986 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 988 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 990 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 992 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 994 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 996 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 998 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1000 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1002 */	
			0x12, 0x0,	/* FC_UP */
/* 1004 */	NdrFcShort( 0xfc68 ),	/* Offset= -920 (84) */
/* 1006 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1008 */	NdrFcShort( 0xfc16 ),	/* Offset= -1002 (6) */
/* 1010 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1012 */	NdrFcShort( 0xfda2 ),	/* Offset= -606 (406) */
/* 1014 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1016 */	NdrFcShort( 0xfdb0 ),	/* Offset= -592 (424) */
/* 1018 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1020 */	NdrFcShort( 0xfdbe ),	/* Offset= -578 (442) */
/* 1022 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1024 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1026) */
/* 1026 */	
			0x12, 0x0,	/* FC_UP */
/* 1028 */	NdrFcShort( 0xa ),	/* Offset= 10 (1038) */
/* 1030 */	
			0x12, 0x0,	/* FC_UP */
/* 1032 */	NdrFcShort( 0xfc3e ),	/* Offset= -962 (70) */
/* 1034 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1036 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1038 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1040 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1044) */
/* 1046 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1048 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1050 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1052 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1054 */	NdrFcShort( 0xfc50 ),	/* Offset= -944 (110) */
/* 1056 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1058 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1060 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1062 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0xfc40 ),	/* Offset= -960 (106) */
/* 1068 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1070 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1076) */
/* 1072 */	
			0x13, 0x0,	/* FC_OP */
/* 1074 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1038) */
/* 1076 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1078 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1080 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1072) */
/* 1086 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1088 */	NdrFcShort( 0xfbf0 ),	/* Offset= -1040 (48) */
/* 1090 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1092 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1094) */
/* 1094 */	
			0x13, 0x0,	/* FC_OP */
/* 1096 */	NdrFcShort( 0xff74 ),	/* Offset= -140 (956) */
/* 1098 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1100 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1102 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1090) */
/* 1108 */	
			0x1c,		/* FC_CVARRAY */
			0x3,		/* 3 */
/* 1110 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1112 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 1114 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1116 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 1118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1120 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1122 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1124 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1126 */	
			0x11, 0x0,	/* FC_RP */
/* 1128 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1130) */
/* 1130 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1136) */
/* 1138 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1140 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1142 */	NdrFcShort( 0xfbba ),	/* Offset= -1094 (48) */
/* 1144 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };



/* Standard interface: __MIDL_itf_SampleCOMDataType_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMarshalCOMDataType, ver. 0.0,
   GUID={0x0E64E631,0x81B5,0x4947,{0xA2,0x4C,0xC2,0x45,0x9C,0x13,0xD7,0xA1}} */

#pragma code_seg(".orpc")
static const unsigned short IMarshalCOMDataType_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    34,
    68,
    102,
    136,
    170,
    204,
    238,
    272,
    306,
    346,
    380,
    420
    };

static const MIDL_STUBLESS_PROXY_INFO IMarshalCOMDataType_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMarshalCOMDataType_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMarshalCOMDataType_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMarshalCOMDataType_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _IMarshalCOMDataTypeProxyVtbl = 
{
    &IMarshalCOMDataType_ProxyInfo,
    &IID_IMarshalCOMDataType,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalChar */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalCOMChar */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalBSTR */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalLPSTR */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalDECIMAL */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalCURRENCY */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalBoolean */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalVariantBool */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalDATE */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalCOMVariant */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::SortArray */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalCStylelArray */ ,
    (void *) (INT_PTR) -1 /* IMarshalCOMDataType::MarshalStructure */
};


static const PRPC_STUB_FUNCTION IMarshalCOMDataType_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMarshalCOMDataTypeStubVtbl =
{
    &IID_IMarshalCOMDataType,
    &IMarshalCOMDataType_ServerInfo,
    20,
    &IMarshalCOMDataType_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _SampleCOMDataType_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMarshalCOMDataTypeProxyVtbl,
    0
};

const CInterfaceStubVtbl * _SampleCOMDataType_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMarshalCOMDataTypeStubVtbl,
    0
};

PCInterfaceName const _SampleCOMDataType_InterfaceNamesList[] = 
{
    "IMarshalCOMDataType",
    0
};

const IID *  _SampleCOMDataType_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _SampleCOMDataType_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _SampleCOMDataType, pIID, n)

int __stdcall _SampleCOMDataType_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_SampleCOMDataType_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo SampleCOMDataType_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _SampleCOMDataType_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _SampleCOMDataType_StubVtblList,
    (const PCInterfaceName * ) & _SampleCOMDataType_InterfaceNamesList,
    (const IID ** ) & _SampleCOMDataType_BaseIIDList,
    & _SampleCOMDataType_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

