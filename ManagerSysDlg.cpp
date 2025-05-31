
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
	, m_age(0)
	, m_int(0)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerSysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_pic);
	//DDX_Control(pDX, IDC_EDIT_AGE, m_age);

	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Slider(pDX, IDC_SLIDER1, m_int);
}

BEGIN_MESSAGE_MAP(CManagerSysDlg, CDialogEx)
	//ON_WM_SYSCOMMAND()
	//ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
	//ON_STN_CLICKED(IDC_PICTURE, &CManagerSysDlg::OnStnClickedPicture)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CManagerSysDlg::OnNMCustomdrawProgress1)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_AGE, &CManagerSysDlg::OnNMCustomdrawSliderAge)
	ON_WM_HSCROLL()
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
	// 进度条
	CProgressCtrl* pProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1); // 获取进度条控件指针
	pProgress->ModifyStyle(0, PBS_MARQUEE); // 将进度条样式修改为 PBS_MARQUEE marquee：
	pProgress->SetMarquee(TRUE, 25); // 设置为滚动模式，速度为 25 毫秒


	//// slider
	//// 获取 Slider 控件指针
	//CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_AGE);
	//// 设置范围为 0 到 80
	//pSlider->SetRange(0, 80);
	//// 设置初始位置
	//pSlider->SetPos(0);
	//// 显示刻度线（模拟 Auto Ticks 效果）
	//pSlider->SetTicFreq(10);  // 每隔10显示一个刻度
	 //设置滚动条滚动范围
	m_slider.SetRange(0, 100);
	//每十个单位画一个刻度
	m_slider.SetTicFreq(10);
	//设置初始位置
	int Start = 80;
	m_slider.SetPos(Start);//滚动条初始位置
	SetDlgItemInt(IDC_EDIT_AGE, Start);//设置编辑框的初始值



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
}

// 不确定进度加载
void CManagerSysDlg::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{ 
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}


//void CManagerSysDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
//	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_AGE);
//
//	if ((CScrollBar*)pSlider == pScrollBar)
//	{
//		m_age = pSlider->GetPos();  // 获取滑块值，赋给绑定变量
//		UpdateData(FALSE);          // 将 m_age 写入界面上的 Edit 控件
//	}
//
//	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
//}


void CManagerSysDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	//获取当前位置值，放在变量m_int中
	m_int = m_slider.GetPos();
	//内容设置到编辑框中，编辑框的ID是IDC_EDIT1
	SetDlgItemInt(IDC_EDIT_AGE, m_int);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
