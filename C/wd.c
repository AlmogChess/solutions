/*******************************************************************************
Project:    Watch Dog
Author:     Almog
Reviewer:   Gita
Version:
*******************************************************************************/
#include <semaphore.h> /* semaphore              */

#include <stdatomic.h> /* atomic_int             */

#include <pthread.h>   /* pthread_create         */

#include "utils.h"

pthread_t watchdog_thread = 0;
pid_t watchdog_proc = 0; 



void *ThreadWachdog(void *params)
{
    
    /* Create watchdog_proc */
    watchdog_proc = fork();
    
    if(0 == watchdog_proc) /* the watch dog process */
    {
        
    }
    else /* the watchdog_thread */
    {
        
    }
    
    
    return NULL;
}
int MakeMeImmortal(int argc, char *argv[], size_t interval, size_t max_misses)
{
    int watch_dog_status = 0;
    int status = 0;
    
    assert(interval);
    assert(max_misses);
    
    /* Create new thread of watch dog */
    status = pthread_create(&watchdog, NULL, ThreadWachdog, NULL);
    RETURN_IF_BAD(!status, "pthread_create Failed", CREATE_F);
    
    
    
    
    
    pthread_join(watchdog, (void **)&status);
    RETURN_IF_BAD(!status, "pthread_join Failed", JOIN_F);
}


/*******************************************************************************
 * notifies the watchdog to not resuscitate the calling program

 * returns 0 for success, not 0 otherwise
*******************************************************************************/
int DoNotResuscitate(void)
{
    /* Send SIGUSR2 to watchdog */
}
