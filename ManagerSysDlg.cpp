
// ManagerSysDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ManagerSys.h"
#include "ManagerSysDlg.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include <vector> // 添加此行以包含 std::vector 的定义

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
public:
	/*afx_msg void OnBnClickedButtonPopN();*/
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	/*ON_BN_CLICKED(IDC_BUTTON_POP_N, &CAboutDlg::OnBnClickedButtonPopN)*/
END_MESSAGE_MAP()



// 以上是“关于”对话框 不用管


// CManagerSysDlg 对话框



CManagerSysDlg::CManagerSysDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGERSYS_DIALOG, pParent)
	, m_age(0)
	, m_int(0)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pcimdlg = NULL;
}

void CManagerSysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_pic);
	//DDX_Control(pDX, IDC_EDIT_AGE, m_age);

	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Slider(pDX, IDC_SLIDER1, m_int);
	DDX_Control(pDX, IDC_GRADE, m_grade);
	DDX_Control(pDX, IDC_MAJOR, m_major);

	DDX_Control(pDX, IDC_EDIT_NAME, m_nameEdit);
	DDX_Control(pDX, IDC_EDIT_ID, m_idEdit);
	DDX_Control(pDX, IDC_EDIT_IP, m_ipEdit);
	DDX_Control(pDX, IDC_EDIT_MAC, m_phyAddrEdit);
	DDX_Control(pDX, IDC_EDIT_MASK, m_subnetEdit);
	DDX_Control(pDX, IDC_EDIT_PREF, m_politicsEdit);
	DDX_Control(pDX, IDC_EDIT_CONTACT, m_contactEdit);
	DDX_Control(pDX, IDC_MALE, m_radioMale);
	DDX_Control(pDX, IDC_FEMALE, m_radioFemale);

}

