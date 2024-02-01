/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:06 by mman              #+#    #+#             */
/*   Updated: 2024/01/27 00:51:01 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// return The converted value or 0 on error.

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	return (result);
}

int	ft_mutex_trylock(t_custom_mutex *custom_mutex)
{
	if (custom_mutex->is_locked)
	{
		return (EBUSY);
	}

	pthread_mutex_lock(custom_mutex);
	return (0);
}

// int	ft_mutex_trylock(t_custom_mutex *mutex)
// {
// 	while (1)
// 	{
// 		if (pthread_mutex_lock(mutex) == 0)
// 			return (0);  // Successfully acquired the lock
// 		else if (errno == EBUSY)
// 			return (EBUSY);
// 		// continue ;  // The mutex is busy, continue spinning?
// 		else
// 			return (-1);  // An error occurred during locking

// 		// You can insert a short delay here if desired
// 		// to reduce CPU usage during the spinning loop.
// 		// For example: usleep(1000); // Sleep for 1 millisecond
// 	}
// }



long long int	ft_get_time(void)
{
	static struct timeval	start_time;
	static int				initialized;
	struct timeval			current_time;
	long long int			elapsed_time;

	initialized = 0;
	if (!initialized)
	{
		gettimeofday(&start_time, NULL);
		initialized = 1;
	}
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - start_time.tv_sec) * 1000
		+ (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (elapsed_time);
}
