/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <mbond@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:33:42 by mbond             #+#    #+#             */
/*   Updated: 2018/08/30 16:39:31 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	double playerX;
	double playerY;
	double playerA;
}				t_player;

typedef struct	s_work
{
	void *mxl;
	void *win;
}				t_work;

typedef struct	s_read
{
	int		fd;
	int		ret;
	int		px;
	int		py;
	char	*line;
	char	**split;
}				t_read;

typedef struct	s_rays
{
	double		rayA;
	double		dist;
	double		eyeX;
	double		eyeY;
	double		depth;
	double		testX;
	double		testY;
	int			hit;
	double		ceiling;
	double		floors;
	double		shade;
}				t_rays;

typedef struct	s_wolf
{
	t_work		w;
	t_player	p;
	t_rays		r;
	int			map[24][24];
	int			cols;
	int			rows;
}				t_wolf;

void			map_draw(t_wolf *g);
t_wolf			map_read(char *file, t_wolf w);	

#endif