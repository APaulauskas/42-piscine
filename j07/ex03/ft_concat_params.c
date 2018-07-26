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

int		get_total_length(int argc, char **argv)
{
	int i;
	int j;
	int length;

	length = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			length++;
			j++;
		}
		length++;
		i++;
	}
	return (length);
}

void	concat(char *result, int argc, char **argv)
{
	int i;
	int j;
	int total;

	i = 0;
	total = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			result[total] = argv[i][j];
			total++;
			j++;
		}
		if (i < argc - 1)
			result[total] = '\n';
		else
			result[total] = '\0';
		total++;
		i++;
	}
}

char	*ft_concat_params(int argc, char **argv)
{
	int		length;
	char	*result;

	length = get_total_length(argc, argv);
	result = (char *)malloc(sizeof(char) * length);
	concat(result, argc, argv);
	return (result);
}
