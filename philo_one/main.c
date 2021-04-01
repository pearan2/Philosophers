/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:19:54 by honlee            #+#    #+#             */
/*   Updated: 2021/04/01 12:13:58 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../share/share.h"

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
	philo->create_time = philo->last_eat_time;
	while (1)
	{
		pthread_mutex_lock(&(philo->forks[left_idx]));
		pthread_mutex_lock(&(philo->forks[right_idx]));
		nt = ft_get_ms();
		printf("%llums %d takes forks\n",
			nt - philo->create_time, philo->id + 1);
		philo->last_eat_time = nt;
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

int	main_loop(t_philo_one *philos, int nop)
{
	unsigned long long	nt;
	int					idx;

	idx = -1;
	while (1)
	{
		++idx;
		nt = ft_get_ms();
		if (nt - philos[idx].last_eat_time > philos[idx].time_to_die)
		{
			printf("%llums %d die\n", nt - philos[idx].create_time, idx + 1);
			return (0);
		}
		if (idx == nop - 1)
			idx = -1;
	}
	return (0);
}

int	init(pthread_mutex_t **forks, t_philo_one **philos, int num)
{
	int	idx;

	idx = -1;
	if (ft_salloc((void **)forks, sizeof(pthread_mutex_t), num) != 0)
		return (1);
	if (ft_salloc((void **)philos, sizeof(t_philo_one), num) != 0)
		return (1);
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
	pthread_t			p_thread;
	unsigned long long	nt;

	if (ac < 5 || init(&forks, &philos, ft_atoi(av[1])) == 1)
		return (1);
	idx = -1;
	nt = ft_get_ms();
	while (++idx < ft_atoi(av[1]))
	{
		philos[idx].id = idx;
		philos[idx].time_to_die = ft_atoi(av[2]);
		philos[idx].time_to_eat = ft_atoi(av[3]);
		philos[idx].time_to_sleep = ft_atoi(av[4]);
		philos[idx].last_eat_time = nt;
		philos[idx].forks = forks;
		philos[idx].philo_max = ft_atoi(av[1]);
		pthread_create(&p_thread, NULL, philo_loop, (void *)&philos[idx]);
	}
	return (main_loop(philos, ft_atoi(av[1])));
}
