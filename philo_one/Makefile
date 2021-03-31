# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 05:28:05 by honlee            #+#    #+#              #
#    Updated: 2021/03/30 20:19:28 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					main.c\
					../share/ft_atoi.c\
					../share/ft_salloc.c\

OBJS        =       ${SRCS:.c=.o}

INCDIR		=		./share/

NAME		=		philo_one

CC			=		clang

CF			=		-Wall -Wextra -Werror -I ${INCDIR} ${SRCS} -lpthread
DCF			=		-g -I ${INCDIR} ${SRCS} -lpthread

${NAME}     :       
					${CC} ${CF} -o ${NAME}

test		:		fclean
					${CC} ${DCF} -o ${NAME}
					lldb philo_one -- 2 310 100 100

fclean		:		
					rm -f ${NAME}

clean       :               
					rm -f ${NAME}

re			:		fclean all

all         :      	${NAME}