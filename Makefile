
# Name
NAME = so_long


# Compiller
CC = cc


# Flags
CFLAGS = -Wall -Wextra -Werror -I./ft_printf -I./get_next_line -I./minilibx -std=gnu11
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer

# debug:
# 	$(MAKE) CFLAGS="-Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer"


FT_PRINTF = ./ft_printf/libftprintf.a
G_N_L = ./get_next_line/get_next_line.a
MLX = ./minilibx/libmlx.a

MLX_FLAGS = -lXext -lX11 -lm


# Sources
SRCS =	main.c \
		utils.c \
		./validation_map/validate_map.c \
		./validation_map/validate_map2.c \
		./validation_map/read_map.c \
		./validation_map/flood_fill.c \
		./validation_map/player_position.c \

# Objscd
OBJS = $(SRCS:%.c=%.o)

# Target
all: $(NAME)


$(FT_PRINTF):
	make -C  ./ft_printf

$(G_N_L):
	make -C  ./get_next_line

$(MLXL):
	make -C  ./minilibx

$(NAME): $(OBJS) $(FT_PRINTF) $(G_N_L) $(MLX)
	$(CC)	$(CFLAGS) $(OBJS) $(FT_PRINTF)	$(G_N_L)  $(MLX)  $(MLX_FLAGS) -o $(NAME)

# Translate .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean objs
clean:
	rm -f	$(OBJS)
	make -C ./ft_printf clean
	make -C ./get_next_line clean
	make -C ./minilibx clean


# Clean all
fclean: clean
	rm -f $(NAME)
	make -C ./ft_printf fclean
	make -C ./get_next_line fclean
	make -C ./minilibx fclean

# Recompile all
re: fclean all


# Phony
.PHONY: all clean fclean re debug
