/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:29:16 by honlee            #+#    #+#             */
/*   Updated: 2021/04/06 19:47:28 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_get_sem(sem_t **sem, char *sem_id, int nop)
{
	sem_t			*temp;

	sem_unlink(sem_id);
	temp = sem_open(sem_id, O_CREAT | O_EXCL, 0644, nop);
	if (temp == SEM_FAILED)
		return (-1);
	*sem = temp;
	return (0);
}

int	init_base(t_base *base, int ac, char **av)
{
	int					idx;

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
	if (ft_salloc((void **)&base->pids, sizeof(int), base->philo_max) != 0)
		return (1);
	if (ft_get_sem(&base->forks, SEM_FORK_ID, base->philo_max) != 0
		|| ft_get_sem(&base->printer, SEM_PRINTER_ID, 1) != 0
		|| ft_get_sem(&base->is_die, SEM_DIE_ID, 1) != 0
		|| ft_get_sem(&base->is_full, SEM_FULL_ID, base->philo_max) != 0
		|| ft_get_sem(&base->lid, SEM_LID_ID, 1) != 0)
		return (1);
	while (++idx < base->philo_max)
		sem_wait(base->is_full);
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
		(*philos)[idx].last_eat_time = base->create_time;
		(*philos)[idx].num_of_eat = 0;
		(*philos)[idx].base = base;
		(*philos)[idx].full = 0;
	}
	return (0);
}
