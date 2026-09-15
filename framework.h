#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Nadiren kullanılan verileri Windows üst bilgilerinden dışla
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // Bazı CString oluşturucuları açık olacak

// MFC'nin bazı genel ve çoğu zaman güvenle yoksayılan uyarı iletilerini gizleme özelliğini kapatır
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC çekirdeği ve standart bileşenler
#include <afxext.h>         // MFC uzantıları


#include <afxdisp.h>        // MFC Otomasyonu sınıfları



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 Ortak Denetimleri için MFC desteği
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows Ortak Denetimleri için MFC desteği
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // Şeritler ve denetim çubukları için MFC desteği









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


