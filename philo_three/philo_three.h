/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:52:58 by honlee            #+#    #+#             */
/*   Updated: 2021/04/06 19:46:54 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include "../share/share.h"
# define SEM_FORK_ID "/sem_fork"
# define SEM_DIE_ID	"/sem_die"
# define SEM_FULL_ID "/sem_full"
# define SEM_PRINTER_ID "/sem_printer"
# define SEM_LID_ID "/sem_lid"

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
	sem_t						*is_die;
	sem_t						*is_full;
	sem_t						*lid;
	int							*pids;
}								t_base;

typedef struct					s_philo
{
	int							id;
	int							num_of_eat;
	unsigned long long			last_eat_time;
	int							full;
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
