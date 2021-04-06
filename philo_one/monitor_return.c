/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:38:57 by honlee            #+#    #+#             */
/*   Updated: 2021/04/07 00:24:56 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	die_return(t_base *base, int id, unsigned long long nt)
{
	base->is_end = 1;
	printf("%8llums %d died\n", nt - base->create_time, id);
	ft_sleep(10);
	return (0);
}

int	full_return(t_base *base)
{
	base->is_end = 1;
	printf("All philosophers are full\n");
	ft_sleep(10);
	return (0);
}
