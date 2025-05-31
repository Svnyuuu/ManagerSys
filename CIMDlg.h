#pragma once
#include "afxdialogex.h"


// CIMDlg 对话框

class CIMDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIMDlg)

public:
	CIMDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CIMDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NPOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
