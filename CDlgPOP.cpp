// CDlgPOP.cpp: 实现文件
//

#include "pch.h"
#include "ManagerSys.h"
#include "afxdialogex.h"
#include "CDlgPOP.h"


// CDlgPOP 对话框

IMPLEMENT_DYNAMIC(CDlgPOP, CDialogEx)

CDlgPOP::CDlgPOP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGERSYS_DIALOG, pParent)
{

}

CDlgPOP::~CDlgPOP()
{
}

void CDlgPOP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPOP, CDialogEx)
END_MESSAGE_MAP()


// CDlgPOP 消息处理程序
