#pragma once
#include "afxdialogex.h"


// NPOPDlg 对话框

class NPOPDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NPOPDlg)
	BOOL NPOPDlg::OnInitDialog()
	{
		CDialogEx::OnInitDialog();
		n_name.SetWindowText(nc_name); // 关键：首次弹出时同步内容
		return TRUE;
	}
public:
	NPOPDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NPOPDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NPOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnUpdateFields(WPARAM wParam, LPARAM lParam);
	void UpdateFields(); // 用于刷新控件
	CEdit n_major;
	CEdit n_grade;
	CEdit n_id;
	CEdit n_name;
	CString nc_name;
	CString nc_id;
	CString nc_grade;
	CString nc_major;
};
