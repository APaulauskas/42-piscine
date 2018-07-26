/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:21:48 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/15 16:21:52 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_string(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}

void	print_solution(char grid[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			write(1, &grid[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		print_string("\n");
		i++;
	}
}

int		store_solution(char grid[9][9], char solution[9][9])
{
	int i;
	int j;

	if (solution[0][0] != 0)
		return (0);
	j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9)
		{
			solution[j][i] = grid[j][i];
			i++;
		}
		j++;
	}
	return (1);
}
