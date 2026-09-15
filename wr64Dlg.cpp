
// wr64Dlg.cpp: uygulama dosyası
//

#include "pch.h"
#include "framework.h"
#include "wr64.h"
#include "wr64Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Uygulamanın Hakkında bölümü için kullanılan CAboutDlg iletişim kutusu

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// İletişim Kutusu Verileri
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV desteği

// Uygulama
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cwr64Dlg iletişim kutusu



Cwr64Dlg::Cwr64Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WR64_DIALOG, pParent)
	, m_strTask(_T(""))
	, m_selectedDate(COleDateTime::GetCurrentTime())
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cwr64Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strTask);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1, m_selectedDate);
}

BEGIN_MESSAGE_MAP(Cwr64Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, &Cwr64Dlg::OnMcnSelchangeMonthcalendar1)
	ON_BN_CLICKED(IDOK, &Cwr64Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Cwr64Dlg ileti işleyicileri

BOOL Cwr64Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Sistem menüsüne "Hakkında..." menü öğesini ekleyin.

	// IDM_ABOUTBOX, sistem komutu aralığında olmalıdır.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Bu iletişim kutusu için simgeyi ayarlayın. Uygulamanın ana penceresi,
	//  iletişim kutusu olmadığında çerçeve bunu otomatik olarak yapar
	SetIcon(m_hIcon, TRUE);			// Büyük simge ayarla
	SetIcon(m_hIcon, FALSE);		// Küçük simge ayarla

	// TODO: Buraya ek başlatma işlemlerini ekleyin

	return TRUE;  // Odağı bir denetime ayarlamadığınız sürece TRUE döndürün
}

void Cwr64Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// İletişim kutunuza bir simge durumuna küçültme düğmesi eklerseniz, simgeyi çizmek için
//  aşağıdaki kod gerekir. Belge/görünüm modelini kullanan MFC uygulamaları için bu,
//  çerçeve tarafından sizin için otomatik olarak yapılır.

void Cwr64Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // boyama için cihaz bağlamı

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Simgeyi istemci dikdörtgeni içinde ortalayın
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Simgeyi çizin
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Sistem, kullanıcı simge durumuna küçültülmüş pencereyi sürüklerken görüntülenecek imleci
//  elde etmek için bu işlevi çağırır.
HCURSOR Cwr64Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cwr64Dlg::OnMcnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO:Kontrol bildirimi işleyicinizin kodunu buraya ekleyin
	SYSTEMTIME st = pSelChange->stSelStart;
	m_selectedDate = COleDateTime(st);
	*pResult = 0;
}

void Cwr64Dlg::OnBnClickedOk()
{
	// TODO:Kontrol bildirimi işleyicinizin kodunu buraya ekleyin
	UpdateData(TRUE);

	CFileDialog dlg(TRUE, _T("txt"), nullptr, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Metin belgeleri (*.txt)|*.txt||"));

	if (dlg.DoModal() == IDOK)
	{
		CString path = dlg.GetPathName();
		CStdioFile file;
		if (file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
		{
			CString line;
			line.Format(_T("Not: %s\r\nTarih: %02d/%02d/%04d\r\n"), m_strTask, m_selectedDate.GetDay(),
				m_selectedDate.GetMonth(), m_selectedDate.GetYear());

			file.WriteString(line);
			file.Close();

			AfxMessageBox(_T("Hatırlatma notunuz kaydedildi!"));
		}
	}
}
