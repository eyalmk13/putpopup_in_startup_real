#include "ClientManageSocket.h"

ManageClient::ManageClient(SOCKET socketToClient)
{
    m_socketToClient = socketToClient;
}

ManageClient::~ManageClient()
{
    closesocket(m_socketToClient);
}
int ManageClient::recv_data(char* recvbuf, int recvbuflen)
{

    int iResultRecv = recv(m_socketToClient, recvbuf, recvbuflen, 0);
    if (iResultRecv > 0)
    {
        return iResultRecv;
    }
    else if (iResultRecv == 0)
    {
        throw ClassManageClientExceptions("socket closed in other side");
    }
    throw ClassManageClientExceptions("error in receiving from client");
}

void ManageClient::send_data(const char* send_buff, int len)
{
    int iSendResult;

    iSendResult = send(m_socketToClient, send_buff, len, 0);

    if (iSendResult == SOCKET_ERROR)
    {
        throw ClassManageClientExceptions("send to client failed");
    }
}
