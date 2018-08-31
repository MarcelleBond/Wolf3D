/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:34:14 by mbond             #+#    #+#             */
/*   Updated: 2018/08/31 20:33:57 by mbond            ###   ########.fr       */
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
		mlx_clear_window(w->w.mxl, w->w.win);
		map_draw(w);
	}
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 0 || keycode == 97)
		r_left(w);
	if (keycode == 2 || keycode == 100)
		r_right(w);
	if (keycode == 13 || keycode == 119)
		m_forward(w);
	if (keycode == 1 || keycode == 115)
		m_backward(w);
	return (0);
}

int		main(int argc, char **argv)
{
	t_wolf	w;

	if (argc == 2)
	{
		w.cols = 1;
		w = map_read(argv[1], w);
		w.p.player_a = 0.00;
		w.p.player_y = w.rows / 2;
		w.p.player_x = w.cols / 2;
		w.r.depth = (w.cols > w.rows) ? w.cols : w.rows;
		w.w.mxl = mlx_init();
		w.w.win = mlx_new_window(w.w.mxl, WIDTH, HEIGHT, "WOLF3D");
		mlx_string_put(w.w.mxl, w.w.win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
		"start");
		/* mlx_hook(w.w.win, 2, 0, keywork, &w); */
		mlx_key_hook(w.w.win,keywork, &w);
		mlx_hook(w.w.win, 17, 0, butt, 0);
		mlx_loop(w.w.mxl);
	}
	else if (argc < 2)
		ft_putendl("NO MAP FOUND");
	else if (argc > 2)
		ft_putendl("TO MANY INPUTS");
	return (0);
}
