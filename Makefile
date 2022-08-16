# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 14:35:00 by ahernand          #+#    #+#              #
#    Updated: 2022/07/30 15:40:59 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/main.c

OBJS = srcs/main.o


all : $(NAME)

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@




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
	@rm -f $(NAME)

re:	fclean all