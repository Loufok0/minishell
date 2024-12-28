# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/12/28 23:04:17 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c\
	prompt.c\

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lreadline -o $(NAME)
	@echo $(NAME)" compiled!\n"

debug: $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) libft/libft.a  -lreadline -o $(NAME)
	@echo $(NAME)" compiled with debug!\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -lreadline -c $< -o $@


clean:
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

