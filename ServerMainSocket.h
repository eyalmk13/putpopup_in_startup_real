#pragma once
#include <exception>
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

class ServerSocket
{
    /*
    manages a classic server listening
    */
  public:
    /*
    constructor of class
    :param srcPort: the port to listen from as a server
    */
    ServerSocket(std::string srcPort);
    /*
    destroyer of class
    frees addr info data and does WSACleanup.
    */
    ~ServerSocket();
    /*
    binds the server
    */
    void bindServer();
    /*
    makes the server to listen to clients
    */
    void listenSocket();
    /*
    makes the server to accepets a client
    */
    void acceptClient();
    /*
    gets the socket the server is in contact with a client
    :return: m_clientSocket
    */
    SOCKET getClientSocket();

  private:
    SOCKET m_socketListen;
    SOCKET m_clientSocket;
    struct addrinfo* m_ptrResult;
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
