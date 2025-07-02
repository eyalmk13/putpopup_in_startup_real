#include "ServerSpecialLogic.h"
#include <cstring>
#include <iostream>
#include <Windows.h>
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

ServerLogic::ServerLogic(ManageClient& tech_other_computer) : m_tech_other_computer(tech_other_computer)
{
}

void ServerLogic::sendDataServer(int received_len, char* recv_buffer)
{
    std::string str_recieved(recv_buffer, received_len);
    if (strcmp(KNOWN_COMMAND.c_str(), str_recieved.c_str()) == 0)
    {
        char* ptr_len_pong = (char*)(&LEN_PONG);

        m_tech_other_computer.send_data(ptr_len_pong, INT_BYTES_AMOUNT);
        m_tech_other_computer.send_data(PONG.c_str(), LEN_PONG);
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
    delete[] recv_buffer;
}

char* ServerLogic::recvDataServer(int* ptr_received_len)
{
    if (m_tech_other_computer.recv_data((char*)ptr_received_len, INT_BYTES_AMOUNT) != INT_BYTES_AMOUNT)
    {
        throw ClassServerLogicExceptions("error in recvDataServer func in length recieving");
    }
    char* recv_buffer = new char[*ptr_received_len];
    if (*ptr_received_len != m_tech_other_computer.recv_data(recv_buffer, *ptr_received_len))
    {
        throw ClassServerLogicExceptions("error in recvDataServer function command recieving");
    }

    return recv_buffer;
}


