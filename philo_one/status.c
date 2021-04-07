/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:57:06 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 11:38:53 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->forks[philo->lf_idx]));
	pthread_mutex_lock(&(philo->base->printer));
	printf("%8llums %d has taken a fork 1\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	pthread_mutex_unlock(&(philo->base->printer));
	pthread_mutex_lock(&(philo->base->forks[philo->rf_idx]));
	pthread_mutex_lock(&(philo->base->printer));
	printf("%8llums %d has taken a fork 2\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	philo->num_of_eat++;
	printf("%8llums %d is eating : %d\n",
		ft_get_ms() - philo->base->create_time, philo->id, philo->num_of_eat);
	pthread_mutex_unlock(&(philo->base->printer));
	philo->last_eat_time = ft_get_ms();
	ft_sleep(philo->base->time_to_eat);
	pthread_mutex_unlock(&(philo->base->forks[philo->lf_idx]));
	pthread_mutex_unlock(&(philo->base->forks[philo->rf_idx]));
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->printer));
	printf("%8llums %d is sleeping\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	pthread_mutex_unlock(&(philo->base->printer));
	ft_sleep(philo->base->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->printer));
	printf("%8llums %d is thinking\n",
		ft_get_ms() - philo->base->create_time, philo->id);
	pthread_mutex_unlock(&(philo->base->printer));
}
