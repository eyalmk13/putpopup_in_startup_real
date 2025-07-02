#include "ServerMainSocket.h"

ServerSocket::ServerSocket(std::string srcPort)
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        throw ClassServerSocketyExceptions("WSAStartup failed in ServerSocket func");
    }

    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, srcPort.c_str(), &hints, &m_ptrResult);
    if (iResult != 0)
    {
        throw ClassServerSocketyExceptions("getaddrinfo failed in ServerSocket func");
    }
    else
    {
        m_socketListen = socket(m_ptrResult->ai_family, m_ptrResult->ai_socktype, m_ptrResult->ai_protocol);
    }
}
ServerSocket::~ServerSocket()
{
    if (m_socketListen != INVALID_SOCKET)
    {
        closesocket(m_socketListen);
    }

    if (m_clientSocket != INVALID_SOCKET)
    {
        closesocket(m_clientSocket);
    }
    if (m_ptrResult != nullptr)
    {
        freeaddrinfo(m_ptrResult);
    }
    WSACleanup();
}

SOCKET ServerSocket::getClientSocket()
{
    return m_clientSocket;
}
void ServerSocket::bindServer()
{
    int iResult = bind(m_socketListen, m_ptrResult->ai_addr, (int)m_ptrResult->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        throw ClassServerSocketyExceptions("something went wrong in bindServer");
    }
}

void ServerSocket::listenSocket()
{
    if (listen(m_socketListen, SOMAXCONN) == SOCKET_ERROR)
    {
        throw ClassServerSocketyExceptions("something went wrong in listenSocket");
    }
}

void ServerSocket::acceptClient()
{
    m_clientSocket = INVALID_SOCKET;

    m_clientSocket = accept(m_socketListen, NULL, NULL);
    if (m_clientSocket == INVALID_SOCKET)
    {
        throw ClassServerSocketyExceptions("something went wrong in acceptClient");
    }
}
