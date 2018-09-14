/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:29:47 by mbond             #+#    #+#             */
/*   Updated: 2018/06/29 08:58:57 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		isnewline(const char *s)
{
	char *str;

	if ((str = ft_strchr(s, '\n')))
		return (1);
	return (0);
}

static char		*keep4later(const char *s)
{
	char *temp1;
	char *temp2;

	if (isnewline(s))
	{
		temp2 = (char *)s;
		temp1 = ft_strchr(s, '\n');
		temp1++;
		temp1 = ft_strdup(temp1);
		free(temp2);
	}
	else
	{
		temp1 = ft_strdup("");
		temp2 = (char *)s;
		free(temp2);
	}
	return (temp1);
}

static char		*sendtoline(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	while (s1[i] != '\n' && s1[i])
		i++;
	s2 = ft_strsub(s1, 0, i);
	return (s2);
}

int				get_next_line(const int fd, char **line)
{
	int			outcome;
	static char	*leftover;
	char		*temp;
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (leftover == NULL)
		leftover = ft_strdup("");
	while (!(isnewline(leftover)))
	{
		outcome = read(fd, buff, BUFF_SIZE);
		if (outcome == 0)
			break ;
		buff[outcome] = '\0';
		temp = leftover;
		leftover = ft_strjoin(leftover, buff);
		free(temp);
	}
	if (outcome == 0 && leftover[0] == '\0')
		return (0);
	*line = sendtoline(leftover);
	leftover = keep4later(leftover);
	return (1);
}
