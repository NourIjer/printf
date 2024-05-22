# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nijer <nijer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 18:20:24 by nijer             #+#    #+#              #
#    Updated: 2024/03/12 18:20:28 by nijer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putnbr.c ft_puthexa.c

OBJS =	$(SRCS:.c=.o)

CC =	cc

RM =	rm -f

CFLAGS =	-c -Wall -Wextra -Werror

NAME =	libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c	ft_printf.h
	$(CC) $(CFLAGS) $<

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re