CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = so_long

HEADERS = so_long.h
SRCS = get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       libft/ft_split.c libft/ft_strrchr.c\
        libft/ft_strncmp.c libft/ft_putnbr_fd.c\
       libft/ft_strlcpy.c libft/ft_strlcat.c \
       ft_put_image.c free_exit.c so_long.c  \
       search_function.c \
       map_rules.c \
       map_rules2.c \
       move.c \
       read_map.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c so_long.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean  Mk_libft
