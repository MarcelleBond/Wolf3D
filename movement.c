/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:07:24 by mbond             #+#    #+#             */
/*   Updated: 2018/09/07 10:34:41 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	m_forward(t_wolf *w)
{
	w->p.player_x += sinf(w->p.player_a) * 0.85;
	w->p.player_y += cosf(w->p.player_a) * 0.85;
	if (w->map[(int)w->p.player_y][(int)w->p.player_x] > 0 ||
	w->p.player_x > w->cols || w->p.player_x < 0 ||
	w->p.player_y > w->rows || w->p.player_y < 0)
	{
		w->p.player_x -= sinf(w->p.player_a) * 0.85;
		w->p.player_y -= cosf(w->p.player_a) * 0.85;
	}
}

void	m_backward(t_wolf *w)
{
	w->p.player_x -= sinf(w->p.player_a) * 0.85;
	w->p.player_y -= cosf(w->p.player_a) * 0.85;
	if (w->map[(int)w->p.player_y][(int)w->p.player_x] > 0 ||
	w->p.player_x > w->cols || w->p.player_x < 0 ||
	w->p.player_y > w->rows || w->p.player_y < 0)
	{
		w->p.player_x += sinf(w->p.player_a) * 0.85;
		w->p.player_y += cosf(w->p.player_a) * 0.85;
	}
}

void	r_right(t_wolf *w)
{
	w->p.player_a += 0.1;
}

void	r_left(t_wolf *w)
{
	w->p.player_a -= 0.1;
}
