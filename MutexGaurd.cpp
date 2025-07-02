#include "MutexGaurd.h"

<<<<<<< HEAD
MutexGuard::MutexGuard(std::string name_of_lock)
{
    m_lock_handle = CreateMutexA(NULL, FALSE, name_of_lock.c_str());
    if (m_lock_handle == NULL)
    {
        DWORD error = GetLastError();
        throw ClassMutexGuardExceptions("CreateMutexA failed with error code: " + std::to_string(error));
    }
    m_is_lock_free = (GetLastError() != ERROR_ALREADY_EXISTS);
}
MutexGuard::~MutexGuard()
{
    if (m_is_lock_free)
    {
        if (!ReleaseMutex(m_lock_handle))
        {
            DWORD error = GetLastError();
            std::cerr << "Error: Failed to close registry key error code : " << std::to_string(error) << std::endl;
        }
    }
    if (!CloseHandle(m_lock_handle))
    {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to close registry key error code : " << std::to_string(error) << std::endl;
    }
}

BOOL MutexGuard::getIsLockFree()
{
    return m_is_lock_free;
}
=======

MutexGuard::MutexGuard(std::string nameOfLock)
{
   m_lockHandle = CreateMutexA(NULL, FALSE, nameOfLock.c_str());
    if (m_lockHandle == NULL) {
        DWORD error = GetLastError();
        throw MutexGuardExceptions("CreateMutexA failed with error code: " + std::to_string(error));
    }
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        throw MutexGuardExceptions("lock is not avaliable");
    }
}
MutexGuard::~MutexGuard()
{
    
    if (!ReleaseMutex(m_lockHandle))
    {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to close registry key error code : "<< std::to_string(error)<< std::endl;
    }
    if (!CloseHandle(m_lockHandle))
    {
        DWORD error = GetLastError();
        std::cerr << "Error: Failed to close registry key error code : " << std::to_string(error) << std::endl;

    }
}

>>>>>>> technic
