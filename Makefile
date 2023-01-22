# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sung-hle <sung-hle@42student.berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:11:14 by sung-hle          #+#    #+#              #
#    Updated: 2022/12/23 17:02:01 by sung-hle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	get_next_line_utils.c \
				*get_next_line.c

OBJS		= ${SRCS:.c=.o}

NAME		= get_next_line.a
CC			= cc -Wall -Wextra -Werror -D BUFFER_SIZE=5
# -g

%.o: %.c libft.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} get_next_line.h
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all


.PHONY:		all clean fclean re bonus $(NAME) 

