﻿
// JYDlg.h: 头文件
//

#pragma once


// CJYDlg 对话框
class CJYDlg : public CDialogEx
{
// 构造
public:
	CJYDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton2();
};
