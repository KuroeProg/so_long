NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = .
UTILS_DIR = utils/gnl
PRINTF_DIR = utils/ft_printf
MINILIBX_DIR = minilibx-linux

SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/key_handler.c \
	$(SRCS_DIR)/window.c \
	$(SRCS_DIR)/sprites.c \
	$(SRCS_DIR)/collision.c \
	$(SRCS_DIR)/move.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/parsing.c \
	$(SRCS_DIR)/check_map.c \
	$(UTILS_DIR)/get_next_line.c \
	$(UTILS_DIR)/get_next_line_utils.c \
	$(SRCS_DIR)/utils/utils.c

OBJS = $(SRCS:.c=.o)

MLX_LIB = -L $(MINILIBX_DIR) -lmlx -L /usr/lib -lX11 -lXext
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I . -I $(MINILIBX_DIR) -I $(UTILS_DIR) -I $(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(PRINTF_LIB) -o $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
