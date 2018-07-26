/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

int			precedence(char op)
{
	if (op == '.')
		return (3);
	if (op == '*' || op == '/' || op == '%')
		return (2);
	if (op == '+' || op == '-')
		return (1);
	return (0);
}

long long	exec_op(char op, long long a, long long b)
{
	if (op == '+')
		return (a + b);
	else if (op == '-' || op == '.')
		return (a - b);
	else if (op == '/')
		return (a / b);
	else if (op == '*')
		return (a * b);
	else if (op == '%')
		return (a % b);
	return (0);
}
