/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_base_number(char *base)
{
	int		i;
	char	chars[128];

	if (!base)
		return (0);
	i = 0;
	while (i < 128)
	{
		chars[i] = 0;
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 32 || base[i] > 126 || base[i] == '-' || base[i] == '+')
			return (0);
		if (chars[base[i]] == 0)
			chars[base[i]] = 1;
		else
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	index_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_number;
	int			i;
	long long	result;

	base_number = get_base_number(base);
	if (!base_number || !str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	result = 0;
	while (str[i] != '\0')
	{
		if (index_in_base(str[i], base) == -1)
			return (0);
		result *= base_number;
		result += index_in_base(str[i], base);
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return ((int)result);
}
