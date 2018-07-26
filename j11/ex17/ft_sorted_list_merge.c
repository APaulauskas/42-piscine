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

void	find_insertion_spot(t_list **current, t_list **previous,
							t_list *insertion, int (*cmp)())
{
	while (*current && cmp((*current)->data, insertion->data) < 0)
	{
		*previous = *current;
		*current = (*current)->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
							int (*cmp)())
{
	t_list *current;
	t_list *previous;
	t_list *insertion;
	t_list *next;

	insertion = begin_list2;
	previous = 0;
	current = *begin_list1;
	while (insertion)
	{
		if (previous)
			current = previous;
		find_insertion_spot(&current, &previous, insertion, cmp);
		next = insertion->next;
		insertion->next = current;
		if (current == *begin_list1)
		{
			*begin_list1 = insertion;
			current = *begin_list1;
		}
		else
			previous->next = insertion;
		insertion = next;
	}
}
