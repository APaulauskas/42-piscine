/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_place(int *positions, int ocuppied_columns, int row)
{
	int i;

	i = 0;
	while (i < ocuppied_columns)
	{
		if (positions[i] == row ||
			positions[i] - i == row - ocuppied_columns ||
			positions[i] + i == row + ocuppied_columns)
			return (0);
		i++;
	}
	return (1);
}

int	put_queen(int size, int *positions, int column)
{
	int row;
	int solutions;

	solutions = 0;
	if (column == size)
		solutions++;
	else
	{
		row = 0;
		while (row < size)
		{
			if (check_place(positions, column, row))
			{
				positions[column] = row;
				solutions += put_queen(size, positions, column + 1);
			}
			row++;
		}
	}
	return (solutions);
}

int	ft_eight_queens_puzzle(void)
{
	int positions[8];

	return (put_queen(8, positions, 0));
}
