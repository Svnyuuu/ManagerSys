
// ManagerSysDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ManagerSys.h"
#include "ManagerSysDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
	CBitmap m_bmp;  // 这个必须声明为成员变量，不能是局部变量
	// 控件变量
	CStatic m_pic;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_pic);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CManagerSysDlg 对话框



CManagerSysDlg::CManagerSysDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGERSYS_DIALOG, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerSysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_pic);
}

BEGIN_MESSAGE_MAP(CManagerSysDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_PICTURE, &CManagerSysDlg::OnStnClickedPicture)
END_MESSAGE_MAP()


// CManagerSysDlg 消息处理程序

BOOL CManagerSysDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CManagerSysDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CManagerSysDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CManagerSysDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CManagerSysDlg::OnStnClickedPicture()
{
	//// 先释放之前的位图资源，防止内存泄漏
	//if (m_bmp.GetSafeHandle())
	//	m_bmp.DeleteObject();

	//// 从文件加载bmp
	//HBITMAP hbmp = (HBITMAP)::LoadImage(NULL, _T("D:\\Work\\Pito\\pito.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//if (hbmp == NULL)
	//{
	//	AfxMessageBox(_T("加载图片失败！"));
	//	return;
	//}

	//// 将HBITMAP绑定到成员变量，管理生命周期
	//m_bmp.Attach(hbmp);

	//// 设置控件显示位图
	//m_pic.SetBitmap(hbmp);
}
