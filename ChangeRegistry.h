#pragma once
#include <Windows.h>
#include <exception>
#include <iostream>
#include <string>

class ManageRegistry
{
<<<<<<< HEAD
  public:
    /*
    constructor of class - gets a handle to the key register
    :param sub_key: a string of sub key path from the main key to insert in the value
    :param hkey: the handle to the key
    */
    ManageRegistry(std::string sub_key, HKEY hkey);
=======
public:
    /*
    constructor of class - gets a handle to the key register
    :param subKey: a string of sub key path from the main key to insert in the value
    :param hKey: the handle to the key
    */
    ManageRegistry(std::string subKey, HKEY hKey);
>>>>>>> technic
    /*
    destroyer of class - closes the handle
    */
    ~ManageRegistry();
    /*
    creates a registry value in the key given
<<<<<<< HEAD
    :param name_to_add: the value to add
    :param data_to_store: data to store in value
    */
    void createRegistryValue(std::string name_to_add, std::string data_to_store);
    /*
    checks if a value is already inserted in a key or not
    :param value_name: the value to check
    :return: if there is the value inputted true,else false
    */
    BOOL checkRegistryValue(std::string value_name);
    /*
    returns the value of m_phkResult_open_key
    :return: the value of m_phkResult_open_key
    */
    HKEY getPhkResultOpenKey();

  private:
    HKEY m_phkResult_open_key;
    HKEY* m_ptr_phkResult_open_key = &m_phkResult_open_key;
};

class ClassManageRegistryExceptions : public std::exception
{
  public:
    ClassManageRegistryExceptions(const std::string& msg) : message(msg)
    {
=======
    :param nameToAdd: the value to add
    :param dataToStore: data to store in value
    */
    void createRegistryValue(std::string nameToAdd, std::string dataToStore);
    /*
    checks if a value is already inserted in a key or not
    :param valueName: the value to check
    :return: if there is the value inputted true,else false
    */
    BOOL checkRegistryValue(std::string valueName);
    /*
    returns the value of m_phkResultOpenKey
    :return: the value of m_phkResultOpenKey
    */
    HKEY getPhkResultOpenKey();

private:
    HKEY m_phkResultOpenKey;
    HKEY* m_ptr_phkResultOpenKey = &m_phkResultOpenKey;
};

class ManageRegistryExceptions : public std::exception
{
public:
    ManageRegistryExceptions(const std::string& msg) : message(msg)
    {
    // left blank intentionally
>>>>>>> technic
    }

    // Override what() from std::exception
    const char* what() const noexcept override
    {
        return message.c_str();
    }

<<<<<<< HEAD
  private:
    std::string message;
=======
private:
    std::string message;

>>>>>>> technic
};
