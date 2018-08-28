/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:21:58 by mbond             #+#    #+#             */
/*   Updated: 2018/06/12 12:29:45 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		iswhitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n'))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*fresh;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s) - 1;
	while (iswhitespace(s[i]))
		i++;
	while ((iswhitespace(s[n])))
		n--;
	n = n - i + 1;
	if (0 > n)
		n = 0;
	if (!(fresh = (char *)ft_strnew(n)))
		return (NULL);
	while (j < n)
		fresh[j++] = s[i++];
	fresh[j] = '\0';
	return (fresh);
}
