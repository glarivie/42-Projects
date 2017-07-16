# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 17:44:01 by glarivie          #+#    #+#              #
#    Updated: 2017/07/16 18:06:37 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf

CC = clang

INCLUDES = -I libft -I includes

FLAGS = -Wall -Wextra -Werror

SRC = 	src/buffer.c	\
		src/ft_printf.c	\
		src/main.c		\
		src/to_upper.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/
	$(CC) $(FLAGS) $(LIBFT) $(SRC) -o $(NAME) $(INCLUDES)

all : $(NAME)

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
