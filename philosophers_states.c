/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_states.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:44:53 by mman              #+#    #+#             */
/*   Updated: 2024/01/27 00:44:55 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eating_state(int philosopher_id)
{
	long long int	time;

	time = ft_get_time();
	print("%lli %i is eating\n", time, philosopher_id);

}

void	ft_thinking_state(int philosopher_id)
{
	long long int	time;

	time = ft_get_time();
	print("%lli %i is thinking\n", time, philosopher_id);
}


void	ft_death_check(int philosopher_id)
{
	long long int	time;

	time = ft_get_time();
	print("%lli %i died\n", time, philosopher_id);
}

void	ft_ending(int philosopher_id)
{
	long long	time;

	time = ft_get_time();
	print("%lli", time);

}


void	ft_sleep_state(int philosopher_id, int duration)
{
	long long int	time;

	time = ft_get_time();
	print("%lli ", time);
	print("Philosopher %d is sleeping.\n", philosopher_id);
	usleep(duration);
}
