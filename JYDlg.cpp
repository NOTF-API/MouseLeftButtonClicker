
// JYDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "JY.h"
#include "JYDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJYDlg 对话框



CJYDlg::CJYDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_JY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CJYDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CJYDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CJYDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK3, &CJYDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK2, &CJYDlg::OnBnClickedCheck2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CJYDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CJYDlg::OnNMCustomdrawSlider2)
	ON_BN_CLICKED(IDC_BUTTON2, &CJYDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CJYDlg 消息处理程序

BOOL CJYDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CSliderCtrl* pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	CSliderCtrl* pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
	pSlidCtrl1->SetPos(10);
	pSlidCtrl2->SetPos(10);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CJYDlg::OnPaint()
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

int s = 0;

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CJYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int st1 = 20;
int st2 = 20;
void T1();
void T2();
void T3();
HANDLE fun1Thread = NULL;
HANDLE fun2Thread = NULL;
HANDLE fun3Thread = NULL;

void CJYDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	if (state == 0) {
		if (fun1Thread != NULL) {
			TerminateThread(fun1Thread,0);
			fun1Thread = NULL;
		}
	}
	else if (state == 1) {
		if (fun1Thread == NULL) {
			fun1Thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T1, (LPVOID)NULL, 0, NULL);
		}
	}
}

void CJYDlg::OnBnClickedCheck2()
{

	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	if (state == 0) {
		if (fun2Thread != NULL) {
			TerminateThread(fun2Thread, 0);
			fun2Thread = NULL;
		}
	}
	else if (state == 1) {
		if (fun2Thread == NULL) {
			fun2Thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T2, (LPVOID)NULL, 0, NULL);
		}
	}
}

void CJYDlg::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	if (state == 0) {
		if (fun3Thread != NULL) {
			TerminateThread(fun3Thread, 0);
			fun3Thread = NULL;
		}
	}
	else if (state == 1) {
		if (fun3Thread == NULL) {
			fun3Thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T3, (LPVOID)NULL, 0, NULL);
		}
	}
}

void T1() {
	while (1) {
		if (GetKeyState(VK_XBUTTON2) < 0) {
			while (1) {
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(st1);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(st2);
				if (!(GetKeyState(VK_XBUTTON2) < 0))break;
			}
		}
	}
}

void T2() {
	while (1) {
		if (GetKeyState(VK_MBUTTON) < 0) {
			while (1) {
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(st1);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(st2);
				if (!(GetKeyState(VK_MBUTTON) < 0))break;
			}
		}
	}
}

void T3() {
	while (1) {
		if (GetKeyState(VK_XBUTTON1) < 0) {
			while (1) {
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(st1);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(st2);
				if (!(GetKeyState(VK_XBUTTON1) < 0))break;
			}
		}
	}
}

void CJYDlg::OnBnClickedButton1()
{
	s++;
	CString tempPort;
	tempPort.Format(_T("%d"), s);
	GetDlgItem(IDC_BUTTON1)->SetWindowTextW(tempPort);
}

void CJYDlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CSliderCtrl* pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	st1 = pSlidCtrl->GetPos() * 2;
	st1 = st1 <= 0 ? 1 : st1;
	CString c;
	c.Format(_T("%d"), st1);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(c);
}


void CJYDlg::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CSliderCtrl* pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
	st2 = pSlidCtrl->GetPos() * 2;
	st2 = st2 <= 0 ? 1 : st2;
	CString c;
	c.Format(_T("%d"), st2);
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(c);
}


void CJYDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CSliderCtrl* pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	CSliderCtrl* pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
	pSlidCtrl1->SetPos(10);
	pSlidCtrl2->SetPos(10);
	st1 = 20;
	st2 = 20;
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(TEXT("20"));
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(TEXT("20"));
}
