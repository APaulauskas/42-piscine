/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:25:28 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/15 16:25:30 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_line_numbers(char line[9])
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < 9)
	{
		if (line[i] != '.')
			result++;
		i++;
	}
	return (result);
}

int		get_best_line(char grid[9][9])
{
	int i;
	int biggest;
	int best_y;
	int count;

	i = 0;
	biggest = -1;
	best_y = -1;
	while (i < 9)
	{
		count = count_line_numbers(grid[i]);
		if (count > biggest && count < 9)
		{
			biggest = count;
			best_y = i;
		}
		i++;
	}
	return (best_y);
}

int		increment_pos(char grid[9][9], int *x, int *y, int find_best)
{
	int best_y;

	if (*x < 8 && !find_best)
		(*x)++;
	else
	{
		best_y = get_best_line(grid);
		if (best_y == -1)
			return (0);
		*x = 0;
		*y = best_y;
	}
	return (1);
}
