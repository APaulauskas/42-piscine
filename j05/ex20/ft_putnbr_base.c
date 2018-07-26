/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_base_number(char *base)
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

void	print(long long num, char *base, int base_number)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= base_number)
		print(num / (long long)base_number, base, base_number);
	ft_putchar(base[num % (long long)base_number]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_number;

	base_number = get_base_number(base);
	if (!base_number)
		return ;
	print((long long)nbr, base, base_number);
}
