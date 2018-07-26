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

#ifndef LIST_H
# define LIST_H

typedef struct	s_list
{
	int *data;
	int count;
	int size;
}				t_list;

t_list			*create_list(int size);
int				add_element(t_list *list, int element);
int				get_element(t_list *list, int index);
void			*free_list(t_list **list);

#endif
