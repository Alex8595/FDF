# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 14:35:00 by ahernand          #+#    #+#              #
#    Updated: 2022/08/16 19:02:53 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/FdF.c			\
		srcs/mlx_fts.c

OBJS = srcs/FdF.o			\
		srcs/mlx_fts.o

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
