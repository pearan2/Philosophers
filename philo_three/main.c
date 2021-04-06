/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:15:36 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 00:16:16 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void				*monitor_die(void *data)
{
	t_philo				*philo;
	unsigned long long	nt;

	philo = (t_philo *)data;
	while (1)
	{
		sem_wait(philo->base->printer);
		nt = ft_get_ms();
		if (nt > philo->last_eat_time + philo->base->time_to_die)
		{
			philo->base->is_end = 1;
			printf("%8llums %d died\n", nt - philo->base->create_time,
				philo->id);
			sem_post(philo->base->is_die);
			exit(0);
		}
		sem_post(philo->base->printer);
	}
}

void				philo_loop(t_philo *philo)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, monitor_die, philo);
	while (1)
	{
		if (philo->base->is_end)
			break ;
		philo_eat(philo);
		if (philo->base->is_end)
			break ;
		philo_sleep(philo);
		if (philo->base->is_end)
			break ;
		philo_think(philo);
	}
	exit(0);
}

void				*monitor_die_all(void *data)
{
	t_base				*base;
	int					idx;

	base = (t_base *)data;
	sem_wait(base->is_die);
	idx = -1;
	while (++idx < base->philo_max)
		kill(base->pids[idx], SIGKILL);
	exit(0);
	return (NULL);
}

int					start_fork(t_philo *philos, t_base *base)
{
	int				idx;
	pthread_t		tid;

	idx = -1;
	while (++idx < base->philo_max)
	{
		base->pids[idx] = fork();
		if (base->pids[idx] == 0)
			philo_loop(&philos[idx]);
	}
	pthread_create(&tid, NULL, monitor_die_all, base);
	idx = -1;
	while (++idx < base->philo_max)
		sem_wait(base->is_full);
	sem_wait(base->printer);
	base->is_end = 1;
	printf("All philosophers eat\n");
	idx = -1;
	while (++idx < base->philo_max)
		kill(base->pids[idx], SIGKILL);
	return (0);
}

int					main(int ac, char **av)
{
	t_base			*base;
	t_philo			*philos;

	if (ft_input_checker(ac, av) != 0
		|| ft_salloc((void **)&base, sizeof(t_base), 1) != 0)
		return (1);
	if (init_base(base, ac, av) != 0)
		return (1);
	sem_wait(base->is_die);
	if (init_philos(&philos, base) != 0)
		return (1);
	return (start_fork(philos, base));
}
