/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:15:36 by honlee            #+#    #+#             */
/*   Updated: 2021/04/05 22:11:43 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*philo_loop(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (philo->base->is_end != 0)
			break ;
		philo_eat(philo);
		if (philo->base->is_end != 0)
			break ;
		philo_sleep(philo);
		if (philo->base->is_end != 0)
			break ;
		philo_think(philo);
	}
	return (NULL);
}

int	monitor_loop(t_philo *philos, t_base *base, pthread_t *tids)
{
	int						idx;
	unsigned long long		nt;
	int						sum;

	while (1)
	{
		idx = -1;
		sum = 0;
		sem_wait(base->printer);
		nt = ft_get_ms();
		while (++idx < base->philo_max)
		{
			if (nt > philos[idx].last_eat_time + base->time_to_die)
				return (die_return(base, philos[idx].id, nt, tids));
			if (base->limit_eat != -1
				&& philos[idx].num_of_eat >= base->limit_eat)
				sum++;
			if (sum == base->philo_max - 1)
				return (full_return(base, tids));
		}
		sem_post(base->printer);
	}
}

int	main(int ac, char **av)
{
	t_base			*base;
	t_philo			*philos;
	pthread_t		*tids;
	int				idx;

	if (ft_input_checker(ac, av) != 0
		|| ft_salloc((void **)&tids, sizeof(pthread_t), ft_atoi(av[1])) != 0
		|| ft_salloc((void **)&base, sizeof(t_base), 1) != 0)
		return (1);
	if (init_base(base, ac, av) != 0)
		return (1);
	if (init_philos(&philos, base) != 0)
		return (1);
	idx = -1;
	while (++idx < base->philo_max)
		pthread_create(&(tids[idx]), NULL, philo_loop, (void *)&(philos[idx]));
	return (monitor_loop(philos, base, tids));
}
