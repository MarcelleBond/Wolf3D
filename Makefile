NAME = wolf3d
COMP = gcc
FLAGS = -Wall -Werror -Wextra -std=c99
LIB_F = -I libft/
LIB_FA = libft/libft.a
LIB_G = -lm -L libft/ -lft  -lmlx -framework OpenGL -framework Appkit
FUNCS = main \
		map_read \
		map_draw \
		movement \

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))

HF = libft/libft.h
LIB = ./libft/libft.a
INCLUDES = -I./libft
all: $(NAME)

$(NAME):	$(SRCO)
	@make -C libft
	@$(COMP) $(FLAGS) -I $(LIB) -c $(SRCC)
	$(COMP) -o $(NAME) $(SRCO) $(LIB_G)
clean:
	@make -C libft/ clean
	rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all