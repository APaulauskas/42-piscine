# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 18:15:02 by apaulaus          #+#    #+#              #
#    Updated: 2018/07/19 15:28:39 by apaulaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_tail
SRC=tail.c ft_putchar.c ft_putstr.c ft_atoi.c ft_strncmp.c

all:
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) 

fclean: clean 
	rm -f $(NAME)	

clean: 
	rm -f *.o

re: fclean all
