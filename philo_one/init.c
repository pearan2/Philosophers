/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:25:38 by honlee            #+#    #+#             */
/*   Updated: 2021/04/05 19:43:31 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	init_base(t_base *base, int ac, char **av)
{
	int					idx;
	pthread_mutex_t		*forks;

	if (ft_salloc((void **)&forks,
			sizeof(pthread_mutex_t), ft_atoi(av[1])) != 0)
		return (1);
	base->create_time = ft_get_ms();
	base->time_to_die = ft_atoi(av[2]);
	base->time_to_eat = ft_atoi(av[3]);
	base->time_to_sleep = ft_atoi(av[4]);
	base->philo_max = ft_atoi(av[1]);
	base->is_end = 0;
	base->limit_eat = -1;
	if (ac == 6)
		base->limit_eat = ft_atoi(av[5]);
	idx = -1;
	while (++idx < base->philo_max)
		if (pthread_mutex_init(&forks[idx], NULL) != 0)
			return (1);
	base->forks = forks;
	if (pthread_mutex_init(&(base->printer), NULL) != 0)
		return (1);
	return (0);
}

int	init_philos(t_philo **philos, t_base *base)
{
	int		idx;

	if (ft_salloc((void **)philos, sizeof(t_philo), base->philo_max) != 0)
		return (1);
	idx = -1;
	while (++idx < base->philo_max)
	{
		(*philos)[idx].id = idx + 1;
		(*philos)[idx].lf_idx = idx - 1;
		(*philos)[idx].rf_idx = idx;
		(*philos)[idx].last_eat_time = base->create_time;
		(*philos)[idx].num_of_eat = 0;
		if ((*philos)[idx].lf_idx < 0)
			(*philos)[idx].lf_idx = base->philo_max - 1;
		(*philos)[idx].base = base;
	}
	return (0);
}
