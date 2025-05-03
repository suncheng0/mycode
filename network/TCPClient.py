from socket import *

from envs.pytorch.Tools.scripts.treesync import raw_input

serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)#创建用户套接字（IPV4，TCP）
clientSocket.connect((serverName, serverPort))#三次握手进行连接
sentence = raw_input('Input lowercase sentence: ')
clientSocket.send(sentence.encode())#发送字符串
modifiedSentence = clientSocket.recv(1024)
print('From server:', modifiedSentence.decode())
clientSocket.close()
