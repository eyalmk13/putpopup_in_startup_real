#include "popup_window.h"
#include <Windows.h>
void send_message(LPCWSTR title_name, LPCWSTR window_msg)
{
    MessageBox(NULL, window_msg, title_name, MB_OK | MB_ICONINFORMATION);
}
