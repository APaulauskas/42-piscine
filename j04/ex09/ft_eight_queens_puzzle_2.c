/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		check_place(int *positions, int ocuppied_columns, int row)
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

void	print_solution(int size, int *positions)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(positions[i] + '0' + 1);
		i++;
	}
	ft_putchar('\n');
}

void	put_queen(int size, int *positions, int column)
{
	int row;

	if (column == size)
		print_solution(size, positions);
	else
	{
		row = 0;
		while (row < size)
		{
			if (check_place(positions, column, row))
			{
				positions[column] = row;
				put_queen(size, positions, column + 1);
			}
			row++;
		}
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int positions[8];

	put_queen(8, positions, 0);
}
