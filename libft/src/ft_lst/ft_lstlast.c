/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:24:12 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:55:14 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns the last node in a list

#include "libft.h"

t_list
	*ft_lstlast(t_list *lst)
{
	t_list	*clone;

	if (lst == 0)
		return (NULL);
	clone = lst;
	while (clone->next)
		clone = clone->next;
	return (clone);
}
