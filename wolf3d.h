/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:33:42 by mbond             #+#    #+#             */
/*   Updated: 2018/09/12 08:20:13 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "includes/SDL2/SDL.h"
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

typedef struct	s_color
{
	int		c[3];
	int		y;
	int		i;
	float	g;
}				t_color;

typedef struct	s_work
{
	void	*mxl;
	void	*win;
	void	*img;
	int		bpp;
	int		sizeline;
	int		end;
	char	*data;
}				t_work;

typedef struct	s_read
{
	int		fd;
	int		ret;
	int		px;
	int		py;
	int		empty;
	char	*line;
	char	**split;
}				t_read;

typedef struct	s_rays
{
	double		ray_a;
	double		eye_x;
	double		eye_y;
	double		test_x;
	double		test_y;
	double		dist;
	double		depth;
	int			hit;
	double		ceiling;
	double		floors;
	double		shade;
}				t_rays;

typedef struct	s_wolf
{
	t_work			w;
	t_player		p;
	t_rays			r;
	int				map[800][800];
	int				cols;
	int				rows;
	int				running;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}				t_wolf;

t_wolf			map_read(char *file, t_wolf w);
void			map_draw(t_wolf *g);
void			m_forward(t_wolf *w);
void			m_backward(t_wolf *w);
void			r_right(t_wolf *w);
void			r_left(t_wolf *w);
void			color_w(t_rays m, t_color *w);
void			color_f(float g, int y, t_color *f);

#endif
