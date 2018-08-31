/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:22:11 by mbond             #+#    #+#             */
/*   Updated: 2018/08/31 20:40:47 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		color_w(t_rays m)
{
	if (m.dist <= m.depth / 4.0)
		return (0x0061ff);
	else if (m.dist < m.depth / 3.0)
		return (0x005aed);
	else if (m.dist < m.depth / 2.0)
		return (0x014cc6);
	else if (m.dist < m.depth)
		return (0x003fa5);
	else
		return (0x46494f);
}

int		color_f(int y)
{
	float f;

	f = 1.0 - (((float)y - HEIGHT / 2.0) / ((float)HEIGHT / 2.0));
	if (f < 0.25)
		return (0xaa0000);
	else if (f < 0.5)
		return (0xa30000);
	else if (f < 0.75)
		return (0x840000);
	else if (f < 0.9)
		return (0x7c0000);
	else
		return (0x960000);
}

t_rays	findwall(t_rays m, t_wolf *g)
{
	while (m.hit != 1 && m.dist < m.depth)
	{
		m.dist += 0.1;
		m.test_x = (g->p.player_x + m.eye_x * m.dist);
		m.test_y = (g->p.player_y + m.eye_y * m.dist);
		if (m.test_x < 0 || m.test_x >= WIDTH || m.test_y < 0 ||
		m.test_y >= HEIGHT)
		{
			m.hit = 1;
			m.dist = m.depth;
		}
		else
		{
			if (g->map[(int)m.test_y][(int)m.test_x] > 0)
			{
				m.hit = 1;
			}
		}
	}
	return (m);
}

void	draw(t_rays m, t_wolf *g, int x)
{
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < m.ceiling)
			mlx_pixel_put(g->w.mxl, g->w.win, x, y, 0x46494f);
		else if (y > m.ceiling && y <= m.floors)
			mlx_pixel_put(g->w.mxl, g->w.win, x, y, color_w(m));
		else
			mlx_pixel_put(g->w.mxl, g->w.win, x, y, color_f(y));
		y++;
	}
}

void	map_draw(t_wolf *g)
{
	t_rays	m;
	int		x;

	x = 0;
	m.depth = g->r.depth;
	while (x < WIDTH)
	{
		m.ray_a = (g->p.player_a - FOV / 2.0f) + ((float)x / (float)WIDTH)
			* FOV;
		m.dist = 0;
		m.eye_x = sinf(m.ray_a);
		m.eye_y = cosf(m.ray_a);
		m.hit = 0;
		m = findwall(m, g);
		m.ceiling = (HEIGHT / 2.0) - HEIGHT / m.dist;
		m.floors = HEIGHT - m.ceiling;
		draw(m, g, x);
		x++;
	}
}
