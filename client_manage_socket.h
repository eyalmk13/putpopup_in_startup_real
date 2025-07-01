#ifndef CLIENT_SOCK_H
#define CLIENT_SOCK_H
#include <Windows.h>
#include <exception>
#include <iostream>
#include <string>

#define DEFAULT_BUFLEN (1024)

class ManageClient
{
  public:
    ManageClient(SOCKET socket_to_client);
    ~ManageClient();
    int recv_data(char* recvbuf, int recvbuflen);
    void send_data(char *send);

  private:
    SOCKET m_socket_to_client = NULL;
};

class ClassManageClientExceptions : public std::exception
{
  private:
    std::string message;

  public:
    ClassManageClientExceptions(const std::string& msg) : message(msg)
    {
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};
#endif