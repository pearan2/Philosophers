/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:12:57 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 14:41:21 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "../share/share.h"

typedef struct s_philo_one
{
	int							id;
	unsigned long long			create_time;
	unsigned long long			last_eat_time;
	unsigned long long			time_to_die;
	unsigned long long			time_to_eat;
	unsigned long long			time_to_sleep;
	int							philo_max;
	int							is_limit;
	int							num_of_eat;
	pthread_mutex_t				*forks;
}								t_philo_one;

int			ft_detach_all(pthread_t *threads, int nop, unsigned long long nt);
int			ft_detach_all2(pthread_t *threads, int nop,
				int pn, unsigned long long nt);

#endif