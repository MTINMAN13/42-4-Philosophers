/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:06:34 by mman              #+#    #+#             */
/*   Updated: 2024/01/27 01:14:20 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/time.h>
# include <errno.h>

# define MAX_PHILOSOPHERS 10

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				is_locked;
}	t_custom_mutex;

// typedef pthread_mutex_t	t_custom_mutex;

// util
int				ft_atoi(const char *str);
long long int	ft_get_time(void);
int				ft_mutex_trylock(t_custom_mutex *custom_mutex);


//  BIG FUNCTIONS
// states
void			ft_thinking_state(int philosopher_id);

// -f



#endif
