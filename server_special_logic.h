
#ifndef SPECIAL_H
#define SPECIAL_H
#include "client_manage_socket.h"

class ServerLogic
{
  public:
    ServerLogic(ManageClient tech_other_computer);
    void sendDataServer(int received_len, char* recv_buffer);
    char* recvDataServer(int* ptr_received_len);

  private:
      ManageClient m_tech_other_computer;
};

class ClassServerLogicExceptions : public std::exception
{
  private:
    std::string message;

  public:
    ClassServerLogicExceptions(const std::string& msg) : message(msg)
    {
    }

    // Override what() from std::exception
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

#endif