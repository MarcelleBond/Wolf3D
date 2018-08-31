/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:59:34 by mbond             #+#    #+#             */
/*   Updated: 2018/08/31 11:27:58 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				map_check(char *file)
{
	int		fd;
	char	*check;

	check = ft_strrchr(file, '.');
	if (check == NULL)
	{
		ft_putendl("Error: Invalid file");
		exit(1);
	}
	if ((strcmp(check, ".fdf") != 0))
	{
		ft_putendl("Error: Invalid file");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error on file opening");
		exit(1);
	}
	return (fd);
}

int				**map_malloc(int y, int x)
{
	int		**map;
	int		i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(map) * y + 1)))
	{
		ft_putendl("failed to malloc for map");
		exit(1);
	}
	while (i < y)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * x)))
		{
			ft_putendl("failed to malloc for map");
			exit(1);
		}
		i++;
	}
	return (map);
}

t_wolf			map_read(char *file, t_wolf w)
{
	t_read	run;

	run.py = 0;
	run.fd = map_check(file);
	while ((run.ret = get_next_line(run.fd, &run.line)) > 0)
	{
		run.px = 0;
		run.split = ft_strsplit(run.line, ' ');
		while (run.split[run.px] != NULL)
		{
			w.map[run.py][run.px] = ft_atoi(run.split[run.px]);
			run.px += 1;
		}
		run.py += 1;
		ft_freesplit((void **)run.split);
		free(run.line);
	}
	close(run.fd);
	w.rows = run.py;
	w.cols = run.px;
	return (w);
}
