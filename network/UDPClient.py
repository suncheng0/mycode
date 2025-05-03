from socket import *

from envs.pytorch.Tools.scripts.treesync import raw_input

serverName = '127.0.0.1'#IP地址
serverPort = 12000     #port
clientSocket = socket(AF_INET, SOCK_DGRAM)#创建套接字（ipv4,套接字类型UDP）
messsage=raw_input('Input lowercase sentence:')#提醒用户输入报文
clientSocket.sendto(messsage.encode(), (serverName, serverPort))#encode将报文从字符串变成字节 sendto为报文夫加上目的地址并发送
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)#接受报文，存到modifiedMessage 源地址IP和port存在serverAddress 缓存长度2048
print(modifiedMessage.decode())#将报文转换成字符串并且打印
clientSocket.close()#关闭socket