/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:34:14 by mbond             #+#    #+#             */
/*   Updated: 2018/08/30 20:55:57 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		butt(int but)
{
	(void)but;
	exit(0);
}

int		keywork(int keycode, t_wolf *w)
{
	printf("%d\n", keycode);
	if (keycode == 11 || keycode == 98)
	{
		mlx_clear_window(w->w.mxl,w->w.win);
		map_draw(w);
	}
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 0 || keycode == 97)
	{
		w->p.playerA -= 0.1f;
		mlx_clear_window(w->w.mxl,w->w.win);
		map_draw(w);

	}
	if (keycode == 2 || keycode == 100)
	{
		w->p.playerA += 0.1f;
		mlx_clear_window(w->w.mxl,w->w.win);
		map_draw(w);

	}
	if (keycode == 119)
	{
		w->p.playerX += sinf(w->p.playerA) * 1.1;
		w->p.playerY += cosf(w->p.playerA) * 1.1;
		if (w->map[(int)w->p.playerY][(int)w->p.playerX] > 0)
		{
			w->p.playerX -= sinf(w->p.playerA) * 1.1;
			w->p.playerY -= cosf(w->p.playerA) * 1.1;
		}
		mlx_clear_window(w->w.mxl,w->w.win);
		map_draw(w);
	}
	if (keycode == 115)
	{
		w->p.playerX -= sinf(w->p.playerA) * 1.1;
		w->p.playerY -= cosf(w->p.playerA) * 1.1;
		if (w->map[(int)w->p.playerY][(int)w->p.playerX] > 0)
		{
			w->p.playerX += sinf(w->p.playerA) * 1.1;
			w->p.playerY += cosf(w->p.playerA) * 1.1;
		}
		mlx_clear_window(w->w.mxl,w->w.win);
		map_draw(w);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_wolf	w;
	(void)argc;

	w.cols = 1;
	w = map_read(argv[1],w);
	w.p.playerA = 0.00;
	w.p.playerY = 12.0;
	w.p.playerX = 12.0;
	w.r.depth = 24;
	w.w.mxl = mlx_init();
	w.w.win = mlx_new_window(w.w.mxl, WIDTH, HEIGHT, "WOLF3D");
	mlx_string_put(w.w.mxl,w.w.win,WIDTH/2,HEIGHT/2,0xFFFFFF,"start");
	// mlx_hook(w.w.win, 2, 0, keywork, &w);
	mlx_key_hook(w.w.win,keywork, &w);
	mlx_hook(w.w.win, 17, 0, butt, 0);
	mlx_loop(w.w.mxl);
	return 0;
}
