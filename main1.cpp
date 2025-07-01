#include "client_manage_socket.h"
#include "server_main_socket.h"
#include <cstring>


int main()
{
    
    char src_port[] = "12345";
    int received_len = 0;
    int* ptr_received_len = &received_len;

    char* recv_buffer = NULL;
    ServerSocket tech_server(src_port);
    tech_server.bindServer();
    tech_server.listenSocket();
    tech_server.acceptClient();
    ManageClient tech_other_computer(tech_server.getClientSocket());
    while (true)
    {
        recv_buffer = recvDataServer(tech_other_computer, ptr_received_len); 
        sendDataServer(tech_other_computer, received_len, recv_buffer);
    }
    
    
    
}
