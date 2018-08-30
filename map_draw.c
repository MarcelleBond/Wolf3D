/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:22:11 by mbond             #+#    #+#             */
/*   Updated: 2018/08/30 20:33:06 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void map_draw(t_wolf *g)
{
	t_rays m;

	m.depth = g->r.depth;
	for (int x = 0; x < WIDTH; x++)
	{
		m.rayA = (g->p.playerA - FOV / 2.0f) + ((float)x / (float)WIDTH) * FOV;
		m.dist = 0;
		m.eyeX = sinf(m.rayA);
		m.eyeY = cosf(m.rayA);
		m.hit = 0;
		while (m.hit != 1 && m.dist < m.depth)
		{
			m.dist += 0.1;
			m.testX = (g->p.playerX + m.eyeX * m.dist);
			m.testY = (g->p.playerY + m.eyeY * m.dist);
			if (m.testX < 0 || m.testX >= WIDTH || m.testY < 0 || m.testY >= HEIGHT)
			{
				m.hit = 1;
				m.dist = m.depth;
			}
			else
			{
				if (g->map[(int)m.testY][(int)m.testX] > 0)
				{
					m.hit = 1;
				}
			}
		}
		m.ceiling = (HEIGHT / 2.0) - HEIGHT / m.dist;
		m.floors = HEIGHT - m.ceiling;

		if (m.dist <= m.depth / 4.0)
			m.shade = 0x0061ff;
		else if (m.dist < m.depth / 3.0)
			m.shade = 0x005aed;
		else if (m.dist < m.depth / 2.0)
			m.shade = 0x014cc6;
		else if (m.dist < m.depth)
			m.shade = 0x003fa5;
		else
			m.shade = 0xFF66FF;
		for (int y = 0; y < HEIGHT; y++)
		{
			if (y < m.ceiling)
				mlx_pixel_put(g->w.mxl, g->w.win, x, y, 0xFF66FF);
			else if (y > m.ceiling && y <= m.floors)
				mlx_pixel_put(g->w.mxl, g->w.win, x, y, m.shade);
			else
				mlx_pixel_put(g->w.mxl, g->w.win, x, y, 0xFFF66);
		}
	}
}