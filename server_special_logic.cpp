#include "server_special_logic.h"
#include <cstring>
#define INT_BYTES_AMOUNT (4)


char PONG[] = "PONG";
char UNKNOWN_COMMAND[] = "Unknown command";



ServerLogic::ServerLogic(ManageClient tech_other_computer)
{
    m_tech_other_computer = tech_other_computer;
}

void ServerLogic::sendDataServer(int received_len, char* recv_buffer)
{
    std::string str_recieved(recv_buffer, received_len);
    const char* char_recievied = str_recieved.c_str();
    if (strcmp("PING", char_recievied) == 0)
    {

        m_tech_other_computer.send_data(PONG);
    }
    else
    {
        m_tech_other_computer.send_data(UNKNOWN_COMMAND);
    }
    delete[] recv_buffer;
}


char* ServerLogic::recvDataServer(int* ptr_received_len)
{
    if (m_tech_other_computer.recv_data((char*)ptr_received_len, INT_BYTES_AMOUNT) != INT_BYTES_AMOUNT)
    {
        throw ClassServerLogicExceptions("error in recvDataServer func in length recieving");
        return NULL;
    }
    char* recv_buffer = new char[*ptr_received_len];
    if (*ptr_received_len != m_tech_other_computer.recv_data(recv_buffer, *ptr_received_len))
    {
        throw ClassServerLogicExceptions("error in recvDataServer function command recieving");
        return NULL;
    }
    return recv_buffer;
}
