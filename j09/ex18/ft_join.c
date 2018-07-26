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

int		get_length(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int		get_total_length(char **argv, int sep_length)
{
	int i;
	int j;
	int length;

	length = 0;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			length++;
			j++;
		}
		length += sep_length;
		i++;
	}
	return (length - sep_length + 1);
}

void	add_sep(char *result, int *total, char *sep, int sep_length)
{
	int k;

	k = 0;
	while (k < sep_length)
	{
		result[*total + k] = sep[k];
		k++;
	}
	*total += sep_length;
}

void	concat(char *result, char **argv, char *sep, int sep_length)
{
	int i;
	int j;
	int total;

	i = 0;
	total = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			result[total] = argv[i][j];
			total++;
			j++;
		}
		if (argv[i + 1])
			add_sep(result, &total, sep, sep_length);
		else
		{
			result[total] = '\0';
			total++;
		}
		i++;
	}
}

char	*ft_join(char **argv, char *sep)
{
	int		length;
	char	*result;
	int		sep_length;

	if (!argv[0])
		return ("");
	sep_length = get_length(sep);
	length = get_total_length(argv, sep_length);
	result = (char *)malloc(sizeof(char) * length);
	concat(result, argv, sep, sep_length);
	return (result);
}
