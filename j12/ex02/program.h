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

typedef struct	s_result
{
	int		status;
	int		value;
	char	*error;
}				t_result;

void			ft_putchar(int file_descriptor, char c);
void			ft_putstr(int file_descriptor, char *str);
int				ft_strncmp(char *s1, char *s2, int n);
t_result		ft_atoi(char *str);

#endif
