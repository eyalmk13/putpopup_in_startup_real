#ifndef CLIENT_SOCK_H
#define CLIENT_SOCK_H

#include <winsock2.h>    
#include <ws2tcpip.h>    
#include <exception>     
#include <string>        
#include <iostream>
#define DEFAULT_BUFLEN (1024)

class ManageClient
{
  public:
    /*
    contructor of class
    :param socket_to_client: instance of SOCKET to send and recieve pakcets from client.
    */
    ManageClient(SOCKET socket_to_client);
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
    void send_data(char* send_buff, int len);

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