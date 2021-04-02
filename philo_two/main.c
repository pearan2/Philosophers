/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:15:36 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 14:47:01 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	init(t_philo_two **philos, pthread_t **threads, char **av)
{
	int					idx;
	sem_t				*sem;
	unsigned long long	nt;

	if (ft_get_sem(&sem, ft_atoi(av[1])) == -1
		|| ft_salloc((void **)threads, sizeof(pthread_t), ft_atoi(av[1])) != 0
		|| ft_salloc((void **)philos, sizeof(t_philo_two), ft_atoi(av[1])) != 0)
		return (1);
	idx = -1;
	nt = ft_get_ms();
	while (++idx < ft_atoi(av[1]))
	{
		(*philos)[idx].id = idx + 1;
		(*philos)[idx].time_to_die = ft_atoi(av[2]);
		(*philos)[idx].time_to_eat = ft_atoi(av[3]);
		(*philos)[idx].time_to_sleep = ft_atoi(av[4]);
		(*philos)[idx].philo_max = ft_atoi(av[1]);
		(*philos)[idx].num_of_eat = 0;
		(*philos)[idx].sem = sem;
		(*philos)[idx].create_time = nt;
		(*philos)[idx].last_eat_time = nt;
	}
	return (0);
}

void	*philo_loop(void *data)
{
	t_philo_two			*philo;
	unsigned long long	nt;

	philo = (t_philo_two *)data;
	while (1)
	{
		sem_wait(philo->sem);
		nt = ft_get_ms();
		philo->last_eat_time = nt;
		philo->num_of_eat++;
		printf("%llums %d takes forks and eat num: %d\n",
			nt - philo->create_time, philo->id + 1, philo->num_of_eat);
		ft_sleep(philo->time_to_eat);
		sem_post(philo->sem);
		printf("%llums %d eat finish\n",
			ft_get_ms() - philo->create_time, philo->id + 1);
		ft_sleep(philo->time_to_sleep);
		printf("%llums %d sleep finish and go to thinking\n",
			ft_get_ms() - philo->create_time, philo->id + 1);
	}
}

int	main_loop(t_philo_two *philos, int nop, int limit, pthread_t *threads)
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

int	main(int ac, char **av)
{
	t_philo_two			*philos;
	int					idx;
	pthread_t			*threads;

	if (ft_input_checker(ac, av) == 1
		|| init(&philos, &threads, av) != 0)
		return (1);
	idx = -1;
	while (++idx < ft_atoi(av[1]))
		pthread_create(&(threads[idx]), NULL, philo_loop, (void *)&philos[idx]);
	if (ac == 5)
		return (main_loop(philos, ft_atoi(av[1]), -1, threads));
	else
		return (main_loop(philos, ft_atoi(av[1]), ft_atoi(av[5]), threads));
}
