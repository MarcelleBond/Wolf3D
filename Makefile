NAME = wolf3d
COMP = gcc
SDL = SDL2-2.0.8
FLAGS = -Wall -Werror -Wextra -std=c99 -ggdb3
LIB_G = -lm -L libft/ -lft
FUNCS = main \
		map_read \
		map_draw \
		movement \
		colors \

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))

HF = libft/libft.h
LIB = ./libft/libft.a
INCLUDES = -I./libft

all: $(NAME)
$(SDL):
	curl -O https://libsdl.org/release/SDL2-2.0.8.tar.gz
	gunzip -c SDL2-2.0.8.tar.gz | tar xf -
	cd SDL2-2.0.8; \
	mkdir build; \
	cd build; \
	../configure; \
	make
	mkdir -p ~/lib/
	cp SDL2-2.0.8/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p includes/SDL2
	cp SDL2-2.0.8/include/*.h includes/SDL2/
$(NAME):	$(SDL) $(SRCO)
	@make -C libft
	@$(COMP) $(FLAGS) -I $(LIB) -c $(SRCC)
	@$(COMP) -o $(NAME) $(SRCO) $(LIB_G)  -lSDL2 -I includes/ -I includes/SDL2/ -L ~/lib
clean:
	@make -C libft/ clean
	rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all