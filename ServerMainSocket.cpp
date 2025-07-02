
#include "ServerMainSocket.h"

#define DEFAULT_PORT "12345"

ServerSocket::ServerSocket(char* src_port)
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

    iResult = getaddrinfo(NULL, src_port, &hints, &m_ptr_result);
    if (iResult != 0)
    {
        throw ClassServerSocketyExceptions("getaddrinfo failed in ServerSocket func");
    }
    else
    {
        m_socket_listen = socket(m_ptr_result->ai_family, m_ptr_result->ai_socktype, m_ptr_result->ai_protocol);
    }
}
ServerSocket::~ServerSocket()
{
    if (m_socket_listen != INVALID_SOCKET)
    {
        closesocket(m_socket_listen);
    }

    if (m_client_socket != INVALID_SOCKET)
    {
        closesocket(m_client_socket);
    }
    if (m_ptr_result != nullptr)
    {
        freeaddrinfo(m_ptr_result);
    }
    WSACleanup();
}

SOCKET ServerSocket::getClientSocket()
{
    return m_client_socket;
}
void ServerSocket::bindServer()
{
    int iResult = bind(m_socket_listen, m_ptr_result->ai_addr, (int)m_ptr_result->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        throw ClassServerSocketyExceptions("something went wrong in bindServer");
    }
}

void ServerSocket::listenSocket()
{
    if (listen(m_socket_listen, SOMAXCONN) == SOCKET_ERROR)
    {
        throw ClassServerSocketyExceptions("something went wrong in listenSocket");
    }
}

void ServerSocket::acceptClient()
{
    m_client_socket = INVALID_SOCKET;

    m_client_socket = accept(m_socket_listen, NULL, NULL);
    if (m_client_socket == INVALID_SOCKET)
    {
        throw ClassServerSocketyExceptions("something went wrong in acceptClient");
    }
}
