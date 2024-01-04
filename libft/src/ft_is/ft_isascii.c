/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:15:56 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:54:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

// whether c is a 7-bit unsigned char value that  fits  into ASCII characte

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}

// int	main(void)
// {
// 	char whatever = 'ř';
// 	int	stuff = ft_isascii(whatever);
// 	printf("isascii for %c;  %d", whatever, stuff);
// 	return (0);
// }
