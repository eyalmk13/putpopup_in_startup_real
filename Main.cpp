<<<<<<< HEAD
#include "ClientManageSocket.h"
#include "ServerMainSocket.h"
#include "ServerSpecialLogic.h"
#pragma comment(lib, "Ws2_32.lib")

#include "ChangeRegistry.h"
#include "MutexGaurd.h"
#include "windows.h"
=======
#include "windows.h"
#include "ChangeRegistry.h"
#include "MutexGaurd.h"
>>>>>>> technic
std::string NAME_OF_VALUE_IN_REG = "popup";
std::string PATH_TO_PROGRAM = "C:\\Users\\astor\\Desktop\\c_learning\\Project10\\x64\\Release\\Project10.exe";
std::string PATH_TO_KEY_TO_INSERT_IN = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
std::string NAME_LOCK = "very_special_lock";
<<<<<<< HEAD

int main()
{
    MutexGuard lock(NAME_LOCK);

    if (!lock.getIsLockFree())
    {
        throw ClassMutexGuardExceptions("lock is not avaliable");
    }
    ManageRegistry run_key(PATH_TO_KEY_TO_INSERT_IN, HKEY_CURRENT_USER);
    if (!run_key.checkRegistryValue(NAME_OF_VALUE_IN_REG))
    {
        run_key.createRegistryValue(NAME_OF_VALUE_IN_REG, PATH_TO_PROGRAM);
    }
    char src_port[] = "12345";
    int received_len = 0;
    int* ptr_received_len = &received_len;

    char* recv_buffer = NULL;
    try
    {
        ServerSocket tech_server(src_port);
        tech_server.bindServer();
        tech_server.listenSocket();
        while (true)
        {
            tech_server.acceptClient();
            try
            {
                ManageClient tech_other_computer(tech_server.getClientSocket());
                ServerLogic server(tech_other_computer);
                while (true)
                {

                    recv_buffer = server.recvDataServer(ptr_received_len);
                    server.sendDataServer(received_len, recv_buffer);
                }
            }
            catch (const ClassManageClientExceptions& ex)
            {
                std::cerr << "Caught ClassManageClientExceptions: " << ex.what() << std::endl;
            }
            catch (const ClassServerLogicExceptions& ex)
            {
                std::cerr << "Caught ClassServerLogicExceptions: " << ex.what() << std::endl;
            }
        }
    }
    catch (const ClassServerSocketyExceptions& ex)
    {
        std::cerr << "Caught ClassServerLogicExceptions: " << ex.what() << std::endl;
    }
    return 0;
=======
std::string TITLE_NAME = "MY_WINDOW";
std::string WINDOW_MSG = "MANAGEMENT PROGRAM IS UP";

int main()
{
    try
    {

        MutexGuard lock(NAME_LOCK);
        ManageRegistry runKey(PATH_TO_KEY_TO_INSERT_IN, HKEY_CURRENT_USER);
        if (!runKey.checkRegistryValue(NAME_OF_VALUE_IN_REG))
        {
            runKey.createRegistryValue(NAME_OF_VALUE_IN_REG, PATH_TO_PROGRAM);
        }
        MessageBoxA(NULL, WINDOW_MSG.c_str(), TITLE_NAME.c_str(), MB_OK | MB_ICONINFORMATION);
        DWORD TIME_TO_SLEEP = 1000 * 3600;
        Sleep(TIME_TO_SLEEP);
    }
    catch (const MutexGuardExceptions& ex)
    {
        std::cerr << "Caught MutexGuardExceptions: " << ex.what() << std::endl;
    }
    catch (const ManageRegistryExceptions& ex)
    {
        std::cerr << "Caught ManageRegistryExceptions: " << ex.what() << std::endl;
    }
    return 0;


>>>>>>> technic
}
