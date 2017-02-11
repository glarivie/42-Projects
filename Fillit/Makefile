# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 10:23:40 by glarivie          #+#    #+#              #
#    Updated: 2015/12/19 13:09:19 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I $(LIB_PATH) -I ./includes
SRCS			=	srcs/ft_main_fillit.c		\
					srcs/ft_resolve.c			\
					srcs/ft_chk_err.c			\
					srcs/ft_chkchr.c			\
					srcs/ft_chkgrid.c			\
					srcs/ft_chktype.c			\
					srcs/ft_dct_blk.c			\
					srcs/ft_fill_dct_1.c		\
					srcs/ft_fill_lst.c			\
					srcs/ft_fill_shp.c			\
					srcs/ft_fillit.c			\
					srcs/ft_fix_shape.c			\
					srcs/ft_free_all.c			\
					srcs/ft_get_map.c			\
					srcs/ft_get_type.c			\
					srcs/ft_ismaj.c				\
					srcs/ft_lst_clr.c			\
					srcs/ft_lst_init.c			\
					srcs/ft_lstlen.c			\
					srcs/ft_print_map.c			\
					srcs/ft_read_buf.c			\
					srcs/ft_rm_last.c			\
					srcs/ft_rm_pl.c				\
					srcs/ft_try_pl.c			\
					srcs/ft_type_angle.c		\
					srcs/ft_chk_wtf.c
OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
