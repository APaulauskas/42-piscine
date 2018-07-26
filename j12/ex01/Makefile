# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 18:15:02 by apaulaus          #+#    #+#              #
#    Updated: 2018/07/18 20:11:55 by apaulaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_cat
SRC=cat.c ft_putchar.c ft_putstr.c

all:
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) 

fclean: clean 
	rm -f $(NAME)	

clean: 
	rm -f *.o

re: fclean all
