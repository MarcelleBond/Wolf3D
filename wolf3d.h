#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define WIDTH 500
# define HEIGHT 500
# define FOV 0.7853975

typedef struct	s_player
{
	float playerX;
	float playerY;
	float playerA;
}				t_player;

#endif