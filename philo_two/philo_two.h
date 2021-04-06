/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:59:26 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 00:14:16 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "../share/share.h"
# define SEM_ID_FORK "/semid_fork"
# define SEM_ID_PRINT "/semid_print"
# define SEM_ID_LID	"/semid_lid"

typedef struct					s_base
{
	unsigned long long			create_time;
	unsigned long long			time_to_die;
	unsigned long long			time_to_eat;
	unsigned long long			time_to_sleep;
	int							philo_max;
	int							limit_eat;
	int							is_end;
	sem_t						*forks;
	sem_t						*printer;
	sem_t						*lid;
}								t_base;

typedef struct					s_philo
{
	int							id;
	int							num_of_eat;
	unsigned long long			last_eat_time;
	t_base						*base;
}								t_philo;

int								ft_get_sem(sem_t **sem,
									char *sem_name, int nop);
int								init_base(t_base *base, int ac, char **av);
int								init_philos(t_philo **philos, t_base *base);
void							philo_eat(t_philo *philo);
void							philo_sleep(t_philo *philo);
void							philo_think(t_philo *philo);
int								die_return(t_base *base, int id,
									unsigned long long nt, pthread_t *tids);
int								full_return(t_base *base, pthread_t *tids);

#endif
