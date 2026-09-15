
// wr64.cpp: Uygulamanın sınıf davranışlarını tanımlar.
//

#include "pch.h"
#include "framework.h"
#include "wr64.h"
#include "wr64Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cwr64App

BEGIN_MESSAGE_MAP(Cwr64App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cwr64App oluşturma

Cwr64App::Cwr64App()
{
	// Yeniden Başlatma Yöneticisini destekle
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: Oluşturma kodunu buraya ekleyin,
	// Tüm önemli başlatmaları InitInstance'a yerleştir
}


// Tek Cwr64App nesnesi

Cwr64App theApp;


// Cwr64App başlatma

BOOL Cwr64App::InitInstance()
{
	// Windows XP'de InitCommonControlsEx() gereken durumlar
	// ComCtl32.dll sürüm 6 veya sonraki sürümlerin kullanılmasını belirtiyorsa
	// Windows XP'de InitCommonControlsEx() gerekir. Aksi takdirde pencere oluşturulamaz.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Uygulamanızda kullanmak istediğiniz tüm ortak denetim sınıflarını
	// dahil etmek için bunu ayarlayın.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// İletişim kutusunun herhangi bir kabuk ağaç görünümü
	// veya kabuk liste görünümü denetimi içermesi durumunda kabuk yöneticisini oluşturun.
	CShellManager *pShellManager = new CShellManager;

	// MFC denetimlerinde temaları etkinleştirmek için "Windows Yerel" görsel yöneticisini etkinleştirin
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standart başlatma
	// Bu özellikleri kullanmıyorsanız ve son yürütülebilir dosyanızın boyutunu
	// azaltmak istiyorsanız, aşağıdan ihtiyacınız olmayan belirli başlatma
	// yordamlarını kaldırmanız gerekir
	// Ayarlarımızın depolandığı kayıt defteri anahtarını değiştirin
	// TODO: Bu dizeyi, şirketinizin veya kuruluşunuzun adı gibi
	// uygun bir dize olarak değiştirmeniz gerekir
	SetRegistryKey(_T("Yerel AppWizard Tarafından Oluşturulan Uygulamalar"));

	Cwr64Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Buraya, iletişim kutusu
		//  Tamam düğmesiyle kapatıldığında işlenecek kodu yerleştirin
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Buraya, iletişim kutusu
		//  İptal düğmesiyle kapatıldığında işlenecek kodu yerleştirin
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Uyarı: İletişim kutusu oluşturulamadığından uygulama beklenmedik şekilde sonlandırılıyor.\n");
		TRACE(traceAppMsg, 0, "Uyarı: İletişim kutusundaki MFC denetimlerini kullanıyorsanız, #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS kullanamazsınız.\n");
	}

	// Yukarıda oluşturulan kabuk yöneticisini silin.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// İletişim kutusu kapatıldığından, uygulamanın ileti pompasını başlatmak yerine,
	//  uygulamadan çıkmamız için FALSE değerini döndürün.
	return FALSE;
}

