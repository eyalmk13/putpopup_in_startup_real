#include "windows.h"
#include "ChangeRegistry.h"
#include "MutexGaurd.h"
std::string NAME_OF_VALUE_IN_REG = "popup";
std::string PATH_TO_PROGRAM = "C:\\Users\\astor\\Desktop\\c_learning\\Project10\\x64\\Release\\Project10.exe";
std::string PATH_TO_KEY_TO_INSERT_IN = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
std::string NAME_LOCK = "very_special_lock";
LPCWSTR TITLE_NAME = L"MY_WINDOW";
LPCWSTR WINDOW_MSG = L"MANAGEMENT PROGRAM IS UP";

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
    MessageBox(NULL, WINDOW_MSG, TITLE_NAME, MB_OK | MB_ICONINFORMATION);
    DWORD TIME_TO_SLEEP = 1000 * 3600;
    Sleep(TIME_TO_SLEEP);
    return 0;
}
