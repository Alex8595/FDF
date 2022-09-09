# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 14:35:00 by ahernand          #+#    #+#              #
#    Updated: 2022/09/09 18:30:45 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc 

CFLAGS = #-Wall -Wextra -Werror

SRCS =	srcs/FdF.c								\
		srcs/mlx_fts.c							\
		srcs/ft_read.c							\
		srcs/ft_exec.c							\
		srcs/ft_error.c


OBJS = srcs/FdF.o								\
		srcs/mlx_fts.o							\
		srcs/ft_read.o							\
		srcs/ft_exec.o							\
		srcs/ft_error.o

MLX = lib_mlx

LIBFT = libft


all : $(NAME)

$(LIBFT) : 
	@cd srcs/libft && make
	ls > hello.txt

$(MLX) : 
	@cd minilibx && make

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) minilibx/libmlx.a srcs/libft/libft.a -framework OpenGl -framework AppKit -o $@















# - - - - - - - - - - - - - - - - - #
# - - - - - - T E S T - - - - - - - #
# - - - - - - - - - - - - - - - - - #

test:







# - - - - - - - - - - - - - - - - - #
# - - - - C L E A N I N G - - - - - #
# - - - - - - - - - - - - - - - - - #


clean:
	@rm -f $(OBJS)
	@rm -f $(NAME)

fclean:
	@rm -f $(OBJS)
	@cd minilibx && make clean
	@cd srcs/libft && make fclean
	@rm -f $(NAME)

re:	clean all
