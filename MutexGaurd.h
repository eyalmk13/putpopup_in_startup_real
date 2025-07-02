#pragma once
#include <Windows.h>
<<<<<<< HEAD
#include <exception>
#include <iostream>
#include <string>
class MutexGuard
{
  public:
    /*
    contructor of class - creates a handle to a lock.(if doesn't exist creates it)
    :param name_of_lock: the name of lock.
    */
    MutexGuard(std::string name_of_lock);
=======
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
>>>>>>> technic
    /*
    destroyer of class - close handle and if thye lock is on our possesion - realeses lock
    */
    ~MutexGuard();
    /*
<<<<<<< HEAD
    gets the m_is_lock_free variable that represent if the lock ios in our possesion(true), or other possesion(false)
    :return m_is_lock_free
    */
    BOOL getIsLockFree();
    /*
=======
>>>>>>> technic
    deleting the copy constructor and assignment
    */
    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;

<<<<<<< HEAD
  private:
    HANDLE m_lock_handle;
    BOOL m_is_lock_free;
};

class ClassMutexGuardExceptions : public std::exception
{
  public:
    ClassMutexGuardExceptions(const std::string& msg) : message(msg)
    {
    }

    // Override what() from std::exception
=======

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

>>>>>>> technic
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
