/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:22:11 by mbond             #+#    #+#             */
/*   Updated: 2018/08/31 14:59:05 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		color(t_rays m)
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
			mlx_pixel_put(g->w.mxl, g->w.win, x, y, m.shade);
		else
			mlx_pixel_put(g->w.mxl, g->w.win, x, y, 0x960000);
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
		m.shade = color(m);
		draw(m, g, x);
		x++;
	}
}
