/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:25 by mman              #+#    #+#             */
/*   Updated: 2024/02/01 15:18:25 by mman             ###   ########.fr       */
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

struct timeval last_meal_time[MAX_PHILOSOPHERS];

int	number_of_philosophers = 6;

void	*ft_philosopher_thread(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		ft_forks_try_state(p);
		if (1)
		{
			ft_eating_state(p->id);
			ft_sleep_state(p->id, p->instructions->time_to_sleep);
		}
		ft_thinking_state(p->id);
		ft_death_check(p->id);
		ft_ending(p); // if p->EATEN == max_eat(p.instructions.opt), we opt to end
	}
}

//checks for <number_of_philosophers (<=200)> <time_to_die> <time_to_eat>
// <time_to_sleep> and optionally <number_of_times_each_philosopher_must_eat>
void	ft_param_check(char *argv[])
{
	printf("%s", argv[0]);
}

static int	ft_leftfork(int philo, int number_of_philosophers)
{
	if (philo != 0)
		return (philo - 1);
	return (number_of_philosophers);
}

//create thread, make it run //join
void	ft_program(int argc, char *argv, t_custom_mutex	**forks)
{
	t_instru	*instructions;
	int			x;
	pthread_t	philosophers[MAX_PHILOSOPHERS];
	t_philo		*philosopher;
	int			number_of_philosophers;

	x = 0;
	philosopher = (t_philo *)malloc(MAX_PHILOSOPHERS * sizeof(t_philo));
	instructions = (t_instru *)malloc(sizeof(t_instru));
	number_of_philosophers = ft_atoi(argv[1]);
	instructions->time_to_die = ft_atoi(argv[2]);
	instructions->time_to_eat = ft_atoi(argv[3]);
	instructions->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		instructions->opt = ft_atoi(argv[5]);
	while (x <= number_of_philosophers)
	{
		philosopher[x].id = x;
		philosopher[x].instructions = &instructions;
		philosopher[x].fork_right = &forks[x % number_of_philosophers];
		philosopher[x].fork_left = forks[ft_leftfork(x,
				number_of_philosophers)];
		pthread_create(&philosophers[x], NULL,
			ft_philosopher_thread, &philosopher[x]);
		x++;
	}
	x = 0;
	while (x <= number_of_philosophers)
	{
		pthread_join(&philosophers[x], NULL);
		x++;
	}
	free(philosopher);
	free(instructions);
}

// destroy the mutex	// destroy the mutex
// join(?)
void	ft_cleanup(void)
{
	printf("cleanup\n");
}


//0 is typically reserved for the name of the program
int	main(int argc, char *argv[])
{
	t_custom_mutex	*forks[MAX_PHILOSOPHERS];
	int				philo_count;

	philo_count = ft_atoi(argv[1]);
	ft_param_check(argv);			//TODO
	ft_mutex_init_custom(&forks, philo_count);
	ft_program(argc, argv, &forks);
	ft_mutex_de_custom(&forks, philo_count);
	printf("%lli", ft_return_time());
	return (EXIT_SUCCESS);
}
