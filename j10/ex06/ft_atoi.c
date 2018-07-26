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

t_op_result	ft_atoi(char *str)
{
	int i;
	int result;
	int success;

	i = 0;
	success = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		success = 1;
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return (t_op_result){success, result, 0};
}
