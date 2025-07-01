#include "mutex_gaurd.h"

MutexGuard::MutexGuard(LPSTR name_of_lock)
{
    m_ghMutex = CreateMutexA(NULL, FALSE, name_of_lock);
    m_is_lock_free = (GetLastError() != ERROR_ALREADY_EXISTS);
}
MutexGuard::~MutexGuard()
{
    if (m_is_lock_free)
    {
        ReleaseMutex(m_ghMutex);
    }
    CloseHandle(m_ghMutex);
}

BOOL MutexGuard::getIsLockFree()
{
    return m_is_lock_free;
}
