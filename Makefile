# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 14:35:00 by ahernand          #+#    #+#              #
#    Updated: 2022/11/14 12:42:42 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/FdF.c								\
		srcs/mlx_fts.c							\
		srcs/ft_read.c							\
		srcs/ft_fill_lines.c					\
		srcs/ft_save_raw.c						\
		srcs/ft_exec.c							\
		srcs/ft_coordinates.c					\
		srcs/hexadecimal_fts.c					\
		srcs/ft_color.c							\
		srcs/color_1_to_4.c						\
		srcs/color_5_to_8.c						\
		srcs/ft_exec_paint_up.c					\
		srcs/ft_exec_paint_down.c				\
		srcs/ft_error.c


OBJS = srcs/FdF.o								\
		srcs/mlx_fts.o							\
		srcs/ft_read.o							\
		srcs/ft_fill_lines.o					\
		srcs/ft_save_raw.o						\
		srcs/ft_exec.o							\
		srcs/ft_coordinates.o					\
		srcs/hexadecimal_fts.o					\
		srcs/ft_color.o							\
		srcs/color_1_to_4.o						\
		srcs/color_5_to_8.o						\
		srcs/ft_exec_paint_up.o					\
		srcs/ft_exec_paint_down.o				\
		srcs/ft_error.o

MLX = lib_mlx

LIBFT = libft

all : $(NAME)

$(LIBFT) : 
	@cd srcs/libft && make

$(MLX) : 
	@cd minilibx && make

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) minilibx/libmlx.a srcs/libft/libft.a -framework OpenGl -framework AppKit -o $@

.SILENT: MLX LIBFT


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

re:	fclean all
