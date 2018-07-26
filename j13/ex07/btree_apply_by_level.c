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
#include "ft_btree.h"

t_node	*create_node(t_btree *item)
{
	t_node *result;

	result = (t_node *)malloc(sizeof(t_node));
	result->item = item;
	result->next = 0;
	result->is_first = 0;
	result->level = 0;
	return (result);
}

void	expand_leaf(t_node **queue, t_node **end)
{
	if ((*queue)->item->left)
	{
		(*end)->next = create_node((*queue)->item->left);
		if ((*queue)->level + 1 > (*end)->level)
			(*end)->next->is_first = 1;
		*end = (*end)->next;
		(*end)->level = (*queue)->level + 1;
	}
	if ((*queue)->item->right)
	{
		(*end)->next = create_node((*queue)->item->right);
		if ((*queue)->level + 1 > (*end)->level)
			(*end)->next->is_first = 1;
		*end = (*end)->next;
		(*end)->level = (*queue)->level + 1;
	}
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_node *queue;
	t_node *next;
	t_node *end;

	queue = create_node(root);
	queue->is_first = 1;
	end = queue;
	while (queue)
	{
		expand_leaf(&queue, &end);
		applyf(queue->item->item, queue->level, queue->is_first);
		next = queue->next;
		free(queue);
		queue = next;
	}
}
