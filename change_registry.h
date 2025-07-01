#ifndef POPUP_H
#define POPUP_H
#include <Windows.h>

#define ERROR_CREATE_FUNC (1)
#define SUCCESS_CREATE_FUNC (0)

/*
creates a registry value in the key given
:param sub_key: a string of sub key path from the main key to insert in the value
:param hkey: the handle to the key
:param name_to_add: the value to add
:param data_to_store: data to store in value
:return: if succeded SUCCESS_CREATE_FUNC,else ERROR_CREATE_FUNC
*/
int create_registry_value(LPCSTR sub_key, HKEY hkey, LPCSTR name_to_add, LPCSTR data_to_store);

/*
checks if a value is already inserted in a key or not
:param hkey: the handle to the key
:param SubKey: a string of sub key path from the main key to insert in the value
:param name_to_add: the value to check
:return: if there is the value inputted true,else false
*/
BOOL check_registry_value(HKEY hKey, LPCSTR SubKey, LPCSTR value_name);
#endif