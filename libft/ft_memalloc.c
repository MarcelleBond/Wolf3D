/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:15:56 by mbond             #+#    #+#             */
/*   Updated: 2018/06/08 08:45:18 by mbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	j;
	void	*pointer;

	j = 0;
	if (!(pointer = malloc(size)))
		return (NULL);
	while (j < size)
	{
		((unsigned char *)pointer)[j] = 0;
		j++;
	}
	return (pointer);
}
