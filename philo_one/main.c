/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:19:54 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 06:24:12 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../share/share.h"

void*	philo_loop(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
}

int	main_loop(t_philo *philos, int nop)
{
	struct timeval		tv;

	while (1)
	{
		gettimeofday(&tv, NULL);
		printf("ms : %ld\n",tv.tv_sec);
		usleep(1000 * 1000);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		*forks;
	t_philo	*philos;
	int		idx;

	idx = -1;
	if (ac < 5)
		return (1);
	if (ft_salloc((void **)&forks, sizeof(int), ft_atoi(av[1])) != 0)
		return (1);
	if (ft_salloc((void **)&philos, sizeof(t_philo), ft_atoi(av[1])) != 0)
		return (1);
	while (++idx < ft_atoi(av[1]))
	{
		philos[idx].id = idx;
		philos[idx].time_to_die = ft_atoi(av[2]);
		philos[idx].time_to_eat = ft_atoi(av[3]);
		philos[idx].time_to_sleep = ft_atoi(av[4]);
		philos[idx].forks = forks;
		//pthread_create(NULL, NULL, philo_loop, (void *)&philos[idx]);
	}
	return (main_loop(philos, ft_atoi(av[1])));
}