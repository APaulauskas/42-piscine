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

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	long long		value;
	struct s_stack	*next;
}					t_stack;

typedef long long	(*t_operation)(long long, long long);

void				push_stack(t_stack **stack, long long value);
long long			pop_stack(t_stack **stack);

long long			ft_atoi(char *str);
void				ft_putnbr(int num);

void				ft_putchar(char c);
char				*remove_whitespace(char *str);

int					precedence(char op);
long long			exec_op(char op, long long a, long long b);

void				handle_end_paren(t_stack **ops, t_stack **output);
void				handle_operator(char op, t_stack **ops, t_stack **output);
void				handle_unary(char op, t_stack **ops, t_stack **output);
void				handle_leftover(t_stack **ops, t_stack **output);
void				handle_number(t_stack **output, char *str, int *i);

int					eval_expr(char *str);

#endif
