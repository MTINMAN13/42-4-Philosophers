/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:37 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:54:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

// erases data in n bytes of the memory starting at the location
// pointed to by s            by writing zeros to that area

void	ft_bzero(void *s, size_t n)
{
	char	*c_pointer;

	c_pointer = (char *)s;
	while (n > 0)
	{
		*c_pointer = '\0';
		c_pointer++;
		n--;
	}
}
