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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *current;
	t_list *previous;
	t_list *temp;

	current = *begin_list;
	previous = 0;
	while (current && cmp(current->data, data) < 0)
	{
		previous = current;
		current = current->next;
	}
	temp = ft_create_elem(data);
	temp->next = current;
	if (current == *begin_list)
		*begin_list = temp;
	else
		previous->next = temp;
}
