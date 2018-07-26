/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 21:08:24 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/25 10:31:00 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

t_map	*create_map(int line_count)
{
	t_map	*result;
	int		i;

	result = malloc(sizeof(t_map));
	if (!result)
		return (0);
	result->data = malloc(sizeof(t_list *) * line_count);
	if (!result->data)
	{
		free(result);
		return (0);
	}
	i = -1;
	while (++i < line_count)
		result->data[i] = 0;
	result->empty_char = 0;
	result->obstacle_char = 0;
	result->full_char = 0;
	result->width = 0;
	result->height = line_count;
	return (result);
}

int		get(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	return (get_element(map->data[y], x));
}

void	*free_map(t_map **map)
{
	int i;

	if (*map)
	{
		i = -1;
		if ((*map)->data)
		{
			while ((*map)->data[++i] && i < (*map)->height)
				free_list(&(*map)->data[i]);
			free((*map)->data);
		}
		free(*map);
	}
	return (0);
}
