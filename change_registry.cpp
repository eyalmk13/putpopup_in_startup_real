#include "change_registry.h"
#include <cstring>

ManageRegistry::ManageRegistry(LPCSTR sub_key, HKEY hkey)
{
    LSTATUS result_check;
    m_phkResult_open_key = NULL;
    result_check = RegOpenKeyA(hkey, sub_key, m_ptr_phkResult_open_key);
    if (result_check != ERROR_SUCCESS)
    {
        throw ClassManageRegistryExceptions("ManageRegistry function went wrong");
    }
}
ManageRegistry::~ManageRegistry()
{
    LSTATUS result_check;
    result_check = RegCloseKey(m_phkResult_open_key);
    if (result_check != ERROR_SUCCESS)
    {
        std::cerr << "Warning: Failed to close registry key " << std::endl;
    }
}

void ManageRegistry::createRegistryValue(LPCSTR name_to_add, LPCSTR data_to_store)
{
    LSTATUS result_check;
    size_t data_to_store_len = strlen(data_to_store) + 1;
    DWORD size_data = static_cast<DWORD>(data_to_store_len);
    const BYTE* data_to_store_bytes = reinterpret_cast<const BYTE*>(data_to_store);
    result_check = RegSetValueExA(m_phkResult_open_key, name_to_add, NULL, REG_SZ, data_to_store_bytes, size_data);
    if (result_check != ERROR_SUCCESS)
    {
        throw ClassManageRegistryExceptions("createRegistryValue function went wrong");
    }
}

BOOL ManageRegistry::checkRegistryValue(LPCSTR value_name)
{
    LSTATUS result_check;
    result_check = RegGetValueA(m_phkResult_open_key, NULL, value_name, RRF_RT_ANY, NULL, NULL, NULL);
    if (result_check == ERROR_SUCCESS)
    {
        return true;
    }
    else if (result_check != ERROR_FILE_NOT_FOUND)
    {
        throw ClassManageRegistryExceptions("createRegistryValue function went wrong");
    }
    return false;
}
HKEY ManageRegistry::getPhkResultOpenKey()
{
    return m_phkResult_open_key;
}