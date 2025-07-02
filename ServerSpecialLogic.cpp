#include "ServerSpecialLogic.h"
#include <cstring>
#include <iostream>
#include <vector>
#define INT_BYTES_AMOUNT (4)

std::string PONG = "PONG";
std::string KNOWN_COMMAND = "PING";
int LEN_PONG = static_cast<int>(PONG.length());
const int MAX_SIZE = 1024;

ServerLogic::ServerLogic(ManageClient& techOtherComputer) : m_techOtherComputer(techOtherComputer)
{
    // left blank intentionally
}

void ServerLogic::sendDataServer(int receivedLen, std::string recvBuffer)
{
    if (strcmp(KNOWN_COMMAND.c_str(), recvBuffer.c_str()) == 0)
    {
        char* ptrLenPong = (char*)(&LEN_PONG);

        m_techOtherComputer.send_data(ptrLenPong, INT_BYTES_AMOUNT);
        m_techOtherComputer.send_data(PONG.c_str(), LEN_PONG);
    }
    else
    {
        throw ClassServerLogicExceptions("Unknown command");
    }
}

std::string ServerLogic::recvDataServer(int* ptrReceivedLen)
{
    
    if (m_techOtherComputer.recv_data(reinterpret_cast<char*>(ptrReceivedLen), INT_BYTES_AMOUNT) != INT_BYTES_AMOUNT)
    {
        throw ClassServerLogicExceptions("error in recvDataServer func in length recieving");
    }
    std::vector<char> recvBuffer(MAX_SIZE);
    if (*ptrReceivedLen != m_techOtherComputer.recv_data(recvBuffer.data(), *ptrReceivedLen))
    {
        throw ClassServerLogicExceptions("error in recvDataServer function command recieving");
    }
    return std::string(recvBuffer.data(), *ptrReceivedLen);;
}
