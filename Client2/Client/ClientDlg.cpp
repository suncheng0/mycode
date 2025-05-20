
// ClientDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"
#include"Resource.h"



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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientDlg 对话框



CClientDlg::CClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_DIALOG, pParent)
	, m_Port(_T(""))
	, m_Word(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Port);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IP);
	DDX_Control(pDX, IDC_LIST1, m_Message);
	DDX_Control(pDX, IDC_BUTTON7, m_Connect);
	DDX_Control(pDX, IDC_BUTTON8, m_Break);
	DDX_Control(pDX, IDC_BUTTON10, m_SendClean);
	DDX_Control(pDX, IDC_BUTTON3, m_SendMessage);
	DDX_Control(pDX, IDC_BUTTON1, m_RecordClean);
	DDX_Control(pDX, IDC_EDIT3, m_SendWord);
	DDX_Text(pDX, IDC_EDIT3, m_Word);
	DDX_Control(pDX, IDC_EDIT2, m_ControlPort);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON7, &CClientDlg::OnInternectConnect)
	ON_BN_CLICKED(IDC_BUTTON8, &CClientDlg::OnInternectBreak)
	ON_BN_CLICKED(IDC_BUTTON3, &CClientDlg::OnMessageSend)
	ON_BN_CLICKED(IDC_BUTTON9, &CClientDlg::OnInternectQuit)
	ON_BN_CLICKED(IDC_BUTTON10, &CClientDlg::OnBnSendClean)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnRecordClean)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &CClientDlg::OnIpnFieldchangedIpaddress1)
END_MESSAGE_MAP()


HBRUSH CClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDC_LIST1)
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(255, 255, 255));
		hbr = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	}

	return hbr;
}
// CClientDlg 消息处理程序


BOOL CClientDlg::OnInitDialog()
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
	//
	//SETIP[0] = 127;
	//SETIP[1] = 0;
	//SETIP[2] = 0;
	//SETIP[3] = 1;
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint()
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CSocket sock;


void CClientDlg::OnInternectConnect()
{
	BYTE IPADDRESS[4];
	CString IpString;
	UINT port;
	UpdateData(TRUE);
	port = _ttoi(m_Port);  //把端口数据转换成整形变量
	m_IP.GetAddress(IPADDRESS[0], IPADDRESS[1], IPADDRESS[2], IPADDRESS[3]);  //获取IP地址
	if (!(m_IP.IsBlank()))  //判断是否有输入IP地址
	{
		IpString.Format(_T("%d.%d.%d.%d"), IPADDRESS[0], IPADDRESS[1], IPADDRESS[2], IPADDRESS[3]);  //把IP地址转换成字符串类型
		m_ClientSocket->Create();  //创建Socket
		m_ClientSocket->Connect(IpString, port);  //连接网络

		m_Break.EnableWindow(TRUE);  //使断开按键有效
		m_SendMessage.EnableWindow(TRUE); //使发送按键有效
		m_Connect.EnableWindow(FALSE);  //使连接按键失效
		m_IP.EnableWindow(FALSE);  //使IP控件输入无效
		m_ControlPort.EnableWindow(FALSE);  //使断开无效
	}

	//CButton *cbutton = (CButton*)GetDlgItem(IDC_CONNECT);
	//HWND hbutton = cbutton->GetSafeHwnd();
	CDC* buttonpdc = GetDlgItem(IDC_CONNECT)->GetDC();
	buttonpdc->SetBkMode(TRANSPARENT);
	buttonpdc->SetBkColor(RGB(255, 0, 0));
	ReleaseDC(buttonpdc);
	
	
	
}




void CClientDlg::OnInternectBreak()
{
	// TODO: 在此添加控件通知处理程序代码
	 // TODO: 在此添加控件通知处理程序代码

	m_ClientSocket->Close();  //断开网络连接

	m_IP.EnableWindow(TRUE);  //使IP控件有效
	m_ControlPort.EnableWindow(TRUE);  //使断开有效
	m_Connect.EnableWindow(TRUE);  //使连接按键有效
	m_Message.AddString(_T("已断开连接"));
	m_Message.SetTopIndex(m_Message.GetCount() - 1);

}


void CClientDlg::OnMessageSend()
{
	// TODO: 在此添加控件通知处理程序代码
	 // TODO: 在此添加控件通知处理程序代码
	CString sendmessage;
	UpdateData(TRUE);

	if (m_Word.GetLength() != 0)  //判断发送信息框是否有信息要发送
	{
		m_ClientSocket->Send(m_Word, 2 * m_Word.GetLength()); //发送信息
		sendmessage.Format(_T("发送:%s"), m_Word);
		m_Message.AddString(sendmessage);
		m_Message.SetTopIndex(m_Message.GetCount() - 1);
	}

}


void CClientDlg::OnInternectQuit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ClientSocket->Close();  //退出网络连接
	CDialog::OnCancel();
}



void CClientDlg::OnBnSendClean()
{
	// TODO: 在此添加控件通知处理程序代码
	m_SendWord.SetWindowTextW(_T(""));  //清除发送框内容
}


void CClientDlg::OnBnRecordClean()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Message.ResetContent();  //清除列表框内容
}


void CClientDlg::OnIpnFieldchangedIpaddress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
