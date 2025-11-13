#include "MutexGaurd.h"


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

