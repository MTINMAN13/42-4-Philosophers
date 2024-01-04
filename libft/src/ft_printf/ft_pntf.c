/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:06:20 by apple             #+#    #+#             */
/*   Updated: 2023/11/20 21:17:52 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pntf(const char *to_be_printed, ...)
{
	va_list	conversions;
	int		chars_printed;

	if (to_be_printed == NULL)
		return (0);
	chars_printed = 0;
	va_start(conversions, to_be_printed);
	while (*to_be_printed)
	{
		if (*to_be_printed == '%')
		{
			to_be_printed++;
			chars_printed += ft_printfhandler(conversions, *to_be_printed);
		}
		else
			chars_printed += ft_putcharo(*to_be_printed);
		to_be_printed++;
	}
	va_end(conversions);
	ft_putcharo('\n');
	return (chars_printed);
}
