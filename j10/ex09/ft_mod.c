/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:09:25 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/16 18:53:59 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

t_op_result	ft_mod(int a, int b)
{
	if (a != 0 && b == 0)
		return (t_op_result){0, 0, "Stop : modulo by zero"};
	return (t_op_result){1, a % b, 0};
}
