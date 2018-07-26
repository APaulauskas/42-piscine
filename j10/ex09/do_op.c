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
#include "ft_opp.h"

t_op_result	ft_usage(int a, int b)
{
	int i;

	(void)a;
	(void)b;
	ft_putstr("error : only [ ");
	i = 0;
	while (*g_opptab[i].op)
	{
		ft_putstr(g_opptab[i].op);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("] are accepted.");
	return (t_op_result){0, 0, ""};
}

t_op_func	get_function(char *op)
{
	int i;

	i = 0;
	while (*g_opptab[i].op)
	{
		if (ft_strcmp(g_opptab[i].op, op) == 0)
			return (g_opptab[i].function);
		i++;
	}
	return (g_opptab[i].function);
}

void		execute(int num1, int num2, t_op_func function)
{
	t_op_result result;

	result = function(num1, num2);
	if (result.succeeded)
		ft_putnbr(result.value);
	else
		ft_putstr(result.error_message);
}

int			main(int argc, char **argv)
{
	t_op_result	num1;
	t_op_result	num2;
	t_op_func	function;

	if (argc != 4)
		return (0);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	function = get_function(argv[2]);
	execute(num1.value, num2.value, function);
	ft_putchar('\n');
	return (0);
}
