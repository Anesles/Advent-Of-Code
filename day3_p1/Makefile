NAME		= rucksack

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

SRC			= main.c

LIBFTPATH	= ../libft/

LIBFT = libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPATH)$(LIBFT) -o $(NAME)

clean:
	cd ../libft && $(MAKE) clean
	rm -rf $(OBJ)

fclean:	clean
	cd ../libft && $(MAKE) fclean
	rm -rf $(NAME)

re: fclean all