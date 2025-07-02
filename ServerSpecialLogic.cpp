#include "ServerSpecialLogic.h"
#include <cstring>
#include <iostream>
#include <Windows.h>
#include <vector>
#define INT_BYTES_AMOUNT (4)

std::string PONG = "PONG";
std::string KNOWN_COMMAND = "PING";
std::string RUN_COMMAND = "RUN";
int LEN_PONG = static_cast<int>(PONG.length());
int LEN_RUN_COMMAND = static_cast<int>(RUN_COMMAND.length());

void run_path(std::string path)
{

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    int length = static_cast<int>(path.length());
    char* nullTerminatedPath = new char[length + 1];
    memcpy(nullTerminatedPath, path.c_str(), length);
    nullTerminatedPath[length] = '\0';
    LPCSTR exePath = nullTerminatedPath;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    BOOL success = CreateProcessA(exePath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    if (!success)
    {
        throw ClassServerLogicExceptions("CreateProcess func failed ");
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
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
    else if (received_len > LEN_RUN_COMMAND)
    {
        std::string slice_command(recv_buffer, LEN_RUN_COMMAND);
        if (strcmp(RUN_COMMAND.c_str(), slice_command.c_str()) == 0)
        {
            std::string exe_path(&recv_buffer[LEN_RUN_COMMAND + 1], received_len - LEN_RUN_COMMAND - 1);
            run_path(exe_path);
        }
    }
    else
    {
        delete[] recv_buffer;
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


