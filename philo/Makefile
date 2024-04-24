# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykulkarn <ykulkarn@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:09:13 by ykulkarn          #+#    #+#              #
#    Updated: 2022/12/14 00:05:24 by ykulkarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS 	=	main.c create.c dine.c close_program.c time.c print.c eat.c
			

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -g3
TFLAGS	=	-lpthread

$(NAME):	$(OBJS)
			 $(CC) $(SRCS) $(CFLAGS) $(TFLAGS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re%