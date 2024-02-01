[Deadlock](https://en.wikipedia.org/wiki/Deadlock)
[PTHREAD_MUTEX_INITIALIZER](https://stackoverflow.com/questions/14320041/pthread-mutex-initializer-vs-pthread-mutex-init-mutex-param), 
- key takeaway - 4 Coffman Conditions (E.G.Coffman, 1971)
- key takeaway - PTHREAD_MUTEX_INITIALIZER, suitable alternative for .._init and .._destroy 

# 42-4-Philosophers
from Greek, philosophia, literally "love of wisdom")


Account Holder:       Sammelkartenmarkt
IBAN:                 DE80100400000107541500
BIC:                  COBADEFFXXX

Address of the Bank:  Commerzbank AG
                      Müllerstr. 180
                      13353 Berlin
                      Germany
Transfer Reason:

mmman-991929414


stuck in the middle, living to fight another dayye


=====================

Here's a brief explanation of each function:

sem_open: Open a named semaphore.

This function is used to create or open a named semaphore. A named semaphore is a semaphore that has a name in the operating system, making it accessible by multiple processes.
Syntax: sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
Example: sem_t *my_semaphore = sem_open("/my_semaphore", O_CREAT, 0644, 1);
This example creates a named semaphore with the name "/my_semaphore," initializes it with a value of 1, and sets permissions to 0644.
sem_close: Close a named semaphore.

This function is used to close a named semaphore, freeing up system resources.
Syntax: int sem_close(sem_t *sem);
Example: sem_close(my_semaphore);
This example closes the semaphore previously opened with sem_open.
sem_post: Increment the value of a semaphore.

This function is used to increase (post) the value of a semaphore. If other processes or threads are waiting for the semaphore, one of them will be unblocked.
Syntax: int sem_post(sem_t *sem);
Example: sem_post(my_semaphore);
This example increments the value of the semaphore.
sem_wait: Decrement the value of a semaphore, blocking if necessary.

This function is used to decrease (wait) the value of a semaphore. If the semaphore's value is already zero, the process or thread will be blocked until the value becomes positive.
Syntax: int sem_wait(sem_t *sem);
Example: sem_wait(my_semaphore);
This example decrements the value of the semaphore, potentially causing the calling process or thread to block.
sem_unlink: Remove a named semaphore from the system.

This function is used to remove (unlink) a named semaphore from the system. After calling this function, the semaphore is no longer accessible by its name.
Syntax: int sem_unlink(const char *name);
Example: sem_unlink("/my_semaphore");
This example removes the named semaphore with the name "/my_semaphore" from the system.
These functions are commonly used in scenarios where multiple processes or threads need to coordinate and synchronize their activities, especially when accessing shared resources. They are part of the POSIX standard for inter-process communication on Unix-like operating systems.
