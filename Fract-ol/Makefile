# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 08:44:38 by glarivie          #+#    #+#              #
#    Updated: 2016/01/22 09:58:39 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

SRCS = ./srcs/main.c				\
	   ./srcs/instructions.c		\
	   ./srcs/analyse_arg.c			\
	   ./srcs/mlx.c					\
	   ./srcs/img_pixel_put.c		\
	   ./srcs/set_julia.c			\
	   ./srcs/key_hook.c			\
	   ./srcs/mouse_motion_hook.c	\
	   ./srcs/julia.c				\
	   ./srcs/set_mandelbrot.c		\
	   ./srcs/set_manu.c			\
	   ./srcs/mandelbrot.c			\
	   ./srcs/manu.c				\
	   ./srcs/hsv_to_rgb.c			\
	   ./srcs/rgb_to_int.c			\
	   ./srcs/mouse_key_hook.c

OBJ = ./*.o

FLAGS = -Wall -Werror -Wextra

HEADER = -I ./includes/ -I ./libft/

FRAMEWORK = -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

X11 = -I /usr/X11/includes -g -L /usr/X11/lib

LIB = -lmlx -lXext -lX11

all : $(NAME)

$(NAME) :
	@make re -C ./libft/
	@$(CC) -c $(SRCS) $(FLAGS) $(HEADER)
	@$(CC) $(OBJ) $(X11) $(LIB) $(FRAMEWORK) -o $(NAME) $(LIBFT)
	@echo "Compiling\t\tOK"

clean :
	@rm -rf *.o
	@make clean -C ./libft
	@echo "Cleaning\t\tOK"

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all
