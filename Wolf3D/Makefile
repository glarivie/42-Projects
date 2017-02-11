# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 13:27:14 by glarivie          #+#    #+#              #
#    Updated: 2016/11/13 18:17:28 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

INCLUDES = "libft"

FLAGS = -Wall -Wextra -Werror

MLXFLA = -lmlx -framework OpenGL -framework AppKit

SRC = 	main.c init.c hook.c trace.c color.c draw.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)


$(NAME) :$(OBJ)
	make -C libft/
	$(CC) $(FLAGS) -o $(NAME) $(MLXFLA) $(OBJ) -lft -L ./libft -I $(INCLUDES)

all : $(NAME)

%.o:%.c
	gcc -c $(FLAGS) -I $(INCLUDES) $< -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
