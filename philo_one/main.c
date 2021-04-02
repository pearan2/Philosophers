/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:19:54 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 12:58:36 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_set_fork_idx(int *left, int *right, t_philo_one *philo)
{
	int					left_idx;
	int					right_idx;

	left_idx = philo->id - 1;
	right_idx = philo->id;
	if (left_idx < 0)
		left_idx = philo->philo_max - 1;
	*left = left_idx;
	*right = right_idx;
}

void	*philo_loop(void *data)
{
	t_philo_one			*philo;
	int					left_idx;
	int					right_idx;
	unsigned long long	nt;

	philo = (t_philo_one *)data;
	philo_set_fork_idx(&left_idx, &right_idx, philo);
	while (1)
	{
		pthread_mutex_lock(&(philo->forks[left_idx]));
		pthread_mutex_lock(&(philo->forks[right_idx]));
		nt = ft_get_ms();
		philo->last_eat_time = nt;
		philo->num_of_eat++;
		printf("%llums %d takes forks and eat num: %d\n",
			nt - philo->create_time, philo->id + 1, philo->num_of_eat);
		ft_sleep(philo->time_to_eat);
		pthread_mutex_unlock(&(philo->forks[left_idx]));
		pthread_mutex_unlock(&(philo->forks[right_idx]));
		printf("%llums %d eat finish\n",
			ft_get_ms() - philo->create_time, philo->id + 1);
		ft_sleep(philo->time_to_sleep);
		printf("%llums %d sleep finish and go to thinking\n",
			ft_get_ms() - philo->create_time, philo->id + 1);
	}
}

int	main_loop(t_philo_one *philos, int nop, int limit, pthread_t *threads)
{
	unsigned long long	nt;
	int					idx;
	int					sum;

	idx = -1;
	sum = 0;
	while (++idx < nop)
	{
		nt = ft_get_ms();
		if (nt - philos[idx].last_eat_time > philos[idx].time_to_die)
			return (ft_detach_all2(threads, nop, idx + 1,
					nt - philos[idx].create_time));
		if (limit != -1 && philos[idx].num_of_eat >= limit)
			sum++;
		if (sum == nop)
			return (ft_detach_all(threads, nop, nt - philos[idx].create_time));
		if (idx == nop - 1)
		{
			idx = -1;
			sum = 0;
		}
	}
	return (0);
}

int	init(pthread_mutex_t **forks, t_philo_one **philos, int num, char **av)
{
	int	idx;

	if (ft_salloc((void **)forks, sizeof(pthread_mutex_t), num) != 0)
		return (1);
	if (ft_salloc((void **)philos, sizeof(t_philo_one), num) != 0)
		return (1);
	idx = -1;
	while (++idx < num)
	{
		(*philos)[idx].forks = *forks;
		(*philos)[idx].time_to_die = ft_atoi(av[2]);
		(*philos)[idx].time_to_eat = ft_atoi(av[3]);
		(*philos)[idx].time_to_sleep = ft_atoi(av[4]);
		(*philos)[idx].philo_max = num;
		(*philos)[idx].num_of_eat = 0;
		(*philos)[idx].is_limit = 0;
	}
	idx = -1;
	while (++idx < num)
		if (pthread_mutex_init(&((*forks)[idx]), NULL) != 0)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	pthread_mutex_t		*forks;
	t_philo_one			*philos;
	int					idx;
	pthread_t			*threads;
	unsigned long long	nt;

	if (ft_input_checker(ac, av) == 1
		|| init(&forks, &philos, ft_atoi(av[1]), av) == 1
		|| ft_salloc((void **)&threads, sizeof(pthread_t), ft_atoi(av[1])) != 0)
		return (1);
	idx = -1;
	nt = ft_get_ms();
	while (++idx < ft_atoi(av[1]))
	{
		philos[idx].id = idx;
		philos[idx].last_eat_time = nt;
		philos[idx].create_time = nt;
		if (ac == 6)
			philos[idx].is_limit = 1;
		pthread_create(&(threads[idx]), NULL, philo_loop, (void *)&philos[idx]);
	}
	if (ac == 5)
		return (main_loop(philos, ft_atoi(av[1]), -1, threads));
	else
		return (main_loop(philos, ft_atoi(av[1]), ft_atoi(av[5]), threads));
}
