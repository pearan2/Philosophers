/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:38:57 by honlee            #+#    #+#             */
/*   Updated: 2021/04/05 21:25:00 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	die_return(t_base *base, int id, unsigned long long nt, pthread_t *tids)
{
	int		idx;

	base->is_end = 1;
	printf("%8llums %d died\n", nt - base->create_time, id);
	idx = -1;
	while (++idx < base->philo_max)
		pthread_detach(tids[idx]);
	return (0);
}

int	full_return(t_base *base, pthread_t *tids)
{
	int		idx;

	base->is_end = 1;
	printf("All philosophers is full\n");
	idx = -1;
	while (++idx < base->philo_max)
		pthread_detach(tids[idx]);
	return (0);
}
