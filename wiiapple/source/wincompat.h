/****************************************************************************
*                                                                           *
* wincompat.h -- Basic Windows Type Definitions                                *
*                                                                           *
* Copyright (c) 1985-1997, Microsoft Corp. All rights reserved.             *
*                                                                           *
****************************************************************************/


#ifndef _WINDEF_
#define _WINDEF_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BASETYPES
#define BASETYPES
typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;
#endif  /* !BASETYPES */


typedef void *HANDLE;
typedef signed short INT16;		// why there was char instead of short? --bb ??????????????????
typedef unsigned short UINT16;		// why there was char instead of short? --bb ??????????????????? 0_0
#define __int64 long long

typedef unsigned int UINT32;
typedef unsigned char UINT8;

//#define __stdcall _cdecl


#define MAX_PATH          260

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#undef far
#undef near
#undef pascal

#define far
#define near
#if (!defined(_MAC)) && ((_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED))
#define pascal __stdcall
#else
#define pascal
#endif

#undef FAR
#undef NEAR
#define FAR                 far
#define NEAR                near
#ifndef CONST
#define CONST               const
#endif

typedef unsigned long       DWORD;
typedef unsigned int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL near           *PBOOL;
typedef BOOL far            *LPBOOL;
typedef BYTE near           *PBYTE;
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;
typedef int far             *LPINT;
typedef WORD near           *PWORD;
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;
typedef DWORD near          *PDWORD;
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;
typedef CONST void far      *LPCVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;

//#define LPSTR				(char*)


#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define LOWORD(l)           ((WORD)(l))
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#define LOBYTE(w)           ((BYTE)(w))
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))

typedef DWORD   COLORREF;
typedef DWORD   *LPCOLORREF;


////////////////////////// WINNT ///////////////////////////////
#ifndef VOID
#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef long LONG;
typedef SHORT *PSHORT;
typedef LONG *PLONG;
#endif


typedef char WCHAR;    // wc,   16-bit UNICODE character
typedef WCHAR *PWCHAR;
typedef WCHAR *LPWCH, *PWCH;
typedef CONST WCHAR *LPCWCH, *PCWCH;
typedef WCHAR *NWPSTR;
typedef WCHAR *LPWSTR, *PWSTR;

typedef CONST WCHAR *LPCWSTR, *PCWSTR;



//
// ANSI (Multi-byte Character) types
//
typedef CHAR *PCHAR;
typedef CHAR *LPCH, *PCH;

typedef CONST CHAR *LPCCH, *PCCH;
typedef CHAR *NPSTR;
typedef CHAR *LPSTR, *PSTR;
typedef CONST CHAR *LPCSTR, *PCSTR;

typedef LPWSTR LPTCH, PTCH;
typedef LPWSTR PTSTR, LPTSTR;
typedef LPCWSTR LPCTSTR;
typedef LPWSTR LP;


#ifndef _TCHAR_DEFINED
typedef char TCHAR, *PTCHAR;
typedef unsigned char TBYTE , *PTBYTE ;
#define _TCHAR_DEFINED
#endif /* !_TCHAR_DEFINED */

////////////////////////////////////////////////////
typedef struct _OVERLAPPED {
	DWORD   Internal;
	DWORD   InternalHigh;
	DWORD   Offset;
	DWORD   OffsetHigh;
	HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct tagPOINT
{
	LONG  x;
	LONG  y;
} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;


// TCHAR support
#define __TEXT(quote) quote         // r_winnt
#define TEXT(quote) __TEXT(quote)   // r_winnt

#define _tcschr strchr
#define _tcscspn strcspn
#define _tcsncat strncat
#define _tcsncpy strncpy
#define _tcspbrk strpbrk
#define _tcsrchr strrchr
#define _tcsspn strspn
#define _tcsstr strstr
#define _tcstok strtok

// not ANSI????
#define _tcsnset strnset
#define _tcsrev strrev
#define _tcsset strset

#define _tcscmp strcmp
#define _tcsicmp stricmp
//#define _tcsnccmp(const char *, const char *, size_t);
#define _tcsncmp strncmp
//#define _tcsncicmp(const char *, const char *, size_t);
#define _tcsnicmp strnicmp

// #define _tcscoll(const char *, const char *);
// #define _tcsicoll(const char *, const char *);
// #define _tcsnccoll(const char *, const char *, size_t);
// #define _tcsncoll(const char *, const char *, size_t);
// #define _tcsncicoll(const char *, const char *, size_t);
// #define _tcsnicoll(const char *, const char *, size_t);

/* Note that _mbscat, _mbscpy and _mbsdup are functionally equivalent to
		strcat, strcpy and strdup, respectively. */

#define _tcscat     strcat
#define _tcscpy     strcpy
#define _tcsdup     strdup

#define _tcslen     strlen
#define _tcsxfrm    strxfrm

#define MoveMemory(Destination,Source,Length) memmove((Destination),(Source),(Length))
#define FillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
#define EqualMemory(Destination,Source,Length) (!memcmp((Destination),(Source),(Length)))
#define CopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
#define ZeroMemory(Destination,Length) memset((Destination),0,(Length))

#define GetTickCount SDL_GetTicks
#define _ASSERT	assert


#ifdef __cplusplus
}
#endif

#endif /* _WINDEF_ */

