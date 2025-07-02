#include "ChangeRegistry.h"

ManageRegistry::ManageRegistry(std::string subKey, HKEY hKey)
{
    LSTATUS status_open_key;
    m_phkResultOpenKey = NULL;
    status_open_key = RegOpenKeyA(hKey, subKey.c_str(), m_ptr_phkResultOpenKey);
    if (status_open_key != ERROR_SUCCESS)
    {
        throw ManageRegistryExceptions("ManageRegistry function went wrong");

    }
}
ManageRegistry::~ManageRegistry()
{
    LSTATUS status_close_key;
    status_close_key = RegCloseKey(m_phkResultOpenKey);
    if (status_close_key != ERROR_SUCCESS)
    {
        std::cerr << "Error: Failed to close registry key" << std::endl;
    }
}

void ManageRegistry::createRegistryValue(std::string nameToAdd, std::string dataToStore)
{
    LSTATUS status_set_value_reg;
    size_t data_to_store_len = dataToStore.length() + 1;
    DWORD size_data = static_cast<DWORD>(data_to_store_len);
    const BYTE* data_to_store_bytes = reinterpret_cast<const BYTE*>(dataToStore.c_str());
    status_set_value_reg = RegSetValueExA(m_phkResultOpenKey, nameToAdd.c_str(), NULL, REG_SZ, data_to_store_bytes, size_data);
    if (status_set_value_reg != ERROR_SUCCESS)
    {
        throw ManageRegistryExceptions("createRegistryValue function went wrong");
    }
}


BOOL ManageRegistry::checkRegistryValue(std::string valueName)
{
    LSTATUS status_get_value_reg;
    status_get_value_reg = RegGetValueA(m_phkResultOpenKey, NULL, valueName.c_str(), RRF_RT_ANY, NULL, NULL, NULL);
    if (status_get_value_reg == ERROR_SUCCESS)
    {
        return true;
    }
    else if (status_get_value_reg != ERROR_FILE_NOT_FOUND)
    {
        throw ManageRegistryExceptions("createRegistryValue function went wrong");
    }
    return false;
}
HKEY ManageRegistry::getPhkResultOpenKey()
{
    return *m_ptr_phkResultOpenKey;
}