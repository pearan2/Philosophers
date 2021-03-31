/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:19:54 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 20:48:53 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../share/share.h"

void*	philo_loop(void *data)
{
	t_philo_one 		*philo;
	int					left_idx;
	int					right_idx;
	struct timeval		tv;

	philo = (t_philo_one *)data;
	left_idx = philo->id - 1;
	right_idx = philo->id;
	if (left_idx < 0)
		left_idx = philo->philo_max - 1;
	while (1)
	{
		pthread_mutex_lock(&(philo->forks[left_idx]));
		pthread_mutex_lock(&(philo->forks[right_idx]));
		gettimeofday(&tv, NULL);
		printf("%ldms %d takes fork\n", tv.tv_usec, philo->id + 1);
		usleep(philo->time_to_eat * 1000);
		gettimeofday(&tv, NULL);
		philo->last_eat_time = tv.tv_usec;
		printf("%ldms %d eat\n", tv.tv_usec, philo->id + 1);
		pthread_mutex_unlock(&(philo->forks[left_idx]));
		pthread_mutex_unlock(&(philo->forks[right_idx]));
		usleep(philo->time_to_sleep * 1000);
		gettimeofday(&tv, NULL);
		printf("%ldms %d sleep finish and go to thinking\n", tv.tv_usec, philo->id + 1);
	}
}

int	main_loop(t_philo_one *philos, int nop)
{
	struct timeval		tv;
	int					idx;

	idx = -1;
	while (1)
	{
		++idx;
		gettimeofday(&tv, NULL);
		if (tv.tv_usec - philos[idx].last_eat_time > philos[idx].time_to_die  * 1000)
		{
			printf("%ldms %d die\n",tv.tv_usec, idx + 1);
			return (0);
		}
		if (idx == nop - 1)
			idx = -1;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pthread_mutex_t		*forks;
	t_philo_one			*philos;
	int					idx;
	pthread_t 			p_thread;
	struct timeval		tv;

	idx = -1;
	if (ac < 5)
		return (1);
	if (ft_salloc((void **)&forks, sizeof(pthread_mutex_t), ft_atoi(av[1])) != 0)
		return (1);
	if (ft_salloc((void **)&philos, sizeof(t_philo_one), ft_atoi(av[1])) != 0)
		return (1);
	while (++idx < ft_atoi(av[1]))
		if (pthread_mutex_init(&forks[idx], NULL) != 0)
			return (1);
	idx = -1;
	gettimeofday(&tv, NULL);
	while (++idx < ft_atoi(av[1]))
	{
		philos[idx].id = idx;
		philos[idx].time_to_die = ft_atoi(av[2]);
		philos[idx].time_to_eat = ft_atoi(av[3]);
		philos[idx].time_to_sleep = ft_atoi(av[4]);
		philos[idx].last_eat_time = tv.tv_usec;
		philos[idx].forks = forks;
		philos[idx].philo_max = ft_atoi(av[1]);
		pthread_create(&p_thread, NULL, philo_loop, (void *)&philos[idx]);
	}
	return (main_loop(philos, ft_atoi(av[1])));
}