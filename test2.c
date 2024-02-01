/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:31:16 by mman              #+#    #+#             */
/*   Updated: 2024/02/01 09:39:52 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

MAX_PHILOSOPHERS = 200;

//custom implement t_pthread_mutex for lock usage (obvioouslyyy)

struct define s_philo
{
	pthread_mutex_t	*forks;
	int				philosopher_id;
}	t_philo_args_;

int	main(int argc, char *argv[])
{
	pthread_mutex_t	forks[MAX_PHILOSOPHERS];

	forks = {PTHREAD_MUTEX_INITIALIZER};
    if (argc >= 5) {
        number_of_philosophers = atoi(argv[1]);
        time_to_die = atol(argv[2]);
        time_to_eat = atol(argv[3]);
        time_to_sleep = atol(argv[4]);
        number_of_times_each_philosopher_must_eat = atoi(argv[5]);
		eat_counter = calloc(MAX_PHILOSOPHERS, sizeof(int));
    } else {
        printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> and optionally <number_of_times_each_philosopher_must_eat>\n", argv[0]);
        return 1;
    }

    if (number_of_philosophers > MAX_PHILOSOPHERS || number_of_philosophers < 1) {
        printf("Invalid number of philosophers. Must be between 1 and %d.\n", MAX_PHILOSOPHERS);
        return 1;
    }

    int philosopher_ids[MAX_PHILOSOPHERS];
	t_philo_args_ *thread_args;

    for (int i = 0; i < number_of_philosophers; i++) {
        philosopher_ids[i] = i;

        // Allocate memory for thread arguments
        thread_args = t_philo_args_ *)malloc(sizeof	t_philo_args_));
        thread_args->forks = forks; // Pass the array of forks
        thread_args->philosopher_id = i + 1; // Adjust philosopher_id to start from 1

        // Pass thread_args as the argument to pthread_create
        pthread_create(&philosophers[i], NULL, philosopher_thread, thread_args);
    }

    for (int i = 0; i < number_of_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // ... (free any other allocated resources)

    return 0;
}
