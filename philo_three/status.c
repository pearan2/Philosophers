/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:57:06 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 00:15:40 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->base->lid);
	sem_wait(philo->base->forks);
	sem_wait(philo->base->printer);
	printf("%8llums %d has taken a fork 1\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	sem_post(philo->base->printer);
	sem_wait(philo->base->forks);
	sem_post(philo->base->lid);
	sem_wait(philo->base->printer);
	printf("%8llums %d has taken a fork 2\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	philo->num_of_eat++;
	if (philo->base->limit_eat != -1
		&& (philo->base->limit_eat <= philo->num_of_eat))
		sem_post(philo->base->is_full);
	printf("%8llums %d is eating : %d\n",
		ft_get_ms() - philo->base->create_time, philo->id, philo->num_of_eat);
	sem_post(philo->base->printer);
	philo->last_eat_time = ft_get_ms();
	ft_sleep(philo->base->time_to_eat);
	sem_post(philo->base->forks);
	sem_post(philo->base->forks);
}

void	philo_sleep(t_philo *philo)
{
	sem_wait(philo->base->printer);
	printf("%8llums %d is sleeping\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	sem_post(philo->base->printer);
	ft_sleep(philo->base->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	sem_wait(philo->base->printer);
	printf("%8llums %d is thinking\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	sem_post(philo->base->printer);
}
