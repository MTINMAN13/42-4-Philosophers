/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoidouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:38:43 by mman              #+#    #+#             */
/*   Updated: 2024/01/04 18:17:12 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_whitespaces(const char *str, int i)
{
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	return (i);
}

static int	ft_sign_handler(const char *str, int *sign, int i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			*sign = -1;
	}
	return (i);
}

static void	ft_integer_processor(const char *str, double *result, int *i)
{
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		*result *= 10.0;
		*result += str[(*i)++] - '0';
	}
}

static void	ft_decimals_processor(const char *str, double *fraction, int *i)
{
	double	decimal;

	if (str[*i] == '.')
	{
		(*i)++;
		decimal = 0.1;
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		{
			*fraction += (str[(*i)++] - '0') * decimal;
			decimal *= 0.1;
		}
	}
}

double	ft_atoidouble(const char *str)
{
	int		sign;
	double	result;
	double	fraction;
	int		i;

	sign = 1;
	result = 0.0;
	fraction = 0.0;
	i = 0;
	i = ft_skip_whitespaces(str, i);
	i = ft_sign_handler(str, &sign, i);
	ft_integer_processor(str, &result, &i);
	ft_decimals_processor(str, &fraction, &i);
	result = result * sign + fraction * sign;
	return (result);
}
