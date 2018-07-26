/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr_base16(long long nbr, int digits)
{
	char *base;

	*base = "0123456789abcdef";
	if (digits > 1)
		ft_putnbr_base16(nbr / 16, digits - 1);
	ft_putchar(base[nbr % 16]);
}

void	print_hex_data(void *addr, int size, int row)
{
	int j;

	j = 0;
	while (j < 16)
	{
		if (row * 16 + j < size)
			ft_putnbr_base16(*(char *)(addr + (row * 16) + j), 2);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (j % 2 == 1)
			ft_putchar(' ');
		j++;
	}
}

void	print_char_data(void *addr, int size, int row)
{
	int		j;
	char	c;

	j = 0;
	while (j < 16 && row * 16 + j < size)
	{
		c = *(char *)(addr + (row * 16) + j);
		if (c < 32 || c > 126)
			ft_putchar('.');
		else
			ft_putchar(c);
		j++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	int i;

	i = 0;
	while (i < size / 16 + 1)
	{
		ft_putnbr_base16((long long)(addr + (i * 16)), 8);
		ft_putchar(':');
		ft_putchar(' ');
		print_hex_data(addr, size, i);
		print_char_data(addr, size, i);
		ft_putchar('\n');
		i++;
	}
}
