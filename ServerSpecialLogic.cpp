#include "ServerSpecialLogic.h"
#include <cstring>
#include <iostream>
#define INT_BYTES_AMOUNT (4)

std::string PONG = "PONG";
std::string KNOWN_COMMAND = "PING";
int LEN_PONG = static_cast<int>(PONG.length());

ServerLogic::ServerLogic(ManageClient& m_techOtherComputer) : m_techOtherComputer(techOtherComputer)
{
}

void ServerLogic::sendDataServer(int receivedLen, char* recvBuffer)
{
    std::string strRecieved(recvBuffer, receivedLen);
    if (strcmp(KNOWN_COMMAND.c_str(), strRecieved.c_str()) == 0)
    {
        char* ptrLenPong = (char*)(&LEN_PONG);

        m_techOtherComputer.send_data(ptrLenPong, INT_BYTES_AMOUNT);
        m_techOtherComputer.send_data(PONG.c_str(), LEN_PONG);
    }
    else
    {
        throw ClassServerLogicExceptions("Unknown command");
    }
    delete[] recvBuffer;
}

char* ServerLogic::recvDataServer(int* ptrReceivedLen)
{
    if (m_techOtherComputer.recv_data((char*)ptrReceivedLen, INT_BYTES_AMOUNT) != INT_BYTES_AMOUNT)
    {
        throw ClassServerLogicExceptions("error in recvDataServer func in length recieving");
    }
    char* recvBuffer = new char[*ptrReceivedLen];
    if (*ptrReceivedLen != m_techOtherComputer.recv_data(recvBuffer, *ptrReceivedLen))
    {
        throw ClassServerLogicExceptions("error in recvDataServer function command recieving");
    }

    return recvBuffer;
}
