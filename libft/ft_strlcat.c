/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:19:49 by mbond             #+#    #+#             */
/*   Updated: 2018/06/11 13:31:12 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *dest, const char *src, int len)
{
	int i;
	int d;

	d = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	ft_join(dst, src, dstsize - (dstlen + 1));
	return (dstlen + srclen);
}
