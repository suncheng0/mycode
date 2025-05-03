from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))#serverPort是欢迎套接字
serverSocket.listen(1)#请求链接的最大用户数为1
print('The server is ready to receive')
while True:
    clientSocket, clientAddress = serverSocket.accept()#创建连接套接字，该客户专用
    sentence = clientSocket.recv(1024).decode()
    capitalizedSentence = sentence.upper()
    clientSocket.send(capitalizedSentence.encode())
    clientSocket.close()