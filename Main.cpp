
#include "ClientManageSocket.h"
#include "ServerMainSocket.h"
#include "ServerSpecialLogic.h"
#pragma comment(lib, "Ws2_32.lib")

#include "ChangeRegistry.h"
#include "MutexGaurd.h"
#include "windows.h"
std::string NAME_OF_VALUE_IN_REG = "popup";
std::string PATH_TO_PROGRAM = "C:\\Users\\astor\\Desktop\\c_learning\\Project10\\x64\\Release\\Project10.exe";
std::string PATH_TO_KEY_TO_INSERT_IN = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
std::string NAME_LOCK = "very_special_lock";
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
    char srcPort[] = "12345";
    int receivedLen = 0;
    int* ptrReceivedLen = &receivedLen;

    char* recvBuffer = NULL;
    try
    {
        ServerSocket techServer(srcPort);
        techServer.bindServer();
        techServer.listenSocket();
        while (true)
        {
            techServer.acceptClient();
            try
            {
                ManageClient techOtherComputer(techServer.getClientSocket());
                ServerLogic server(techOtherComputer);
                while (true)
                {

                    recvBuffer = server.recvDataServer(ptrReceivedLen);
                    server.sendDataServer(receivedLen, recvBuffer);
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

}
