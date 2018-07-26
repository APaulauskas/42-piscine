/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *current;
	t_list *previous;
	t_list *next;

	current = *begin_list;
	previous = 0;
	while (current && current->next)
	{
		next = current->next;
		if (cmp(current->data, next->data) > 0)
		{
			if (previous)
				previous->next = next;
			if (current == *begin_list)
				*begin_list = next;
			current->next = next->next;
			next->next = current;
			current = *begin_list;
			previous = 0;
			continue;
		}
		previous = current;
		current = next;
	}
}
