#pragma once
#include "afxdialogex.h"


// CDlgPOP 对话框

class CDlgPOP : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPOP)

public:
	CDlgPOP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgPOP();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGERSYS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
