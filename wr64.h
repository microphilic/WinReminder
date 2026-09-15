
// wr64.h: PROJECT_NAME uygulaması için ana üst bilgi dosyası
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH için bu dosyayı eklemeden önce 'pch.h' öğesini ekle"
#endif

#include "resource.h"		// ana semboller


// Cwr64App:
// Bu sınıfın uygulaması için bkz. wr64.cpp
//

class Cwr64App : public CWinApp
{
public:
	Cwr64App();

// Geçersiz Kılar
public:
	virtual BOOL InitInstance();

// Uygulama

	DECLARE_MESSAGE_MAP()
};

extern Cwr64App theApp;
