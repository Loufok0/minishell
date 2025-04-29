CC = cc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror -I$(LDIR) -I/usr/include -lreadline

RM = rm -f

NAME = minishell
LIB = libft/libft.a

SRCS_PARSING = parser.c \
	parser_utils.c \
	tokenizer.c \
	tokenizer_utils.c \
	tokenizer_utils2.c \
	limiter.c \
	redirections.c \
	debug.c \
	clean.c \
	struct.c \
	in_and_out.c \
	in.c \
	out.c \
	list_insert.c \

SRCS_EXEC = \
	exec.c \
	exec_utils.c \
	exec_utils_2.c \

SRCS_BUILTINS = \
	builtins.c \
	ft_cd.c \
	ft_echo.c \
	ft_env.c \
	ft_exit.c \
	ft_export.c \
	ft_pwd.c \
	ft_unset.c \

SRCS_LIB_UTILS = \
	ft_split_let.c\
	ft_strjoin_f.c\
	ft_free_arr.c\
	ft_arrdup.c \
	ft_arrlen.c \

SRCS_VARS = \
	vars_2.c \
	vars.c \

SRCS = \
	main.c\
	$(addprefix parsing/, $(SRCS_PARSING)) \
	$(addprefix exec/, $(SRCS_EXEC)) \
	$(addprefix builtins/, $(SRCS_BUILTINS)) \
	$(addprefix lib_utils/, $(SRCS_LIB_UTILS)) \
	$(addprefix vars/, $(SRCS_VARS)) \

OBJS = $(addprefix $(ODIR)/, $(SRCS:.c=.o))
LDIR = $(dir $(LIB))
ODIR = obj

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)
	@echo $(NAME)" compiled!\n"

debug: $(OBJS) $(LIB)
	$(CC) $(DEBUG) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)
	@echo $(NAME)" compiled with debug!\n"

%.a:
	$(MAKE) -C $(dir $@)

$(ODIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g -gdwarf-4 -c -o $@ $<

clean:
	$(MAKE) clean -C $(LDIR)
	$(RM) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LDIR)
	$(RM) $(OBJS) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run quiet
