#include "server_special_logic.h"
#include <cstring>
#include <iostream>
#define INT_BYTES_AMOUNT (4)

char PONG[] = "PONG";
int LEN_PONG = static_cast<int>(strlen(PONG));
char UNKNOWN_COMMAND[] = "Unknown command";
int LEN_UNKNOWN_COMMAND = static_cast<int>(strlen(UNKNOWN_COMMAND));

ServerLogic::ServerLogic(ManageClient& tech_other_computer) : m_tech_other_computer(tech_other_computer)
{
}

void ServerLogic::sendDataServer(int received_len, char* recv_buffer)
{
    std::string str_recieved(recv_buffer, received_len);
    const char* char_recievied = str_recieved.c_str();
    if (strcmp("PING", char_recievied) == 0)
    {
        char* ptr_len_pong = (char*)(&LEN_PONG);
        m_tech_other_computer.send_data(ptr_len_pong, INT_BYTES_AMOUNT);
        m_tech_other_computer.send_data(PONG, LEN_PONG);
    }
    else
    {
        char* ptr_len_unkown_command = (char*)(&LEN_UNKNOWN_COMMAND);
        m_tech_other_computer.send_data(ptr_len_unkown_command, INT_BYTES_AMOUNT);
        m_tech_other_computer.send_data(UNKNOWN_COMMAND, LEN_UNKNOWN_COMMAND);
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
