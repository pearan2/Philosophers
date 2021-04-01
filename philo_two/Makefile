# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 05:28:05 by honlee            #+#    #+#              #
#    Updated: 2021/04/01 16:16:10 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					main.c\
					../share/ft_atoi.c\
					../share/ft_salloc.c\
					../share/ft_time_util1.c\

OBJS        =       ${SRCS:.c=.o}

INCDIR		=		./share/

NAME		=		philo_two

CC			=		clang

CF			=		-Wall -Wextra -Werror -I ${INCDIR} ${SRCS} -lpthread
DCF			=		-g -I ${INCDIR} ${SRCS} -lpthread

${NAME}     :       
					${CC} ${CF} -o ${NAME}

fclean		:		
					rm -f ${NAME}

clean       :               
					rm -f ${NAME}

re			:		fclean all

all         :      	${NAME}