# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2025/01/17 16:57:23 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c\
	envp.c\
	prompt/prompt.c\
	parsing/parser.c\
	parsing/parser_utils.c\
	parsing/tokenizer.c\
	parsing/tokenizer_utils.c\
	minishell_clean.c\
	lib_utils/ft_split_let.c\
	lib_utils/ft_strjoin_f.c\
	lib_utils/ft_free_arr.c\
	debug.c\

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@make -C 42_libft/
	@$(CC) $(CFLAGS) $(OBJS) 42_libft/libft.a -lreadline -o $(NAME)
	@echo $(NAME)" compiled!\n"

debug: $(OBJS)
	@make -C 42_libft/
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) 42_libft/libft.a  -lreadline -o $(NAME)
	@echo $(NAME)" compiled with debug!\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -lreadline -c $< -o $@


clean:
	@make clean -C 42_libft/
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C 42_libft/
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

