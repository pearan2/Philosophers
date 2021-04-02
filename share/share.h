/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 05:07:10 by honlee            #+#    #+#             */
/*   Updated: 2021/04/02 14:20:55 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <semaphore.h>

int								ft_atoi(const char *str);
int								ft_salloc(void**target, int type_size, int alloc_size);
unsigned long long				ft_get_ms(void);
void							ft_sleep(unsigned long long s_time);
int								ft_input_checker(int ac, char **av);
int								ft_printf_error(char *str);
int								ft_detach_all(pthread_t *threads,
							int nop, unsigned long long nt);
int								ft_detach_all2(pthread_t *threads, int nop,
							int pn, unsigned long long nt);

#endif