/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:17:42 by mman              #+#    #+#             */
/*   Updated: 2023/11/20 21:23:04 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_numlen(long n, int base)
{
	unsigned long long	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!(s))
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_print_u(long n)
{
	unsigned int			len;
	char					*ret;
	const char				*digits;

	digits = "0123456789";
	len = ft_numlen(n, 10);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return ;
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	ft_putstr_fd(ret, 1);
	free(ret);
}

int	ft_handle_u(unsigned int n)
{
	ft_print_u(n);
	return (ft_numlen(n, 10));
}

int	ft_handle_di(int i)
{
	int	len;

	len = ft_numlen(i, 10);
	ft_putnbr_fd(i, 1);
	return (len);
}

// int	main(void)
// {
// 	ft_handle_u(ft_handle_u(1000));
// 	return(0);
// }
