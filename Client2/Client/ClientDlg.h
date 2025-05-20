
// ClientDlg.h: 头文件
//

#pragma once
#include"ClientSocket.h"
#include<afxwin.h>

// CClientDlg 对话框
class CClientDlg : public CDialogEx
{
// 构造
public:
	CClientDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
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
	ClientSocket* m_ClientSocket  = new ClientSocket;
	CIPAddressCtrl m_IP;
	CString m_Port;
	afx_msg void OnInternectConnect();
	afx_msg void OnInternectBreak();
	afx_msg void OnMessageSend();
	afx_msg void OnInternectQuit();
	CListBox m_Message;
	CString m_Word;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_Connect;
	CButton m_Break;
	CButton m_SendClean;
	CButton m_SendMessage;
	CButton m_RecordClean;
	CEdit m_SendWord;
	afx_msg void OnBnSendClean();
	afx_msg void OnBnRecordClean();
	CEdit m_ControlPort;
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR* pNMHDR, LRESULT* pResult);
};
