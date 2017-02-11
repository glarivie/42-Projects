# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 17:02:38 by glarivie          #+#    #+#              #
#    Updated: 2016/01/14 10:26:33 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	srcs/ft_get_line.c		\
			srcs/ft_fdf.c			\
			srcs/ft_init_coord.c	\
			srcs/ft_draw_line.c		\
			srcs/ft_hook.c			\
			srcs/ft_hud.c			\

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
INC		=	-I /usr/X11/include -g -I includes -I libft
LIB		=	-L libft -lft -L /usr/X11/lib -lX11 -lXext -lmlx
FMW		=	-framework OpenGL -framework Appkit

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

all		:	$(NAME)

$(NAME)	:
	@make -C libft/
	@echo "compiling libft\t\tOK"
	@$(CC) $(FLAGS) $(LIB) $(INC) $(FMW) $(SRCS) -o $(NAME)
	@echo "compiling\t\tOK"

clean	:
	@rm -f srcs/*.o
	@echo "remove *.o\t\tOK"
	@make clean -C libft/
	@echo "clean libft\t\tOK"

fclean	:	clean
	@rm -f $(NAME)
	@echo "remove fdf\t\tOK"
	@make fclean -C libft/
	@echo "fclean libft\t\tOK"
	@rm -Rf fdf.dSYM

re		:	fclean all
