/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:16:00 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:55:02 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

// checks for any printable character including space.

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
