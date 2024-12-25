# Nom de l'exécutable
NAME = so_long

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
SRCS_DIR = .
UTILS_DIR = utils/gnl
MINILIBX_DIR = minilibx-linux

# Sources
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

# Objets
OBJS = $(SRCS:.c=.o)

# Minilibx et bibliothèques
MLX_LIB = -L $(MINILIBX_DIR) -lmlx -L /usr/lib -lX11 -lXext

# Includes
INCLUDES = -I . -I $(MINILIBX_DIR) -I $(UTILS_DIR)

# Règles de compilation
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

# Compilation des fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

# Ne pas supprimer les fichiers implicites
.PHONY: all clean fclean re
