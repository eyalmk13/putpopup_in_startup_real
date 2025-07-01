#include "mutexgaurd.h"

mutex_gaurd::mutex_gaurd(LPSTR name_of_lock)
{
    m_name_of_lock = name_of_lock;
    m_ghMutex = CreateMutexA(NULL, FALSE, m_name_of_lock);
    m_is_lock_free = (GetLastError() != ERROR_ALREADY_EXISTS);
}
mutex_gaurd::~mutex_gaurd()
{
    if (m_is_lock_free)
    {
        ReleaseMutex(m_ghMutex);
    }
    CloseHandle(m_ghMutex);
}

BOOL mutex_gaurd::get_is_lock_free()
{
    return m_is_lock_free;
}
