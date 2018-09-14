/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:13:44 by mbond             #+#    #+#             */
/*   Updated: 2018/06/12 11:02:38 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fullstr(char const *str, char c)
{
	size_t i;
	size_t j;

	i = 0;
	if (!str)
		return (0);
	if (*str != c)
		i = 1;
	j = 1;
	while (str[j])
	{
		if (str[j] != c && str[j - 1] == c)
			i++;
		j++;
	}
	return (i);
}

static size_t	ft_splitlen(char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	int		j;
	char	**fresh;

	i = 0;
	n = 0;
	if (!s || !(fresh = (char**)malloc(sizeof(fresh) *
					(ft_fullstr((char *)s, c)) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		if (s[i] == '\0')
			break ;
		fresh[n] = (char *)ft_strnew(ft_splitlen((char *)&s[i], c));
		while (s[i] != c && s[i] != '\0')
			fresh[n][j++] = s[i++];
		fresh[n][j] = '\0';
		n++;
	}
	fresh[n] = 0;
	return (fresh);
}
