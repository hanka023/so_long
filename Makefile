
# Compiller
CC = cc


# Flags
CFLAGS = -Wall -Wextra -Werror -I./ft_printf -I./get_next_line -I/libft
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer

debug:
	$(MAKE) CFLAGS="-Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer" re


FT_PRINTF = ./ft_printf/libftprintf.a
G_N_L = ./get_next_line/get_next_line.a
LIBFT = ./libft/libft.a

# Sources
SRCS =	main.c \
		./validation_map/validate_map.c \
		./validation_map/read_map.c \
		./validation_map/flood_fill.c

# Objscd
OBJS = $(SRCS:%.c=%.o)




# Name
NAME = so_long



# Target
all: $(NAME)


$(FT_PRINTF):
	make -C  ./ft_printf

$(G_N_L):
	make -C  ./get_next_line

$(LIBFT):
	make -C  ./libft


$(NAME): $(OBJS) $(FT_PRINTF) $(G_N_L) $(LIBFT)
	$(CC)	$(CFLAGS) $(OBJS) $(FT_PRINTF)	$(G_N_L) $(LIBFT) -o $(NAME)


# Translate .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean objs
clean:
	rm -f	$(OBJS)
	make -C ./ft_printf clean
	make -C ./get_next_line clean
	make -C ./libft clean


# Clean all
fclean: clean
	rm -f $(NAME)
	make -C ./ft_printf fclean
	make -C ./get_next_line fclean
	make -C ./libft fclean

# Recompile all
re: fclean all


# Phony
.PHONY: all clean fclean re debug
