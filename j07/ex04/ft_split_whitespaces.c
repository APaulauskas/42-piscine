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

int		add_next_word(char **result, int word, int pos, char *str)
{
	int length;
	int i;

	length = 0;
	while (str[pos + length] == ' ' || str[pos + length] == '\t' ||
		str[pos + length] == '\n')
		pos++;
	while (str[pos + length] != ' ' && str[pos + length] != '\t' &&
		str[pos + length] != '\n' && str[pos + length] != '\0')
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

int		get_word_count(char *str)
{
	int i;
	int word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] == '\0')
			break ;
		word_count++;
		while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\0'))
			i++;
	}
	return (word_count);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	char	**result;
	int		word;
	int		word_count;

	word_count = get_word_count(str);
	result = (char **)malloc(sizeof(char **) * (word_count + 1));
	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		i = add_next_word(result, word, i, str);
		word++;
	}
	result[word_count] = 0;
	return (result);
}
