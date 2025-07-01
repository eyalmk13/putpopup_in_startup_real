#ifndef SEND_MESSAGE_H
#define SEND_MESSAGE_H
#include <Windows.h>

/*
shosw a popup message on screen
:param title_name: the title of window
:param window_msg: the message in window
*/
void send_message(LPCWSTR title_name, LPCWSTR window_msg);

#endif