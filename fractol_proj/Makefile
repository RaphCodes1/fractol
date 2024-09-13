NAME = fractol
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = -rm -f

SRCS = main.c fractal_init.c render.c libft/ft_putstr_fd.c libft/ft_strncmp.c \
		math_utils.c events.c

MINILIBX = libmlx.a
MLX_FLAGS = -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

all: $(NAME)

#add C FLAGS AFTER
$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $^ $(MLX_FLAGS) -o $@ 

#add C FLAGS AFTER
%.o:%.c
	$(CC) -c $< -o $@ 

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus