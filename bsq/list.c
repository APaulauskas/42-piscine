/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:08:24 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/21 21:08:26 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list	*create_list(int size)
{
	t_list *result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (0);
	result->data = (int *)malloc(sizeof(int) * size);
	if (!result->data)
	{
		free(result);
		return (0);
	}
	result->size = size;
	result->count = 0;
	return (result);
}

/*
** returns whether the list size was succesfully doubled
*/

int		expand_list(t_list *list)
{
	int i;
	int *new_data;

	new_data = (int *)malloc(sizeof(int) * (list->size * 2));
	if (!new_data)
		return (0);
	i = 0;
	while (i < list->count)
	{
		new_data[i] = list->data[i];
		i++;
	}
	free(list->data);
	list->data = new_data;
	list->size = list->size * 2;
	return (1);
}

/*
** returns whether the element was succesfully added
*/

int		add_element(t_list *list, int element)
{
	if (list->count < list->size || expand_list(list))
	{
		list->data[list->count++] = element;
		return (1);
	}
	return (0);
}

int		get_element(t_list *list, int index)
{
	return (list->data[index]);
}

void	*free_list(t_list **list)
{
	if (*list)
	{
		if ((*list)->data)
			free((*list)->data);
		free(*list);
	}
	return (0);
}
