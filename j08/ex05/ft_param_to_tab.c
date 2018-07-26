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

#include <stdlib.h>
#include "ft_stock_par.h"

char				**ft_split_whitespaces(char *str);
void				ft_show_tab(struct s_stock_par *par);

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			length;
	t_stock_par	*result;

	i = 0;
	result = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		length = 0;
		while (av[i][length] != '\0')
			length++;
		result[i].size_param = length;
		result[i].str = av[i];
		result[i].copy = (char *)malloc(sizeof(char) * (length + 1));
		result[i].copy[length] = '\0';
		while (--length >= 0)
		{
			result[i].copy[length] = av[i][length];
		}
		result[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
