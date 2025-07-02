<<<<<<< HEAD

#include "ChangeRegistry.h"

ManageRegistry::ManageRegistry(std::string sub_key, HKEY hkey)
{
    LSTATUS status_open_key;
    m_phkResult_open_key = NULL;
    status_open_key = RegOpenKeyA(hkey, sub_key.c_str(), m_ptr_phkResult_open_key);
    if (status_open_key != ERROR_SUCCESS)
    {
        throw ClassManageRegistryExceptions("ManageRegistry function went wrong");
=======
#include "ChangeRegistry.h"

ManageRegistry::ManageRegistry(std::string subKey, HKEY hKey)
{
    LSTATUS status_open_key;
    m_phkResultOpenKey = NULL;
    status_open_key = RegOpenKeyA(hKey, subKey.c_str(), m_ptr_phkResultOpenKey);
    if (status_open_key != ERROR_SUCCESS)
    {
        throw ManageRegistryExceptions("ManageRegistry function went wrong");
>>>>>>> technic
    }
}
ManageRegistry::~ManageRegistry()
{
    LSTATUS status_close_key;
<<<<<<< HEAD
    status_close_key = RegCloseKey(m_phkResult_open_key);
=======
    status_close_key = RegCloseKey(m_phkResultOpenKey);
>>>>>>> technic
    if (status_close_key != ERROR_SUCCESS)
    {
        std::cerr << "Error: Failed to close registry key" << std::endl;
    }
}

<<<<<<< HEAD
void ManageRegistry::createRegistryValue(std::string name_to_add, std::string data_to_store)
{
    LSTATUS status_set_value_reg;
    size_t data_to_store_len = data_to_store.length() + 1;
    DWORD size_data = static_cast<DWORD>(data_to_store_len);
    const BYTE* data_to_store_bytes = reinterpret_cast<const BYTE*>(data_to_store.c_str());
    status_set_value_reg =
        RegSetValueExA(m_phkResult_open_key, name_to_add.c_str(), NULL, REG_SZ, data_to_store_bytes, size_data);
    if (status_set_value_reg != ERROR_SUCCESS)
    {
        throw ClassManageRegistryExceptions("createRegistryValue function went wrong");
    }
}

BOOL ManageRegistry::checkRegistryValue(std::string value_name)
{
    LSTATUS status_get_value_reg;
    status_get_value_reg = RegGetValueA(m_phkResult_open_key, NULL, value_name.c_str(), RRF_RT_ANY, NULL, NULL, NULL);
=======

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
>>>>>>> technic
    if (status_get_value_reg == ERROR_SUCCESS)
    {
        return true;
    }
    else if (status_get_value_reg != ERROR_FILE_NOT_FOUND)
    {
<<<<<<< HEAD
        throw ClassManageRegistryExceptions("createRegistryValue function went wrong");
=======
        throw ManageRegistryExceptions("createRegistryValue function went wrong");
>>>>>>> technic
    }
    return false;
}
HKEY ManageRegistry::getPhkResultOpenKey()
{
<<<<<<< HEAD
    return m_phkResult_open_key;
=======
    return m_phkResultOpenKey;
>>>>>>> technic
}