# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sung-hle <sung-hle@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:11:14 by sung-hle          #+#    #+#              #
#    Updated: 2022/12/28 05:19:00 by sung-hle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	get_next_line.c	\
				get_next_line_utils.c
#SRCS_BONUS	= 
OBJS		= ${SRCS:.c=.o}
#OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
NAME		= get_next_line.a
CC			= cc -Wall -Wextra -Werror

%.o: %.c get_next_line.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} get_next_line.h
			ar rcs ${NAME} ${OBJS}

#bonus:		${OBJS} ${OBJS_BONUS} libft.h
#			ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:	
			rm -f ${NAME}

re:			fclean all


.PHONY:		all clean fclean re bonus $(NAME) 

