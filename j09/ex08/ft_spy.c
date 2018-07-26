/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_string(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
}

void	lowercase(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
			string[i] += 'a' - 'A';
		i++;
	}
}

int		is_alert_loops(int i, char *string, int word, char *words[3])
{
	while (word < 3)
	{
		if (string[0] == words[word][0])
			break ;
		if (word == 2)
			return (0);
		word++;
	}
	while (words[word][i] != '\0')
	{
		if (string[i] != words[word][i])
			return (0);
		i++;
	}
	while (string[i] != '\0')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		is_alert(char *string)
{
	char *words[3];

	lowercase(string);
	words[0] = "president";
	words[1] = "attack";
	words[2] = "bauer";
	if (!is_alert_loops(0, string, 0, words))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '\t')
			{
				if (is_alert(&av[i][j]))
				{
					print_string("Alert!!!\n");
				}
				else
					break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
