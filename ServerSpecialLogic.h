#pragma once
#include "ClientManageSocket.h"

class ServerLogic
{
    /*
    manages a the server of tecnic communication with client.
    */
  public:
    /*
    contructor of class
    :param techOtherComputer: instance of ManageClient to send and recieve pakcets via socket.
    */
    ServerLogic(ManageClient& techOtherComputer);
    /*
    sends data to client
    :param receivedLen: the data length  recieved from client
    :param receivedLen: the data recieved from client
    */
    void sendDataServer(int receivedLen, char* recvBuffer);
    /*
    recieves data from client
    :param ptr_received_len: pointer to recieved length
    :return: the recieved data
    */
    char* recvDataServer(int* ptr_received_len);

  private:
    ManageClient& m_tech_other_computer;
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
