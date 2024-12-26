NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = .
UTILS_DIR = utils/gnl
MINILIBX_DIR = minilibx-linux

SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/key_handler.c \
       $(SRCS_DIR)/parsing.c \
       $(SRCS_DIR)/window.c \
       $(SRCS_DIR)/sprites.c \
       $(SRCS_DIR)/collision.c \
       $(SRCS_DIR)/move.c \
       $(SRCS_DIR)/check_map.c \
       $(UTILS_DIR)/get_next_line.c \
       $(UTILS_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

MLX_LIB = -L $(MINILIBX_DIR) -lmlx -L /usr/lib -lX11 -lXext

INCLUDES = -I . -I $(MINILIBX_DIR) -I $(UTILS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
