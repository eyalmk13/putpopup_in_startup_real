#ifndef MUTEX_GAURD_H
#define MUTEX_GAURD_H
#include <Windows.h>

class mutex_gaurd
{
  public:
    /*
    contructor of class - creates a handle to a lock.(if doesn't exist creates it)
    :param name_of_lock: the name of lock.
    */
    mutex_gaurd(LPSTR name_of_lock);
    /*
    destroyer of class - close handle and if thye lock is on our possesion - realeses lock
    */
    ~mutex_gaurd();
    /*
    gets the m_is_lock_free variable that represent if the lock ios in our possesion(true), or other possesion(false)
    :return m_is_lock_free
    */
    BOOL get_is_lock_free();

  private:
    LPSTR m_name_of_lock;
    HANDLE m_ghMutex;
    BOOL m_is_lock_free;
};

#endif