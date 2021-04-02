/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:59:26 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 14:55:31 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "../share/share.h"
# define SEM_ID "/semid"

typedef struct s_philo_two
{
	int							id;
	unsigned long long			create_time;
	unsigned long long			last_eat_time;
	unsigned long long			time_to_die;
	unsigned long long			time_to_eat;
	unsigned long long			time_to_sleep;
	int							philo_max;
	int							num_of_eat;
	sem_t						*sem;
}								t_philo_two;

int				ft_get_sem(sem_t **sem, int nop);

#endif