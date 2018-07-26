/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/15 13:28:24 by fmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"
#include "result.h"

int		check_place(char grid[9][9], int x, int y, char num)
{
	int i;
	int j;
	int square_x;
	int square_y;

	i = -1;
	while (++i < 9)
		if ((i != x && grid[y][i] == num) || (i != y && grid[i][x] == num))
			return (0);
	square_x = (int)(x / 3) * 3;
	square_y = (int)(y / 3) * 3;
	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			if (grid[square_y + j][square_x + i] == num)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		put_num(char grid[9][9], char solution[9][9], int x, int y)
{
	char number;

	while (grid[y][x] != '.')
	{
		if (!increment_pos(grid, &x, &y, 0))
		{
			if (!store_solution(grid, solution))
				return (0);
			return (1);
		}
	}
	number = '1';
	while (number <= '9')
	{
		if (check_place(grid, x, y, number))
		{
			grid[y][x] = number;
			if (!put_num(grid, solution, x, y))
				return (0);
			grid[y][x] = '.';
		}
		number++;
	}
	return (1);
}

int		input(int argc, char **argv, char grid[9][9], char solution[9][9])
{
	int i;
	int j;

	if (argc != 10)
		return (0);
	j = 0;
	while (argv[j + 1])
	{
		i = 0;
		while (argv[j + 1][i])
		{
			if (!(argv[j + 1][i] >= '1' && argv[j + 1][i] <= '9') &&
				argv[j + 1][i] != '.')
				return (0);
			grid[j][i] = argv[j + 1][i];
			solution[j][i] = 0;
			i++;
		}
		if (i != 9)
			return (0);
		j++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	grid[9][9];
	char	solution[9][9];
	int		x;
	int		y;

	if (!input(argc, argv, grid, solution))
	{
		print_string("Error\n");
		return (0);
	}
	x = 0;
	y = 0;
	increment_pos(grid, &x, &y, 1);
	if (put_num(grid, solution, x, y) == 1 && solution[0][0] != 0)
		print_solution(solution);
	else
		print_string("Error\n");
	return (0);
}