BEGIN_MESSAGE_MAP(CManagerSysDlg, CDialogEx)
	//ON_WM_SYSCOMMAND()
	//ON_WM_PAINT()
	//ON_WM_QUERYDRAGICON()
	//ON_STN_CLICKED(IDC_PICTURE, &CManagerSysDlg::OnStnClickedPicture)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CManagerSysDlg::OnNMCustomdrawProgress1)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_AGE, &CManagerSysDlg::OnNMCustomdrawSliderAge)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_GRADE, &CManagerSysDlg::OnCbnSelchangeGrade)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CManagerSysDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CManagerSysDlg::OnBnClickedSaveFile)
	ON_BN_CLICKED(IDC_BUTTON_POP_N, &CManagerSysDlg::OnBnClickedButtonPopN)
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


	// 年龄滑块
	m_slider.SetRange(10, 80);
	//每十个单位画一个刻度
	m_slider.SetTicFreq(1);
	//设置初始位置
	int Start = 20;
	m_slider.SetPos(Start);//滚动条初始位置
	SetDlgItemInt(IDC_EDIT_AGE, Start);//设置编辑框的初始值


	// 年级下拉框
	m_grade.AddString(_T("2021级"));
	m_grade.AddString(_T("2022级"));
	m_grade.AddString(_T("2023级"));
	m_grade.AddString(_T("2024级"));




	// 专业下拉框
	m_major.AddString(_T("计算机科学与技术"));
	m_major.AddString(_T("软件工程"));
	m_major.AddString(_T("信息安全"));
	m_major.AddString(_T("网络工程"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CManagerSysDlg::OnSysCommand(UINT nID, LPARAM lParam) // 处理系统命令
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



// 
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


void CManagerSysDlg::OnCbnSelchangeGrade()
{
	// TODO: 在此添加控件通知处理程序代码
}


// txt部分

void CManagerSysDlg::OnBnClickedButtonOpen()
{
	CFileDialog dlg(TRUE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		_T("Text Files (*.txt)|*.txt||"), this);

	if (dlg.DoModal() == IDOK)
	{
		CString pathName = dlg.GetPathName();
		CFile file;
		if (file.Open(pathName, CFile::modeRead | CFile::typeBinary))
		{
			ULONGLONG fileLen = file.GetLength();
			if (fileLen == 0) return;

			// 读取全部内容
			std::vector<BYTE> buffer((size_t)fileLen);
			file.Read(buffer.data(), (UINT)fileLen);
			file.Close();

			// 跳过UTF-8 BOM
			int offset = 0;
			if (fileLen >= 3 && buffer[0] == 0xEF && buffer[1] == 0xBB && buffer[2] == 0xBF)
				offset = 3;

			// 转为CString
			CString content = CA2W((LPCSTR)(buffer.data() + offset), CP_UTF8);

			// 按行分割
			int pos = 0, lineIndex = 0;
			CString line = content.Tokenize(_T("\n"), pos);
			while (!line.IsEmpty())
			{
				line.Trim();
				switch (lineIndex)
				{
				case 0: m_nameEdit.SetWindowText(line); break;
				case 1: m_idEdit.SetWindowText(line); break;
				case 2: m_ipEdit.SetWindowText(line); break;
				case 3: m_phyAddrEdit.SetWindowText(line); break;
				case 4: m_subnetEdit.SetWindowText(line); break;
				case 5: m_politicsEdit.SetWindowText(line); break;
				case 6: m_contactEdit.SetWindowText(line); break;
				case 7:
				{
					int index = m_grade.FindStringExact(-1, line);
					if (index != CB_ERR)
						m_grade.SetCurSel(index);
				}
				break;
				case 8:
				{
					int index = m_major.FindStringExact(-1, line);
					if (index != CB_ERR)
						m_major.SetCurSel(index);
				}
				case 9:
					if (line == _T("男")) {
						m_radioMale.SetCheck(BST_CHECKED);
						m_radioFemale.SetCheck(BST_UNCHECKED);
					}
					else if (line == _T("女")) {
						m_radioMale.SetCheck(BST_UNCHECKED);
						m_radioFemale.SetCheck(BST_CHECKED);
					}
				break;
				case 10: m_age = _ttoi(line);
					m_slider.SetPos(m_age);
					SetDlgItemInt(IDC_EDIT_AGE, m_age);
					break;

				}
				lineIndex++;
				line = content.Tokenize(_T("\n"), pos);
			}
		}
	}

}


void CManagerSysDlg::OnBnClickedSaveFile()
{
	CString name, id, ip, phy, subnet, politics, contact;
	m_nameEdit.GetWindowText(name);
	m_idEdit.GetWindowText(id);
	m_ipEdit.GetWindowText(ip);
	m_phyAddrEdit.GetWindowText(phy);
	m_subnetEdit.GetWindowText(subnet);
	m_politicsEdit.GetWindowText(politics);
	m_contactEdit.GetWindowText(contact);

	CString grade, major;
	m_grade.GetLBText(m_grade.GetCurSel(), grade);
	m_major.GetLBText(m_major.GetCurSel(), major);

	int age = m_slider.GetPos();
	CString gender = m_radioMale.GetCheck() ? _T("男") : _T("女");

	CString path = _T("D:\\Work\\Files\\junior_d\\socket\\ManagerSys\\aaa\\info.txt");

	// 拼接所有内容
	CString content;
	content.Format(_T("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n"),
		name, id, ip, phy, subnet, politics, contact, grade, major, gender, age);

	// 转为UTF-8编码
	CT2CA utf8Str(content, CP_UTF8);

	CFile file;
	if (file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
	{
		// 写入UTF-8 BOM
		BYTE bom[] = { 0xEF, 0xBB, 0xBF };
		file.Write(bom, 3);
		// 写入UTF-8内容
		file.Write(utf8Str, (UINT)strlen(utf8Str));
		file.Close();
	}
}



//void CManagerSysDlg::OnBnClickedButtonPopN()
//{
//	CString name, id, grade, major;
//	GetDlgItemText(IDC_EDIT_NAME, name);
//	GetDlgItemText(IDC_EDIT_ID, id);
//	m_grade.GetLBText(m_grade.GetCurSel(), grade);
//	m_major.GetLBText(m_major.GetCurSel(), major);
//
//	if (m_pcimdlg == NULL) {
//		m_pcimdlg = new NPOPDlg();
//		m_pcimdlg->nc_name = name;
//		m_pcimdlg->nc_id = id;
//		m_pcimdlg->nc_grade = grade;
//		m_pcimdlg->nc_major = major;
//		m_pcimdlg->Create(IDD_DIALOG_NPOP, this);
//
//		m_pcimdlg->n_name.SetWindowText(name);
//		m_pcimdlg->n_id.SetWindowText(id);
//		m_pcimdlg->n_grade.SetWindowText(grade);
//		m_pcimdlg->n_major.SetWindowText(major);
//	}
//	else {
//		m_pcimdlg->nc_name = name;
//		m_pcimdlg->n_name.SetWindowText(name);
//		m_pcimdlg->nc_id = id;
//		m_pcimdlg->n_id.SetWindowText(id);
//		m_pcimdlg->nc_grade = grade;
//		m_pcimdlg->n_grade.SetWindowText(grade);
//		m_pcimdlg->nc_major = major;
//		m_pcimdlg->n_major.SetWindowText(major);
//	}
//
//	m_pcimdlg->ShowWindow(SW_SHOW);
//}

void CManagerSysDlg::OnBnClickedButtonPopN()
{
	CString name, id, grade, major;
	GetDlgItemText(IDC_EDIT_NAME, name);
	GetDlgItemText(IDC_EDIT_ID, id);
	m_grade.GetLBText(m_grade.GetCurSel(), grade);
	m_major.GetLBText(m_major.GetCurSel(), major);

	if (m_pcimdlg == NULL) {
		m_pcimdlg = new NPOPDlg();
		m_pcimdlg->Create(IDD_DIALOG_NPOP, this);
	}

	// 无论是否第一次，都赋值并刷新
	m_pcimdlg->nc_name = name;
	m_pcimdlg->nc_id = id;
	m_pcimdlg->nc_grade = grade;
	m_pcimdlg->nc_major = major;

	// 立即刷新控件显示
	m_pcimdlg->UpdateFields();

	// 显示窗口
	m_pcimdlg->ShowWindow(SW_SHOW);
}
