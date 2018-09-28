/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:22:11 by mbond             #+#    #+#             */
/*   Updated: 2018/09/28 09:24:51 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_rays	findwall(t_rays m, t_wolf *g)
{
	while (m.hit != 1 && m.dist < m.depth)
	{
		m.dist += 0.13;
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
	t_color w;

	w.y = 0;
	while (w.y < HEIGHT)
	{
		if (w.y < m.ceiling)
		{
			SDL_SetRenderDrawColor(g->renderer, 70, 73, 79, 255);
			SDL_RenderDrawPoint(g->renderer, x, w.y);
		}
		else if (w.y >= m.ceiling && w.y < m.floors)
		{
			color_w(m, &w);
			SDL_SetRenderDrawColor(g->renderer, w.c[0], w.c[1], w.c[2], 255);
			SDL_RenderDrawPoint(g->renderer, x, w.y);
		}
		else
		{
			color_f(w.g, w.y, &w);
			SDL_SetRenderDrawColor(g->renderer, w.c[0], w.c[1], w.c[2], 255);
			SDL_RenderDrawPoint(g->renderer, x, w.y);
		}
		w.y++;
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
