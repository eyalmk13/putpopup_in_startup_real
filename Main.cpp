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
    char srcPort[] = "12345";
    int receivedLen = 0;
    int* ptrReceivedLen= &receivedLen;

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

                    recvBuffer = server.recvDataServer(ptr_received_len);
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
