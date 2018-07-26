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

int		is_part_of_set(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		add_next_word(char **result, int word, char *str, char *charset)
{
	int length;
	int i;
	int pos;

	pos = 0;
	while (is_part_of_set(str[pos], charset))
		pos++;
	length = 0;
	while (!is_part_of_set(str[pos + length], charset) &&
			str[pos + length] != '\0')
		length++;
	result[word] = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		result[word][i] = str[pos + i];
		i++;
	}
	result[word][i] = '\0';
	return (pos + length);
}

int		get_word_count(char *str, char *charset)
{
	int i;
	int word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (is_part_of_set(str[i], charset))
			i++;
		if (str[i] == '\0')
			break ;
		word_count++;
		while (!(is_part_of_set(str[i], charset) ||
				str[i] == '\0'))
			i++;
	}
	return (word_count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**result;
	int		word;
	int		word_count;

	word_count = get_word_count(str, charset);
	result = (char **)malloc(sizeof(char **) * (word_count + 1));
	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		i += add_next_word(result, word, str + i, charset);
		word++;
	}
	result[word_count] = 0;
	return (result);
}
