#pragma once

// ClientSocket 命令目标

class ClientSocket : public CAsyncSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();
	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	
};



