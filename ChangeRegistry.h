#pragma once
#include <Windows.h>
#include <exception>
#include <iostream>
#include <string>

class ManageRegistry
{
public:
    /*
    constructor of class - gets a handle to the key register
    :param subKey: a string of sub key path from the main key to insert in the value
    :param hKey: the handle to the key
    */
    ManageRegistry(std::string subKey, HKEY hKey);
    /*
    destroyer of class - closes the handle
    */
    ~ManageRegistry();
    /*
    creates a registry value in the key given
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
    }

    // Override what() from std::exception
    const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;

};
