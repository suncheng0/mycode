from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))#将端口号12000与服务器的套接字绑定在一起
print("the server is ready to receive")
while True:#无限期等待接收来自用户的分组
    message, clientAddress = serverSocket.recvfrom(2048)#等待分组 数据放在message 用户IP和port放在clientAddress
    modifiedMessage = message.decode().upper()#把服务器接收到的报文转换成大写
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)#将用户的地址和端口附加到报文上从服务器套接字推出去