/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:17:45 by mman              #+#    #+#             */
/*   Updated: 2023/11/20 21:17:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the function returns the amount of printed characters
// the function prints the pointer to passed argument

#include "libft.h"

int	ft_handle_x_ptr(unsigned long long num)
{
	int		count;
	char	c;

	count = 0;
	if (num < 16)
	{
		if (num <= 9)
			c = num + '0';
		else
			c = num - 10 + 'a';
		ft_putchar_fd(c, 1);
		count = 1;
	}
	else
	{
		count += ft_handle_x_ptr(num / 16);
		count += ft_handle_x_ptr(num % 16);
	}
	return (count);
}

int	ft_print_pointer(void *hi)
{
	unsigned long long	fuckingpointer;
	int					returnvalue;

	fuckingpointer = (unsigned long long)hi;
	returnvalue = 0;
	returnvalue += ft_handle_s("0x");
	if (fuckingpointer == 0)
		returnvalue += ft_handle_s("0");
	else
	{
		returnvalue += ft_handle_x_ptr(fuckingpointer);
	}
	return (returnvalue);
}
// int	main(void)
// {
// 	printf("%p", "what");
// 	ft_print_pointer("what");
// 	return(0);
// }
// int	main(void)
// {
// 	int x = 25;
// 	int pointertox = &x;
// 	write(1, pointertox, 10);
// 	return(0);
// }
// #include <stdio.h>
// #include <stdlib.h>
// int G = 0;   /* a global variable, stored in BSS segment */
// int	main(int argc, char **argv)
// {
// 	static int s;  /* static local variable, stored in BSS segment */
// 	int a;         /* automatic variable, stored on stack */
// 	int *p;        /* pointer variable for malloc below */
// 	/* obtain a block big enough for one int from the heap */
// 	p = malloc(sizeof(int));
// 	printf("\n%i\n", printf("%p", (void *) &G));
// 	printf("&s   = %p\n", (void *) &s);
// 	printf("&a   = %p\n", (void *) &a);
// 	printf("&p   = %p\n", (void *) &p);
// 	printf("p    = %p\n", (void *) p);
// 	printf("main = %p\n", (void *) main);
// 	free(p);
// 	return 0;
// }
