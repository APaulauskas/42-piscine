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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_operator(char c)
{
	if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*remove_whitespace(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (is_operator(str[i]) || is_number(str[i]) || str[i] == '('
			|| str[i] == ')')
		{
			if ((i == 0 && (str[i] == '+' || str[i] == '-')) ||
				(i > 0 && (str[i] == '+' || str[i] == '-')
				&& (is_operator(result[j - 1]) || result[j - 1] == '(')))
				result[j++] = str[i] + 1;
			else
				result[j++] = str[i];
		}
	}
	result[j] = '\0';
	return (result);
}
