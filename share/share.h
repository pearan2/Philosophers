/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:07:10 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 20:43:05 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct		s_philo_one
{
	int				id;
	long			last_eat_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				philo_max;
	pthread_mutex_t	*forks;
}					t_philo_one;

int					ft_atoi(const char *str);
int					ft_salloc(void**target, int type_size, int alloc_size);

#endif