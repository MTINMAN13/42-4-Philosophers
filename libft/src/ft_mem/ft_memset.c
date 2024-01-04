/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:16:15 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:55:29 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

// The memset() function returns its first argument.
// writes len bytes of value c converted to the string b
// c is converted to unsigned char

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	buffer;

	buffer = 0;
	while (buffer < len)
		((char *)b)[buffer++] = (unsigned char)c;
	return (b);
}
