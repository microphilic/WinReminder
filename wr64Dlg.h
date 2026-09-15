
// wr64Dlg.h: üst bilgi dosyası
//

#pragma once


// Cwr64Dlg iletişim kutusu
class Cwr64Dlg : public CDialogEx
{
// Oluşturma
public:
	Cwr64Dlg(CWnd* pParent = nullptr);	// standart oluşturucu

// İletişim Kutusu Verileri
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WR64_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV desteği


// Uygulama
protected:
	HICON m_hIcon;

	// Oluşturulan ileti eşlemesi işlevleri
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// String variable for task notes
	CString m_strTask;
	// Date/Time variable for remind
	COleDateTime m_selectedDate;
	afx_msg void OnMcnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
};
