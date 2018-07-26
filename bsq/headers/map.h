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

#ifndef MAP_H
# define MAP_H

# include "list.h"

typedef struct	s_map
{
	char	empty_char;
	char	obstacle_char;
	char	full_char;
	int		width;
	int		height;
	t_list	**data;
}				t_map;

t_map			*create_map(int line_count);
int				get(t_map *map, int x, int y);
void			*free_map(t_map **map);

#endif
