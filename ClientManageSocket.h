#pragma once
#include <exception>
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

class ManageClient
{

    /*
    manages a classic server communication with client
    */
  public:
    /*
    contructor of class
    :param socketToClient: instance of SOCKET to send and recieve pakcets from client.
    */
    ManageClient(SOCKET socketToClient);
    /*
    destroyer of class - closes the socket with client
    */
    ~ManageClient();
    /*
    recieve data from client
    :param recvbuf: the buffer to insert in the data recieved
    :param recvbuflen: the buffer length
    */
    int recv_data(char* recvbuf, int recvbuflen);
    /*
    send data to client
    :param send_buff: the buffer to send
    :param recvbuflen: the buffer length
    */
    void send_data(const char* send_buff, int len);

  private:
    SOCKET m_socketToClient = NULL;
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