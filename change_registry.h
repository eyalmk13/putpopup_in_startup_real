#ifndef POPUP_H
#define POPUP_H
#include <emmintrin.h>
#include <Windows.h>
#include <exception>
#include <iostream>
#include <string>

class ManageRegistry
{
  public:
    /*
    constructor of class - gets a handle to the key register
    :param sub_key: a string of sub key path from the main key to insert in the value
    :param hkey: the handle to the key
    */
    ManageRegistry(LPCSTR sub_key, HKEY hkey);
    /*
    destroyer of class - closes the handle
    */
    ~ManageRegistry();
    /*
    creates a registry value in the key given
    :param name_to_add: the value to add
    :param data_to_store: data to store in value
    */
    void createRegistryValue(LPCSTR name_to_add, LPCSTR data_to_store);
    /*
    checks if a value is already inserted in a key or not
    :param value_name: the value to check
    :return: if there is the value inputted true,else false
    */
    BOOL checkRegistryValue(LPCSTR value_name);
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
  private:
    std::string message;

  public:
    ClassManageRegistryExceptions(const std::string& msg) : message(msg)
    {
    }

    // Override what() from std::exception
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

#endif