#ifndef SOCKET_H
#define SOCKET_H
#include <Windows.h>
#include <exception>
#include <iostream>
#include <string>

class ServerSocket
{
  public:
    ServerSocket(char* src_port);
    ~ServerSocket();
    void bindServer();
    void listenSocket();
    void acceptClient();
    SOCKET getClientSocket();


  private:
    SOCKET m_socket_listen = NULL;
    SOCKET m_client_socket = NULL;
    struct addrinfo** m_ptr_result = NULL;
};


class ClassServerSocketyExceptions : public std::exception
{
  private:
    std::string message;

  public:
    ClassServerSocketyExceptions(const std::string& msg) : message(msg)
    {
    }

    // Override what() from std::exception
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

#endif