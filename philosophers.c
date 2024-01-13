/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:25 by mman              #+#    #+#             */
/*   Updated: 2024/01/13 15:43:03 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

/* Memory Manipulation:
 *   memset: Set a block of memory to a specific value.
 *   malloc: Allocate a specified number of bytes of memory.
 *   free: Deallocate memory previously allocated by malloc.
 *
 * Output:
 *   printf: Print formatted output to the standard output stream.
 *   write: Write data to a file descriptor.
 *
 * Process Control:
 *   fork: Create a new process by duplicating the calling process.
 *   kill: Send a signal to a process or a group of processes.
 *   exit: Terminate the calling process.
 *   waitpid: Wait for a specific child process to terminate.
 *
 * Threading:                                       (REGULAR ONLY)
 *   pthread_create: Create a new thread.
 *   pthread_detach: Detach a thread, allowing it to run independently.
 *   pthread_join: Wait for a thread to terminate.
 *
 * 	--> Mutexes are short for 'mutual exclusion'
 * 		pthread_mutex_init: Initializes a mutex before it can be used.
		pthread_mutex_destroy: Destroys a mutex when it is no longer needed.
		pthread_mutex_lock: Locks a mutex, allowing the calling thread to proceed
						if the mutex is currently not locked by any other thread.
						If the mutex is already locked, the calling thread will
						be blocked until the mutex becomes available.
		pthread_mutex_unlock: Unlocks a mutex, releasing it for other threads to acquire.
 *
 * Time Handling:
 *   usleep: Suspend execution of the calling thread for a specified time.
 *   gettimeofday: Get the current time and date.
 *
 * Inter-Process Communication and Synchronization: (BONUS ONLY)
 *   sem_open: Open a named semaphore.
 *   sem_close: Close a named semaphore.
 *   sem_post: Increment the value of a semaphore.
 *   sem_wait: Decrement the value of a semaphore, blocking if necessary.
 *   sem_unlink: Remove a named semaphore from the system.
 *
 */


/*
 * Your program should take the following arguments:
 *   number_of_philosophers time_to_die time_to_eat time_to_sleep
 *   [number_of_times_each_philosopher_must_eat]
 *
 * - number_of_philosophers: The number of philosophers and also the number
 *   of forks.
 * - time_to_die (in milliseconds): If a philosopher doesn’t start eating
 *   time_to_die milliseconds since the beginning of their last meal or the
 *   beginning of the simulation, they die.
 * - time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
 *   During that time, they will need to hold two forks.
 * - time_to_sleep (in milliseconds): The time a philosopher will spend
 *   sleeping.
 * - number_of_times_each_philosopher_must_eat (optional argument): If all
 *   philosophers have eaten at least
 *   number_of_times_each_philosopher_must_eat times, the simulation stops. If
 *   not specified, the simulation stops when a philosopher dies.
 *
 *
 *  (in milliseconds)
 *
 */

/*
The specific rules for the mandatory part are:

• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.

• To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.


+ • Global variables are forbidden!
+
*/


int main(void)
{
	return (EXIST?);
}



// - create a thread (PHILOSPHER)
// - fork this thread (AMOUNT OF PHILOSOPHERS)
// - each PHILOSOPHER creates a fork
// - when philosopher picks up a fork, it is mutexed
// - when philospher picks up two forks, they start eating
// - when they finish, they go to sleep (and they )release both forks
// - when they finish sleeping, they start thinking
// - when they think for time_to_die since last time, when they ate (or simulation start) they die (ending simulation)
// (Each fork needs to be correctly picked up, On the right and on the left)

// - philosophers dont speak with others, so no fork putdowns, or no begging
// - forks are in the middle
// - available fork (number) is represented by a semaphore
// - main process is XY
// - each philosopher is a process

