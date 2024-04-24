# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:48:59 by ykulkarn          #+#    #+#              #
#    Updated: 2022/12/13 17:10:55 by ykulkarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

SRCS 	=	main.c create.c dine.c close_program.c time.c print.c
			

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