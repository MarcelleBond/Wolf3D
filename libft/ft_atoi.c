/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:35:53 by mbond             #+#    #+#             */
/*   Updated: 2018/06/19 10:40:18 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(const char src)
{
	if (src == ' ' || src == '\t' || src == '\n' || src == '\v'
			|| src == '\f' || src == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int n;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if ((str[0] == '-' && str[1] == '+') || (str[0] == '+' && str[1] == '-'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10;
		n = n + str[i] - '0';
		i++;
	}
	return (n * sign);
}
