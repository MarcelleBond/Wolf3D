/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:59:34 by mbond             #+#    #+#             */
/*   Updated: 2018/09/07 08:42:22 by mbond            ###   ########.fr       */
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

void			emptymap(int empty)
{
	if (empty == 0)
	{
		ft_putendl("EMPTY FILE");
		exit(1);
	}
	else
		return ;
}

t_wolf			map_read(char *file, t_wolf w)
{
	t_read	run;

	run.py = 0;
	run.fd = map_check(file);
	run.empty = 0;
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
		run.empty = 1;
	}
	emptymap(run.empty);
	close(run.fd);
	w.rows = run.py;
	w.cols = run.px;
	return (w);
}
