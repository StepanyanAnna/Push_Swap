# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:30:21 by annstepa          #+#    #+#              #
#    Updated: 2022/09/21 17:50:20 by annstepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -g -ggdb3 #-Werror

SRCS	= $(wildcard *.c)

OBJS	= $(patsubst %.c, %.o, $(SRCS))

RM		= rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS)
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re:	fclean all clean


.PHONY: all clean fclean re


#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
