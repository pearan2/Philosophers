/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_salloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:36:30 by honlee            #+#    #+#             */
/*   Updated: 2021/03/30 05:36:53 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int     ft_salloc(void**target, int type_size, int alloc_size)
{
        if (type_size < 0 || alloc_size < 0)
                return (1);
        (*target) = malloc(type_size * alloc_size);
        if ((*target) == 0)
			return (1);
        return (0);
}