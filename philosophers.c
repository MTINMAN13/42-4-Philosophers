/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:25 by mman              #+#    #+#             */
/*   Updated: 2024/01/27 01:20:05 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*

Any state change of a philosopher must be formatted as follows:
◦timestamp_in_ms X has taken a fork
◦timestamp_in_ms X is eating
◦timestamp_in_ms X is sleeping
◦timestamp_in_ms X is thinking
◦timestamp_in_ms X died
*/

pthread_mutex_t forks[MAX_PHILOSOPHERS] = { PTHREAD_MUTEX_INITIALIZER };
pthread_t philosophers[MAX_PHILOSOPHERS];
struct timeval last_meal_time[MAX_PHILOSOPHERS];

int	number_of_philosophers = 6;

void	*ft_philosopher_thread(void *arg, pthread_mutex_t forks
	, pthread_t philosophers)
{
	int			philosopher_id;

	philosopher_id = *(int *)arg + 1;
	while (1)
	{
		ft_forks_try_state(forks, philosopher_id);
		if (1)
		{
			ft_eating_state(philosopher_id);
			// ft_forks_release();
			ft_sleep_state(philosopher_id, time_to_sleep);
		}
		ft_thinking_state(philosopher_id);
		ft_death_check(philosopher_id);
		ft_ending(philosopher_id);
	}
}

int	main(void)
{
	printf("%lli", ft_return_time());
	return (EXIT_SUCCESS);
}
