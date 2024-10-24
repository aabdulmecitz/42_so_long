NAME = so_long
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
RM = rm -f

# Projeyi derleyen hedef
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)

# Varsayılan hedef
all: $(NAME)

# Object dosyalarını ve geçici dosyaları temizle
clean:
	$(RM) $(OBJS)

# Bütün dosyaları (çalıştırılabilir dosya dahil) temizle
fclean: clean
	$(RM) $(NAME)

# Yeniden derleme
re: fclean all

# Programı yeniden derleyip çalıştırma hedefi
run: re
	./so_long

.PHONY: all clean fclean re run
