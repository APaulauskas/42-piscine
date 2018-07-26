# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 20:45:58 by apaulaus          #+#    #+#              #
#    Updated: 2018/07/25 16:51:16 by apaulaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq
SRC=main.c bsq.c list.c number.c map.c character.c input.c
OBJ=main.o bsq.o list.o number.o map.o character.o input.o
HEADERS=headers

all: $(NAME) clean

$(NAME):
	gcc -Wall -Wextra -Werror -I$(HEADERS) -c $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
