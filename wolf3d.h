#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
// # include <SDL2/SDL.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# define FOV 0.7853975

typedef struct	s_player
{
	float playerX;
	float playerY;
	float playerA;
}				t_player;

#endif