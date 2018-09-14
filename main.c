/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:34:14 by mbond             #+#    #+#             */
/*   Updated: 2018/09/10 12:09:19 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cleanup(t_wolf *w)
{
	SDL_DestroyRenderer(w->renderer);
	SDL_DestroyWindow(w->win);
}

void	set_up_window(t_wolf *w)
{
	SDL_Init(0);
	w->win = SDL_CreateWindow("WOLF3D", 100, 100,
		WIDTH, HEIGHT, 0);
	w->renderer = SDL_CreateRenderer(w->win, 0, 0);
}

void	placeplayer(t_wolf *w)
{
	w->p.player_a = 0.00;
	w->p.player_y = w->rows / 2;
	w->p.player_x = w->cols / 2;
	w->r.depth = (w->cols > w->rows) ? w->cols : w->rows;
}

int		keywork(int keycode, t_wolf *w)
{
	if (keycode == SDLK_ESCAPE)
		exit(0);
	if (keycode == SDLK_a)
		r_left(w);
	if (keycode == SDLK_d)
		r_right(w);
	if (keycode == SDLK_w)
		m_forward(w);
	if (keycode == SDLK_s)
		m_backward(w);
	return (0);
}

int		main(int argc, char **argv)
{
	t_wolf	w;

	if (argc == 2)
	{
		w.running = 1;
		w = map_read(argv[1], w);
		set_up_window(&w);
		placeplayer(&w);
		while (w.running)
		{
			while (SDL_PollEvent(&w.event))
			{
				if (w.event.type == SDL_QUIT)
					w.running = 0;
				else if (w.event.type == SDL_KEYUP)
					keywork(w.event.key.keysym.sym, &w);
			}
			map_draw(&w);
			SDL_RenderPresent(w.renderer);
		}
		cleanup(&w);
	}
	else
		ft_putendl("ERROR");
	return (0);
}
