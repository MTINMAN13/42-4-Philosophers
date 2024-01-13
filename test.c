/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:34:41 by mman              #+#    #+#             */
/*   Updated: 2024/01/13 03:34:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5
#define TIME_TO_DIE 1000000 // in microseconds

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
struct timeval last_meal_time[NUM_PHILOSOPHERS];

void *philosopher_thread(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", philosopher_id);

        // Attempt to pick up either fork
        if (pthread_mutex_trylock(&forks[left_fork]) == 0) {
            printf("Philosopher %d picked up left fork.\n", philosopher_id);

            // Attempt to pick up the other fork
            if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
                printf("Philosopher %d picked up right fork. Starting to eat.\n", philosopher_id);

                // Eating
                gettimeofday(&last_meal_time[philosopher_id], NULL);
                printf("Philosopher %d is eating.\n", philosopher_id);

                // Release right fork
                pthread_mutex_unlock(&forks[right_fork]);
                printf("Philosopher %d released right fork.\n", philosopher_id);

                // Release left fork
                pthread_mutex_unlock(&forks[left_fork]);
                printf("Philosopher %d released left fork.\n", philosopher_id);

                // Sleeping
                usleep(500000); // sleep for 0.5 seconds

                // Check if it's time to die
                struct timeval current_time;
                gettimeofday(&current_time, NULL);
                long elapsed_time = (current_time.tv_sec - last_meal_time[philosopher_id].tv_sec) * 1000000 +
                                    (current_time.tv_usec - last_meal_time[philosopher_id].tv_usec);
                if (elapsed_time >= TIME_TO_DIE) {
                    printf("Philosopher %d died. Ending simulation.\n", philosopher_id);
                    exit(0);
                }
            } else {
                // Release left fork if right fork is not available
                pthread_mutex_unlock(&forks[left_fork]);
            }
        }

        // Attempt to pick up the other fork first
        if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
            printf("Philosopher %d picked up right fork.\n", philosopher_id);

            // Attempt to pick up the other fork
            if (pthread_mutex_trylock(&forks[left_fork]) == 0) {
                printf("Philosopher %d picked up left fork. Starting to eat.\n", philosopher_id);

                // Eating
                gettimeofday(&last_meal_time[philosopher_id], NULL);
                printf("Philosopher %d is eating.\n", philosopher_id);

                // Release left fork
                pthread_mutex_unlock(&forks[left_fork]);
                printf("Philosopher %d released left fork.\n", philosopher_id);

                // Release right fork
                pthread_mutex_unlock(&forks[right_fork]);
                printf("Philosopher %d released right fork.\n", philosopher_id);

                // Sleeping
                usleep(500000); // sleep for 0.5 seconds

                // Check if it's time to die
                struct timeval current_time;
                gettimeofday(&current_time, NULL);
                long elapsed_time = (current_time.tv_sec - last_meal_time[philosopher_id].tv_sec) * 1000000 +
                                    (current_time.tv_usec - last_meal_time[philosopher_id].tv_usec);
                if (elapsed_time >= TIME_TO_DIE) {
                    printf("Philosopher %d died. Ending simulation.\n", philosopher_id);
                    exit(0);
                }
            } else {
                // Release right fork if left fork is not available
                pthread_mutex_unlock(&forks[right_fork]);
            }
        }

        // Sleeping before retrying
        usleep(500000); // sleep for 0.5 seconds
    }
}

int main() {
    // Initialize forks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    int philosopher_ids[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_thread, &philosopher_ids[i]);
    }

    // Wait for philosopher threads to finish (this won't happen in this example as threads are infinite)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
