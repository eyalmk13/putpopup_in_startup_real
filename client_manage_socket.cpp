#pragma comment(lib, "Ws2_32.lib")
#include "client_manage_socket.h"
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>


ManageClient::ManageClient(SOCKET socket_to_client)
{
    m_socket_to_client = socket_to_client;
}

ManageClient::~ManageClient()
{
    closesocket(m_socket_to_client);
    
}
int ManageClient::recv_data(char* recvbuf, int recvbuflen)
{

    int iResult_recv = recv(m_socket_to_client, recvbuf, recvbuflen, 0);
    if (iResult_recv > 0)
    {
        return iResult_recv;
    }
    else if (iResult_recv == 0)
    {
        throw ClassManageClientExceptions("socket closed in other side");
        return 0;
    }
    throw ClassManageClientExceptions("error in receiving from client");
    return 0;
}

void ManageClient::send_data(char *send_buff)
{
    int len = strlen(send_buff);
    int iSendResult;
    iSendResult = send(m_socket_to_client, send_buff, len, 0);
    if (iSendResult == SOCKET_ERROR)
    {
        throw ClassManageClientExceptions("send to client failed");
    }

}
