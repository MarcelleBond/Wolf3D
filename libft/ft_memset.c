/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:05:16 by mbond             #+#    #+#             */
/*   Updated: 2018/06/07 12:06:59 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b_char;

	b_char = (unsigned char *)b;
	while (len > 0)
	{
		*b_char = (char)c;
		b_char++;
		len--;
	}
	return (b);
}
