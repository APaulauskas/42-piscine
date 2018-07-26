/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:09:25 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 20:09:37 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

int			eval_expr(char *str)
{
	int			i;
	t_stack		*output;
	t_stack		*ops;

	str = remove_whitespace(str);
	i = -1;
	ops = 0;
	output = 0;
	while (str[++i])
	{
		if (str[i] == '(')
			push_stack(&ops, str[i]);
		else if (str[i] == '.' || str[i] == ',')
			handle_unary(str[i], &ops, &output);
		else if (str[i] >= '0' && str[i] <= '9')
			handle_number(&output, str, &i);
		else if (str[i] == ')')
			handle_end_paren(&ops, &output);
		else
			handle_operator(str[i], &ops, &output);
	}
	handle_leftover(&ops, &output);
	free(str);
	return (pop_stack(&output));
}
