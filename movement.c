/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:07:24 by mbond             #+#    #+#             */
/*   Updated: 2018/08/31 19:32:40 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	m_forward(t_wolf *w)
{
	w->p.player_x += sinf(w->p.player_a) * 1.1;
	w->p.player_y += cosf(w->p.player_a) * 1.1;
	if (w->map[(int)w->p.player_y][(int)w->p.player_x] > 0)
	{
		w->p.player_x -= sinf(w->p.player_a) * 1.1;
		w->p.player_y -= cosf(w->p.player_a) * 1.1;
	}
	mlx_clear_window(w->w.mxl, w->w.win);
	map_draw(w);
}

void	m_backward(t_wolf *w)
{
	w->p.player_x -= sinf(w->p.player_a) * 1.1;
	w->p.player_y -= cosf(w->p.player_a) * 1.1;
	if (w->map[(int)w->p.player_y][(int)w->p.player_x] > 0)
	{
		w->p.player_x += sinf(w->p.player_a) * 1.1;
		w->p.player_y += cosf(w->p.player_a) * 1.1;
	}
	mlx_clear_window(w->w.mxl, w->w.win);
	map_draw(w);
}

void	r_right(t_wolf *w)
{
	w->p.player_a += 0.1f;
	mlx_clear_window(w->w.mxl, w->w.win);
	map_draw(w);
}

void	r_left(t_wolf *w)
{
	w->p.player_a -= 0.1f;
	mlx_clear_window(w->w.mxl, w->w.win);
	map_draw(w);
}
