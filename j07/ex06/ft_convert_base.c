/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		index_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

int		get_number(char *nbr, char *base_from)
{
	int base;
	int i;
	int result;

	base = 0;
	while (base_from[base] != '\0')
		base++;
	i = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		i++;
	result = 0;
	while (nbr[i] != '\0')
	{
		result *= base;
		result += index_in_base(nbr[i], base_from);
		i++;
	}
	if (nbr[0] == '-')
		result = -result;
	return (result);
}

int		allocate_number(char **result, int number, int base)
{
	int length;

	length = 0;
	while (number > 0)
	{
		number /= base;
		length++;
	}
	*result = (char *)malloc(sizeof(char) * (length + 1));
	return (length);
}

char	*convert_number(int number, char *base_to)
{
	char	*result;
	int		i;
	int		length;
	int		base;

	base = 0;
	while (base_to[base] != '\0')
		base++;
	length = allocate_number(&result, number, base);
	i = 0;
	while (number > 0)
	{
		result[length - i - 1] = base_to[number % base];
		number /= base;
		i++;
	}
	result[length] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*result;

	result = 0;
	number = get_number(nbr, base_from);
	result = convert_number(number, base_to);
	return (result);
}
