# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbond <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 16:20:23 by mbond             #+#    #+#              #
#    Updated: 2018/06/25 10:29:12 by mbond            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = gcc
FLAGS = -Wall -Werror -Wextra
FUNCS = ft_atoi \
ft_bzero \
ft_intlen \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_itoa \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \
ft_putchar \
ft_putchar_fd \
ft_putendl \
ft_putendl_fd \
ft_putnbr \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_strcat \
ft_strchr \
ft_strclr \
ft_strcmp \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_striter \
ft_striteri \
ft_strjoin \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnstr \
ft_strrchr \
ft_strsplit \
ft_strstr \
ft_strsub \
ft_strtrim \
ft_tolower \
ft_toupper \
ft_free_2d_array \
get_next_line \

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))

all: $(NAME)

$(NAME):
	$(COMP) $(FLAGS) -c $(SRCC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
