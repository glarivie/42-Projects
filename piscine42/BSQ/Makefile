# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 10:52:03 by glarivie          #+#    #+#              #
#    Updated: 2015/08/27 22:58:45 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/main.c \
	   srcs/ft_atoi.c \
	   srcs/ft_check.c \
	   srcs/ft_check_square.c \
	   srcs/ft_check_tab.c \
	   srcs/ft_fill_square.c \
	   srcs/ft_free_bsq.c \
	   srcs/ft_get_bsq.c \
	   srcs/ft_get_infos.c \
	   srcs/ft_get_swap.c \
	   srcs/ft_isspace.c \
	   srcs/ft_print_bsq.c \
	   srcs/ft_read.c \
	   srcs/ft_sqrt.c \
	   srcs/ft_wait_args.c \
	   srcs/ft_loop_bsq.c

HEADERS = includes/

CFLAGS = -Wall -Wextra -Werror -I$(HEADERS)

CC = gcc

TMP = swap

all: $(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
		rm -f $(TMP)

fclean: clean
		rm -f $(NAME)

re: fclean all
