/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:42:29 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 13:42:38 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	ft_detach_all(pthread_t *threads, int nop, unsigned long long nt)
{
	int		idx;

	idx = -1;
	printf("%llums all philosophers eat\n", nt);
	while (++idx < nop)
	{
		pthread_detach(threads[idx]);
	}
	return (0);
}

int	ft_detach_all2(pthread_t *threads, int nop, int pn, unsigned long long nt)
{
	int		idx;

	idx = -1;
	printf("%llums %d die\n", nt, pn);
	while (++idx < nop)
	{
		pthread_detach(threads[idx]);
	}
	return (0);
}
