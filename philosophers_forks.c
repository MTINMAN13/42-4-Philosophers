/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:44:46 by mman              #+#    #+#             */
/*   Updated: 2024/02/01 15:30:06 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_left_subprocess(t_philo *p)
{
	size_t			time;

	time = ft_get_time();
	if (ft_trylock(&p->fork_left) == 0)
	{
		if (ft_trylock(&p->fork_right) == 0)
		{
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, p->id);
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, p->id);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	ft_right_subprocess(t_philo *p)
{
	size_t			time;

	time = ft_get_time();
	if (ft_trylock(&p->fork_left) == 0)
	{
		if (ft_trylock(&p->fork_right) == 0)
		{
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, p->id);
			time = ft_get_time();
			print("%lli %i  has taken a fork\n", time, p->id);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	ft_forks_try_state(t_philo *p)
{
	while (1)
	{
		if (ft_left_subprocess(p) == 1)
			return (1);
		else
		{
			if (ft_right_subprocess(p) == 1)
				return (1);
			else
				return (0);
		}
		return (0);
	}
}
