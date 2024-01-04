/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:29 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:56:06 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

// locates first occurrence of null terminated string little in string big
// where no more than len characters are searched (not searched after a '\0')

// if little is empty string, big is returned
// if litztle occurs nowhere in big, NULL is returned
// otherwise pointer to the first char of first occured little is returned

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			length;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	length = ft_strlen((char *)little);
	while ((((char *)big)[i] != '\0' && (i + length) <= len) && (len != 0))
	{
		if (ft_strncmp(((char *)big + i), (char *)little, length) == 0)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
