/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:06:34 by mman              #+#    #+#             */
/*   Updated: 2024/02/01 15:12:04 by mman             ###   ########.fr       */
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
	pthread_mutex_t	*mutex;
	int				is_locked;
}	t_custom_mutex;

typedef struct s_philo_instructions
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	opt;
}		t_instru;

typedef struct s_philo
{
	t_instru		*instructions;
	t_custom_mutex	*fork_left;
	t_custom_mutex	*fork_right;
	int				currently; // 1 is eating // 2 is sleeping // 3 is thinking // 0 is dead
	int				id;
	int				eaten;
	int				max_eat;
	size_t			last_meal_timestamp;
	int				total_philos_number;
}	t_philo;

// typedef pthread_mutex_t	t_custom_mutex;

// util
int				ft_atoi(const char *str);
int				ft_trylock(t_custom_mutex *custom_mutex);
int				ft_mutexunlock(t_custom_mutex *custom_mutex);
// initialize mutex, destroy mutex
void			ft_mutex_init_custom(t_custom_mutex	**forks, int philo_count);
void			ft_mutex_de_custom(t_custom_mutex	**forks, int philo_count);
// time
int				ft_usleep(size_t milliseconds);
size_t			ft_get_current_time(void);
size_t			ft_get_time(void);


//  BIG FUNCTIONS
// states
void			ft_thinking_state(int philosopher_id);

// -f



#endif
