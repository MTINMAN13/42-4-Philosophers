/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_trylocks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:05:35 by mman              #+#    #+#             */
/*   Updated: 2024/02/01 14:09:51 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_trylock(t_custom_mutex *custom_mutex)
{
	if (custom_mutex->is_locked)
	{
		return (EBUSY);
	}

	custom_mutex->is_locked = 1;
	pthread_mutex_lock(custom_mutex->mutex);
	return (0);
}

int	ft_mutexunlock(t_custom_mutex *custom_mutex)
{
	custom_mutex->is_locked = 0;
	pthread_mutex_unlock(custom_mutex->mutex);
	return (0);
}

void	ft_mutex_de_custom(t_custom_mutex	**forks, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_destroy(&forks[i]->mutex);
		forks[i]->is_locked = 0;
		free(forks[i]);
		i++;
	}
	printf("Destroyed all %i custom fork (mutexei)");
}

void	ft_mutex_init_custom(t_custom_mutex	**forks, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		forks[i] = (t_custom_mutex *)malloc(sizeof(t_custom_mutex));
		if (forks[i] == NULL)
			printf("Malloc ERROR!\n\n");
		pthread_mutex_init(&forks[i]->mutex, NULL);
		forks[i]->is_locked = 0;
		i++;
	}
	printf("Initialized all %i custom fork (mutexei)", philo_count);
}
