/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:48:42 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/25 10:34:50 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "number.h"
#include "character.h"
#include "map.h"

int		read_line(int fd, t_map *map, int line)
{
	int		partial_sum;
	char	c;

	while (read(fd, &c, 1) > 0 && c != '\n' && c != '\0')
	{
		partial_sum = get(map, map->data[line]->count, line - 1) +
			(get(map, map->data[line]->count - 1, line) -
			get(map, map->data[line]->count - 1, line - 1));
		if (c == map->obstacle_char)
			partial_sum++;
		else if (c != map->empty_char)
			return (0);
		if (!add_element(map->data[line], partial_sum))
			return (0);
	}
	return (1);
}

t_map	*get_map(int fd, int line_count, char empty, char obstacle)
{
	t_map	*map;
	int		line;
	int		line_length;

	if (!(map = create_map(line_count)))
		return (0);
	line = -1;
	line_length = 64;
	map->empty_char = empty;
	map->obstacle_char = obstacle;
	while (++line < line_count)
	{
		if (!(map->data[line] = create_list(line_length)))
			return (free_map(&map));
		if (!read_line(fd, map, line))
			return (free_map(&map));
		if (line == 0)
			line_length = map->data[line]->count;
		else if (map->data[line]->count != line_length)
			return (free_map(&map));
	}
	if (fd != 0 && read(fd, &empty, 1) > 0)
		return (free_map(&map));
	map->width = line_length;
	return (map);
}

int		check_params(t_list *params)
{
	int char1;
	int char2;
	int char3;

	char1 = get_element(params, params->count - 3);
	char2 = get_element(params, params->count - 2);
	char3 = get_element(params, params->count - 1);
	if (char1 == char2 || char1 == char3 || char2 == char3)
		return (0);
	return (1);
}

t_list	*read_params(int fd)
{
	char	c;
	t_list	*params;

	if (!(params = create_list(8)))
		return (0);
	while (read(fd, &c, 1) > 0 && c != '\n')
		if (!add_element(params, c))
			return (free_list(&params));
	return (params);
}

t_map	*parse_input(int fd)
{
	t_map	*map;
	char	c;
	t_list	*params;
	int		line_count;

	if (!(params = read_params(fd)))
		return (0);
	if (params->count >= 4)
	{
		if (!check_params(params))
			return (free_list(&params));
		c = get_element(params, params->count - 3);
		params->data[params->count - 3] = '\0';
		if ((line_count = ft_atoi(params->data)) <= 0)
			return (free_list(&params));
		if (!(map = get_map(fd, line_count, c,
							get_element(params, params->count - 2))))
			return (free_list(&params));
		map->full_char = get_element(params, params->count - 1);
	}
	else
		return (free_list(&params));
	free_list(&params);
	return (map);
}
