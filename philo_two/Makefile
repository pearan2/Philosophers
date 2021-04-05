# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 05:28:05 by honlee            #+#    #+#              #
#    Updated: 2021/04/05 20:18:32 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					main.c\
					init.c\
					status.c\
					monitor_return.c\
					../share/ft_atoi.c\
					../share/ft_salloc.c\
					../share/ft_time_util1.c\
					../share/ft_input_checker.c\
					../share/ft_detach.c\
					
OBJS        =       ${SRCS:.c=.o}

INCDIR		=		./share/

NAME		=		philo_two

CC			=		clang

CF			=		-Wall -Wextra -Werror -I ${INCDIR} ${SRCS} -lpthread
DCF			=		-g -I ${INCDIR} ${SRCS} -lpthread

${NAME}     :       
					${CC} ${CF} -o ${NAME}

test		:		fclean
					${CC} ${DCF} -o ${NAME}

fclean		:		
					rm -f ${NAME}

clean       :               
					rm -f ${NAME}

re			:		fclean all

all         :      	${NAME}