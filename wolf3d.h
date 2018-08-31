/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:33:42 by mbond             #+#    #+#             */
/*   Updated: 2018/08/31 16:07:30 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define WIDTH 1300
# define HEIGHT 600
# define FOV 0.7853975

typedef struct	s_player
{
	double player_x;
	double player_y;
	double player_a;
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
	double		ray_a;
	double		dist;
	double		eye_x;
	double		eye_y;
	double		depth;
	double		test_x;
	double		test_y;
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
	int			map[1000][1000];
	int			cols;
	int			rows;
}				t_wolf;

void			map_draw(t_wolf *g);
t_wolf			map_read(char *file, t_wolf w);
void			m_forward(t_wolf *w);
void			m_backward(t_wolf *w);
void			r_right(t_wolf *w);
void			r_left(t_wolf *w);

#endif
