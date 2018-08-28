/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 08:21:25 by mbond             #+#    #+#             */
/*   Updated: 2018/06/08 08:22:39 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*fstr;
	int		i;

	if (s && f)
	{
		i = 0;
		if (!(fstr = (char *)malloc(ft_strlen((char *)s) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			fstr[i] = f(s[i]);
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
