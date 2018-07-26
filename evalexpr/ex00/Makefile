# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 18:15:02 by apaulaus          #+#    #+#              #
#    Updated: 2018/07/22 11:20:39 by apaulaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=eval_expr
SRC=main.c eval_expr.c stack.c number.c character.c operation.c shunting.c
OBJ=main.o eval_expr.o stack.o number.o character.o operation.o shunting.o

all:
	gcc -c $(SRC)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
