/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:12:37 by mman              #+#    #+#             */
/*   Updated: 2023/10/28 21:55:21 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*node;
	t_list	*next_node;

	node = lst;
	while (node)
	{
		next_node = node->next;
		f(node->content);
		node = next_node;
	}
}
