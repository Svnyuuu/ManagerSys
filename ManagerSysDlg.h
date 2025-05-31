
// ManagerSysDlg.h: 头文件
//

#pragma once


// CManagerSysDlg 对话框
class CManagerSysDlg : public CDialogEx
{
// 构造
public:
	CManagerSysDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGERSYS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedPicture();
	CStatic m_pic;

private:
	CBitmap m_bmp; // 添加这一行用于管理图片资源

public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	// void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_age;
private:
	CSliderCtrl m_slider;
	int m_int;
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
