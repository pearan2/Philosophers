/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:59:12 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 14:36:48 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ft_get_sem(sem_t **sem, int nop)
{
	sem_t			*temp;

	sem_unlink(SEM_ID);
	temp = sem_open(SEM_ID, O_CREAT | O_EXCL, 0644, nop / 2);
	if (temp == SEM_FAILED)
		return (-1);
	*sem = temp;
	return (0);
}
