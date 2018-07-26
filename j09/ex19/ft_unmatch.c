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

void	matches(int *tab, int length, int *has_pair)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (!has_pair[j] && !has_pair[i] && tab[i] == tab[j] && i != j)
			{
				has_pair[j] = 1;
				has_pair[i] = 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

int		ft_unmatch(int *tab, int length)
{
	int i;
	int has_pair[length];

	i = -1;
	while (++i < length)
		has_pair[i] = 0;
	matches(tab, length, has_pair);
	i = 0;
	while (i < length)
	{
		if (!has_pair[i])
			return (tab[i]);
		i++;
	}
	return (0);
}
