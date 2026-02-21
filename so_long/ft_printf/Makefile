
NAME  = libftprintf.a

SRC = ft_printf.c	\
		ft_putnbr.c		ft_printstr.c \
		ft_printhex.c	ft_putptr.c		ft_unsigned.c


	OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf
AR = ar crs

$(NAME):	$(OBJS)
	$(AR)	$(NAME)	$(OBJS)

all: $(NAME)

clean:
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
