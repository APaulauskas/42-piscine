/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/16 18:52:51 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

t_result	ft_atoi(char *str)
{
	int i;
	int result;
	int success;
	int sign;

	i = 0;
	sign = -1;
	success = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i = 1;
	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (t_result){0, 0, 0};
		success = 1;
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	return (t_result){success, (sign == -1 ? result + 1 : result) * sign, 0};
}
