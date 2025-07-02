#pragma once
#include <Windows.h>
#include <string>
#include <exception>
#include <iostream> 
class MutexGuard
{
public:
    /*
    contructor of class - creates a handle to a lock.(if doesn't exist creates it)
    :param nameOfLock: the name of lock.
    */
    MutexGuard(std::string nameOfLock);
  /*
    destroyer of class - close handle and if thye lock is on our possesion - realeses lock
    */
    ~MutexGuard();
    /*
    deleting the copy constructor and assignment
    */
    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;

private:
    HANDLE m_lockHandle;
};


class MutexGuardExceptions : public std::exception
{
public:
    MutexGuardExceptions(const std::string& msg) : message(msg)
    {
        // left blank intentionally
    }
const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;

};
