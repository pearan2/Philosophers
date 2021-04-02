/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:32:39 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 13:11:27 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	ft_printf_error(char *str)
{
	printf("%s", str);
	return (1);
}

int	ft_input_checker(int ac, char **av)
{
	int		idx;

	if (ac < 5 || ac > 6)
		return (ft_printf_error("plz check input value\n"));
	if (ac == 6)
		if (ft_atoi(av[5]) < 0)
			return (ft_printf_error("plz check input value\n"));
	idx = 0;
	while (++idx < ac)
		if (ft_atoi(av[idx]) <= 0)
			return (ft_printf_error("plz check input value\n"));
	return (0);
}