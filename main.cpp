#include "change_registry.h"
#include "mutex_gaurd.h"
#include "popup_window.h"

LPCSTR NAME_OF_VALUE_IN_REG = (LPCSTR) "popup";
LPCSTR PATH_TO_PROGRAM = (LPCSTR) "C:\\Users\\astor\\Desktop\\c_learning\\Project8\\x64\\Release\\Project8.exe";
LPCSTR PATH_TO_KEY_TO_INSERT_IN = (LPCSTR) "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
LPSTR NAME_LOCK = (LPSTR) "very_special_lock";
LPCWSTR TITLE_NAME = L"MY_WINDOW";
LPCWSTR WINDOW_MSG = L"MANAGEMENT PROGRAM IS UP";

int main()
{
    mutex_gaurd lock(NAME_LOCK);
    if (lock.get_is_lock_free())
    {
        if (!check_registry_value(HKEY_CURRENT_USER, PATH_TO_KEY_TO_INSERT_IN, NAME_OF_VALUE_IN_REG))
        {
            create_registry_value(PATH_TO_KEY_TO_INSERT_IN, HKEY_CURRENT_USER, NAME_OF_VALUE_IN_REG, PATH_TO_PROGRAM);
        }
        send_message(TITLE_NAME, WINDOW_MSG);
    }
    return 0;
}
