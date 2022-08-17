# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 14:35:00 by ahernand          #+#    #+#              #
#    Updated: 2022/08/17 20:04:40 by ahernand         ###   ########.fr        #
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









all : $(NAME)

$(MLX) : 
	@cd minilibx && make

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) minilibx/libmlx.a -framework OpenGl -framework AppKit -o $@















# - - - - - - - - - - - - - - - - - #
# - - - - - - T E S T - - - - - - - #
# - - - - - - - - - - - - - - - - - #

test:







# - - - - - - - - - - - - - - - - - #
# - - - - C L E A N I N G - - - - - #
# - - - - - - - - - - - - - - - - - #


clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS)
	@cd minilibx && make clean
	@rm -f $(NAME)

re:	clean all
