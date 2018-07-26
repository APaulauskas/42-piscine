# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 18:15:02 by apaulaus          #+#    #+#              #
#    Updated: 2018/07/16 18:52:19 by apaulaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=do-op
SRC=do_op.c ft_atoi.c ft_add.c ft_sub.c ft_mul.c ft_div.c ft_mod.c ft_putnbr.c \
	ft_putstr.c ft_putchar.c ft_strcmp.c

all:
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
