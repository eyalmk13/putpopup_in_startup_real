#include "ClientManageSocket.h"
#define INTEGER_LENGTH (4)

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
    }
    throw ClassManageClientExceptions("error in receiving from client");
}

void ManageClient::send_data(const char* send_buff, int len)
{
    int iSendResult;

    iSendResult = send(m_socket_to_client, send_buff, len, 0);

    if (iSendResult == SOCKET_ERROR)
    {
        throw ClassManageClientExceptions("send to client failed");
    }
}
