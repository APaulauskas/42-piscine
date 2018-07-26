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

int		ft_list_size(t_list *begin_list)
{
	int result;

	result = 0;
	while (begin_list)
	{
		result++;
		begin_list = begin_list->next;
	}
	return (result);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	t_list	*swapper;
	void	*temp;
	int		length;
	int		i;

	length = ft_list_size(begin_list);
	current = begin_list;
	while (length > 0)
	{
		i = 0;
		swapper = current;
		while (i < length - 1 && swapper && swapper->next)
		{
			temp = swapper->data;
			swapper->data = swapper->next->data;
			swapper->next->data = temp;
			swapper = swapper->next;
			i++;
		}
		length--;
		current = begin_list;
	}
}
