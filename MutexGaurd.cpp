#include "MutexGaurd.h"

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
