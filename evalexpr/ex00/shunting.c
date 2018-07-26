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

void	handle_end_paren(t_stack **ops, t_stack **output)
{
	long long	temp;
	long long	value1;
	long long	value2;

	while ((temp = pop_stack(ops)) != 0 && temp != '(')
	{
		value2 = pop_stack(output);
		value1 = pop_stack(output);
		push_stack(output, exec_op(temp, value1, value2));
	}
}

void	handle_operator(char op, t_stack **ops, t_stack **output)
{
	long long	value1;
	long long	value2;

	while (*ops && precedence((*ops)->value) >= precedence(op))
	{
		value2 = pop_stack(output);
		value1 = pop_stack(output);
		push_stack(output, exec_op(pop_stack(ops), value1, value2));
	}
	push_stack(ops, op);
}

void	handle_unary(char op, t_stack **ops, t_stack **output)
{
	if (op == '.')
	{
		push_stack(output, 0);
		push_stack(ops, '.');
	}
}

void	handle_leftover(t_stack **ops, t_stack **output)
{
	long long	value1;
	long long	value2;

	while (*ops)
	{
		value2 = pop_stack(output);
		value1 = pop_stack(output);
		push_stack(output, exec_op(pop_stack(ops), value1, value2));
	}
}

void	handle_number(t_stack **output, char *str, int *i)
{
	push_stack(output, ft_atoi(&str[*i]));
	while (str[*i + 1] >= '0' && str[*i + 1] <= '9')
		(*i)++;
}
