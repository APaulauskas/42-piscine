/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int in_word;

	i = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!in_word)
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 'a' - 'A';
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (str);
}
