#include "change_registry.h"
#include <cstring>

int create_registry_value(LPCSTR sub_key, HKEY hkey, LPCSTR name_to_add, LPCSTR data_to_store)
{
    HKEY phkResult_open_key;
    LSTATUS result_check;
    result_check = RegOpenKeyA(hkey, sub_key, &phkResult_open_key);
    if (result_check != ERROR_SUCCESS)
    {
        return ERROR_CREATE_FUNC;
    }
    size_t data_size = strlen(data_to_store) + 1;

    const BYTE* data_to_store_bytes = reinterpret_cast<const BYTE*>(data_to_store);
    result_check = RegSetValueExA(phkResult_open_key, name_to_add, NULL, REG_SZ, data_to_store_bytes, data_size);
    RegCloseKey(phkResult_open_key);
    if (result_check != ERROR_SUCCESS)
    {
        return ERROR_CREATE_FUNC;
    }
    return SUCCESS_CREATE_FUNC;
}

BOOL check_registry_value(HKEY hKey, LPCSTR SubKey, LPCSTR value_name)
{
    LSTATUS result_check;
    result_check = RegGetValueA(hKey, SubKey, value_name, RRF_RT_ANY, NULL, NULL, NULL);
    if (result_check == ERROR_SUCCESS)
    {
        return true;
    }
    return false;
}
