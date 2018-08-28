/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:26 by mbond             #+#    #+#             */
/*   Updated: 2018/06/25 09:02:00 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str_dest;
	char	*str_src;
	char	*ptr;

	str_dest = (char *)dst;
	str_src = (char *)src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		str_dest[i] = str_src[i];
		if (str_src[i] == ((char)c))
			ptr = str_dest + i + 1;
		i++;
	}
	return (ptr);
}
