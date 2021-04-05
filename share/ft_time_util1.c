/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:14:47 by honlee            #+#    #+#             */
/*   Updated: 2021/04/05 11:38:44 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

unsigned long long	ft_get_ms(void)
{
	struct timeval		tv;
	unsigned long long	ret;

	gettimeofday(&tv, NULL);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}

void	ft_sleep(unsigned long long s_time)
{
	unsigned long long	start;

	start = ft_get_ms();
	while (ft_get_ms() - start < s_time)
	{
		usleep(100);
	}
	return ;
}
