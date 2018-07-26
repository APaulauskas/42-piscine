/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/25 10:25:07 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"

int		ft_atoi(int *str)
{
	int i;
	int result;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}
