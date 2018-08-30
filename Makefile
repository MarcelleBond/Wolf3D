NAME = fdf
COMP = gcc
FLAGS = -Wall -Werror -Wextra -std=c99
LIB_F = -I libft/ 
LIB_FA = libft/libft.a
LIB_G = -lm -L libft/ -lft -L minilibxOSX -lmlx -framework OpenGL -framework Appkit
FUNCS = main \
		draw_calc \
		error \
		line_draw \
		map_read \
		preset \
		scale_and_rotate \
		keybord_work \

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