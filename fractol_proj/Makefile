NAME = fractol

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = -rm -f

SRCS = main.c libft/ft_putstr_fd.c libft/ft_strncmp.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus