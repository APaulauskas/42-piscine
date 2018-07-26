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

t_stack		*create_elem(long long value)
{
	t_stack *result;

	result = (t_stack *)malloc(sizeof(t_stack));
	result->value = value;
	result->next = 0;
	return (result);
}

void		push_stack(t_stack **stack, long long value)
{
	t_stack *temp;

	temp = create_elem(value);
	if (!*stack)
		*stack = temp;
	else
	{
		temp->next = *stack;
		*stack = temp;
	}
}

long long	pop_stack(t_stack **stack)
{
	long long	result;
	t_stack		*next;

	if (!*stack)
		return (0);
	result = (*stack)->value;
	next = (*stack)->next;
	free(*stack);
	*stack = next;
	return (result);
}
