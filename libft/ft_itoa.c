/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:32:50 by mbond             #+#    #+#             */
/*   Updated: 2018/06/11 07:49:26 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_numcheck(char *str, int n, int i)
{
	if (n <= -1)
	{
		n = -n;
		while (i != 0)
		{
			i--;
			str[i] = n % 10 + '0';
			n = n / 10;
		}
		str[i] = '-';
	}
	else
		while (i != -1)
		{
			--i;
			str[i] = n % 10 + '0';
			n = n / 10;
		}
	return (str);
}

static char		*ft_min(char *src)
{
	char	*temp;
	int		i;

	i = 0;
	if (!(temp = (char *)malloc((ft_strlen(src) + 1))))
		return (NULL);
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_intlen(n);
	if (n == -2147483648)
	{
		str = ft_min("-2147483648");
		return (str);
	}
	if (!(str = (char*)malloc(1 + i)))
		return (NULL);
	str[i] = '\0';
	if (n == -0)
	{
		str[0] = '0';
		return (str);
	}
	str = ft_numcheck(str, n, i);
	return (str);
}
