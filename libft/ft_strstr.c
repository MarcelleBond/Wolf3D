/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:19:15 by mbond             #+#    #+#             */
/*   Updated: 2018/06/19 10:55:05 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordsearch(const char *s1, const char *s2)
{
	int i;
	int e;
	int d;

	i = 0;
	e = 0;
	while (s1[i] != '\0')
	{
		d = 0;
		if (s1[i] == s2[d])
		{
			e = i;
			while (s1[e] == s2[d] && s2[d] != '\0')
			{
				e++;
				d++;
			}
		}
		if (s2[d] == '\0')
			break ;
		i++;
	}
	if (s2[d] != '\0' && s1[i] == '\0')
		return (-1);
	return (i);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int e;

	e = 0;
	if (!needle[e])
		return ((char *)haystack);
	if (!haystack[e])
		return (NULL);
	i = wordsearch(haystack, needle);
	if (i == -1)
		return (NULL);
	return ((char *)&haystack[i]);
}
