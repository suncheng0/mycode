// ClientSocket.cpp: 实现文件
//

#include "pch.h"
#include "Client.h"
#include "ClientSocket.h"
#include"ClientDlg.h"

// ClientSocket

ClientSocket::ClientSocket()
{
}

ClientSocket::~ClientSocket()
{
}


// ClientSocket 成员函数


void ClientSocket::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
    if (nErrorCode)
    {
        AfxMessageBox(_T("网络连接失败"));
        return;
    }

    ((CClientDlg*)(AfxGetApp()->m_pMainWnd))->m_Message.AddString(_T("网络连接成功"));
    ((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.SetTopIndex(((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.GetCount() + 1);

    CAsyncSocket::OnConnect(nErrorCode);
}


void ClientSocket::OnClose(int nErrorCode)
{
    // TODO: 在此添加专用代码和/或调用基类
    ((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.AddString(_T("服务器端断开连接"));
    ((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.SetTopIndex(((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.GetCount() - 1);

    CAsyncSocket::OnClose(nErrorCode);
}


void ClientSocket::OnReceive(int nErrorCode)
{
    // TODO: 在此添加专用代码和/或调用基类
    char RBYTE[200] = { NULL };
    CString RWord;
    int n = Receive(RBYTE, 200);
    RBYTE[n] = _T('\0');
    RWord.Format(_T("收到:%s"), RBYTE);

    ((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.AddString(RWord);
    ((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.SetTopIndex(((CClientDlg*)AfxGetApp()->m_pMainWnd)->m_Message.GetCount() - 1);

    CAsyncSocket::OnReceive(nErrorCode);

}
