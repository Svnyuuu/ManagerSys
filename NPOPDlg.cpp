// NPOPDlg.cpp: 实现文件
//

#include "pch.h"
#include "ManagerSys.h"
#include "afxdialogex.h"
#include "NPOPDlg.h"


// NPOPDlg 对话框

IMPLEMENT_DYNAMIC(NPOPDlg, CDialogEx)

NPOPDlg::NPOPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NPOP, pParent)
	, nc_name(_T(""))
	, nc_id(_T(""))
	, nc_grade(_T(""))
	, nc_major(_T(""))
{

}

NPOPDlg::~NPOPDlg()
{
}

void NPOPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT4, n_major);
	DDX_Control(pDX, IDC_EDIT3, n_grade);
	DDX_Control(pDX, IDC_EDIT2, n_id);
	DDX_Control(pDX, IDC_EDIT1, n_name);
	DDX_Text(pDX, IDC_EDIT1, nc_name);
	DDX_Text(pDX, IDC_EDIT2, nc_id);
	DDX_Text(pDX, IDC_EDIT3, nc_grade);
	DDX_Text(pDX, IDC_EDIT4, nc_major);
}


//BEGIN_MESSAGE_MAP(NPOPDlg, CDialogEx)
//END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(NPOPDlg, CDialogEx)
	ON_MESSAGE(WM_USER + 1, &NPOPDlg::OnUpdateFields)
END_MESSAGE_MAP()

LRESULT NPOPDlg::OnUpdateFields(WPARAM, LPARAM)
{
	UpdateFields();
	return 0;
}

// NPOPDlg 消息处理程序
