/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:44:46 by mman              #+#    #+#             */
/*   Updated: 2024/01/27 01:20:34 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_left_subprocess(t_custom_mutex forks, int philosopher_id)
{
	long long int	time;
	int				left_fork;
	int				right_fork;
	int				number_of_philosophers;

	number_of_philosophers = ft_get_p(forks);
	left_fork = philosopher_id - 1;
	right_fork = philosopher_id % number_of_philosophers;
	time = ft_get_time();
	if (ft_mutex_trylock(&forks[left_fork]) == 0)
	{
		if (ft_mutex_trylock(&forks[right_fork]) == 0)
		{
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, philosopher_id);
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, philosopher_id);
			return (1);
		}
		else
			ft_mutex_unlock(&forks[left_fork]);
	}
	return (0);
}

int	ft_right_sub(pthread_t forks, int philosopher_id)
{
	long long int	time;
	int				left_fork;
	int				right_fork;
	int				number_of_philosophers;

	number_of_philosophers = ft_get_p(forks);
	left_fork = philosopher_id - 1;
	right_fork = philosopher_id % number_of_philosophers;
	time = ft_get_time();
	if (ft_mutex_trylock(&forks[right_fork]) == 0)
	{
		if (ft_mutex_trylock(&forks[left_fork]) == 0)
		{
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, philosopher_id);
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, philosopher_id);
			return (1);
		}
		else
			ft_mutex_unlock(&forks[right_fork]);
	}
	return (0);
}

int	ft_forks_try_state(pthread_t forks, int philosopher_id)
{
	if (ft_left_subprocess(forks, philosopher_id) == 1)
		return (1);
	else
	{
		if (ft_right_sub(forks, philosopher_id) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}
