/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:07:10 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 06:21:38 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct		s_philo
{
	size_t			id;
	size_t			last_eat_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				*forks;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_salloc(void**target, int type_size, int alloc_size);

#endif