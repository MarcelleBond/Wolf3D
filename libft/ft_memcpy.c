/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:54:38 by mbond             #+#    #+#             */
/*   Updated: 2018/06/07 11:56:46 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*newsrc;
	char	*newdest;
	size_t	i;

	newsrc = (char *)src;
	newdest = (char *)dest;
	i = 0;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		i++;
	}
	return (newdest);
}
