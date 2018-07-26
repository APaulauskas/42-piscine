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

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *head;
	t_list *temp;

	head = *begin_list;
	while (head && head->next)
	{
		if (cmp(head->next->data, data_ref) == 0)
		{
			temp = head->next->next;
			free(head->next);
			head->next = temp;
		}
		else
			head = head->next;
	}
	if (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
		*begin_list = (*begin_list)->next;
}
