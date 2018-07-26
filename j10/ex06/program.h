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

#ifndef PROGRAM_H
# define PROGRAM_H

typedef struct		s_op_result
{
	int		succeeded;
	int		value;
	char	*error_message;
}					t_op_result;

typedef t_op_result	(*t_op_func)(int, int);

typedef struct		s_opp
{
	char		*op;
	t_op_func	function;
}					t_opp;

t_op_result			ft_atoi(char *str);

t_op_result			ft_add(int a, int b);
t_op_result			ft_sub(int a, int b);
t_op_result			ft_mul(int a, int b);
t_op_result			ft_div(int a, int b);
t_op_result			ft_mod(int a, int b);

void				ft_putchar(char c);
void				ft_putnbr(int num);
void				ft_putstr(char *str);
int					ft_strcmp(char *s1, char *s2);

#endif
