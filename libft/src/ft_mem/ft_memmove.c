/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:16:12 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:55:27 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
// move parts of one string to another

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*source;
	char	*destination;

	i = 0;
	if (len == 0)
		return (dst);
	if (((dst == NULL && src == NULL) && len == 0)
		|| ((dst == NULL && src == NULL)))
		return (NULL);
	source = (char *)src;
	destination = (char *)dst;
	if (destination > source)
		while (len-- > 0)
			destination[len] = source[len];
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}
