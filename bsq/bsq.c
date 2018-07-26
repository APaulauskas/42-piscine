/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:48:42 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/25 13:11:39 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "input.h"
#include "character.h"

void	print_map(t_map *map, int sx, int sy, int size)
{
	int y;
	int x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x >= sx && x < sx + size && y >= sy && y < sy + size)
				ft_putchar(1, map->full_char);
			else if (get(map, x, y) - get(map, x - 1, y) - get(map, x, y - 1) +
					get(map, x - 1, y - 1) > 0)
				ft_putchar(1, map->obstacle_char);
			else
				ft_putchar(1, map->empty_char);
		}
		ft_putchar(1, '\n');
	}
}

void	find_square(t_map *map, int *best_x, int *best_y, int *size)
{
	int x;
	int y;

	y = -1;
	while (++y + *size < map->height)
	{
		x = -1;
		while (++x + *size < map->width)
		{
			if ((get(map, x + *size, y + *size) - get(map, x - 1, y + *size) -
				get(map, x + *size, y - 1) + get(map, x - 1, y - 1)) == 0)
			{
				*best_x = x;
				*best_y = y;
				(*size)++;
				y = -1;
				break ;
			}
		}
	}
}

int		bsq(int fd)
{
	t_map	*map;
	int		best_x;
	int		best_y;
	int		size;

	map = parse_input(fd);
	if (!map)
		return (0);
	best_x = 0;
	best_y = 0;
	size = 0;
	find_square(map, &best_x, &best_y, &size);
	print_map(map, best_x, best_y, size);
	free_map(&map);
	return (1);
}
