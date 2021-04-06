/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:12:57 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 00:11:17 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "../share/share.h"

typedef struct					s_base
{
	unsigned long long			create_time;
	unsigned long long			time_to_die;
	unsigned long long			time_to_eat;
	unsigned long long			time_to_sleep;
	int							philo_max;
	int							limit_eat;
	int							is_end;
	pthread_mutex_t				*forks;
	pthread_mutex_t				printer;
}								t_base;

typedef struct					s_philo
{
	int							id;
	int							num_of_eat;
	unsigned long long			last_eat_time;
	int							lf_idx;
	int							rf_idx;
	t_base						*base;
}								t_philo;

int								init_base(t_base *base, int ac, char **av);
int								init_philos(t_philo **philos, t_base *base);
void							philo_eat(t_philo *philo);
void							philo_sleep(t_philo *philo);
void							philo_think(t_philo *philo);
int								die_return(t_base *base, int id,
									unsigned long long nt);
int								full_return(t_base *base);

#endif
