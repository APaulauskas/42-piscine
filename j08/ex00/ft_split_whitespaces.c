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

int		is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && !is_separator(str[i])) ||
			(i > 0 && is_separator(str[i - 1]) && !is_separator(str[i])))
			words++;
		i++;
	}
	return (words);
}

void	split_words(char **result, char *str)
{
	int i;
	int word;
	int length;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && !is_separator(str[i])) ||
			(i > 0 && is_separator(str[i - 1]) && !is_separator(str[i])))
		{
			length = 0;
			while (!is_separator(str[i + length]))
				length++;
			result[word] = (char *)malloc(sizeof(char) * (length + 1));
			result[word][length--] = '\0';
			while (length >= 0)
			{
				result[word][length] = str[i + length];
				length--;
			}
			word++;
		}
		i++;
	}
}

char	**ft_split_whitespaces(char *str)
{
	char	**result;
	int		words;

	words = count_words(str);
	result = (char **)malloc(sizeof(char **) * (words + 1));
	split_words(result, str);
	result[words] = 0;
	return (result);
}
