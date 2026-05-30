#ifndef __common_threads_h__
#define __common_threads_h__

#include <pthread.h>
#include <assert.h>
#include <sched.h>

#ifdef __linux__
#include <semaphore.h>
#endif

#define Pthread_create(thread, attr, start_routine, arg) assert(pthread_create(thread, attr, start_routine, arg) == 0);
#define Pthread_join(thread, value_ptr)                  assert(pthread_join(thread, value_ptr) == 0);

#define Pthread_mutex_init(m, v)                         assert(pthread_mutex_init(m, v) == 0);
#define Pthread_mutex_lock(m)                            assert(pthread_mutex_lock(m) == 0);
#define Pthread_mutex_unlock(m)                          assert(pthread_mutex_unlock(m) == 0);

#define Pthread_cond_init(cond, v)                       assert(pthread_cond_init(cond, v) == 0);
#define Pthread_cond_signal(cond)                        assert(pthread_cond_signal(cond) == 0);
#define Pthread_cond_wait(cond, mutex)                   assert(pthread_cond_wait(cond, mutex) == 0);

#define Mutex_init(m)                                    assert(pthread_mutex_init(m, NULL) == 0);
#define Mutex_lock(m)                                    assert(pthread_mutex_lock(m) == 0);
#define Mutex_unlock(m)                                  assert(pthread_mutex_unlock(m) == 0);

#define Cond_init(cond)                                  assert(pthread_cond_init(cond, NULL) == 0);
#define Cond_signal(cond)                                assert(pthread_cond_signal(cond) == 0);
#define Cond_wait(cond, mutex)                           assert(pthread_cond_wait(cond, mutex) == 0);

#ifdef __linux__
#define Sem_init(sem, value)                             assert(sem_init(sem, 0, value) == 0);
#define Sem_wait(sem)                                    assert(sem_wait(sem) == 0);
#define Sem_post(sem)                                    assert(sem_post(sem) == 0);
#endif // __linux__

//////////////////////맥북 로컬 위한 별도 세마포어 도입
#ifdef __APPLE__
#include <dispatch/dispatch.h>
#include <semaphore.h> // sem_t 타입 정의를 위해 포함

// macOS의 GCD 세마포어를 이용해 POSIX 세마포어 기능 모방
#define sem_t dispatch_semaphore_t

#define sem_init(sem, pshared, value)  ((*sem = dispatch_semaphore_create(value)) ? 0 : -1)
#define sem_wait(sem)                  (dispatch_semaphore_wait(*sem, DISPATCH_TIME_FOREVER), 0)
#define sem_post(sem)                  (dispatch_semaphore_signal(*sem), 0)

#define Sem_init(sem, value)           assert(sem_init(sem, 0, value) == 0);
#define Sem_wait(sem)                  assert(sem_wait(sem) == 0);
#define Sem_post(sem)                  assert(sem_post(sem) == 0);
#endif

///////////////////////////////////////////////////////////

#endif // __common_threads_h__
