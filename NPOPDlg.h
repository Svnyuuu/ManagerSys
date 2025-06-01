#pragma once
#include "afxdialogex.h" 


// NPOPDlg 对话框

class NPOPDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NPOPDlg) // 声明动态类
public:
	NPOPDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NPOPDlg();
	enum { IDD = IDD_DIALOG_NPOP };
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
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NPOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

};



