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

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_head;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		new_head = ft_create_elem(data);
		new_head->next = *begin_list;
		*begin_list = new_head;
	}
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*result;
	int		i;

	if (ac <= 0)
		return (0);
	result = ft_create_elem(av[0]);
	i = 1;
	while (i < ac)
	{
		ft_list_push_front(&result, av[i]);
		i++;
	}
	return (result);
}
