/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:38:32 by mbond             #+#    #+#             */
/*   Updated: 2018/06/07 11:40:33 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
	{
		return (0);
	}
	while (--n && *(char *)s1 == *(char *)s2)
	{
		s1 = (char *)s1 + 1;
		s2 = (char *)s2 + 1;
	}
	if ((char*)s1 == (char*)s2)
		return (0);
	else
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
