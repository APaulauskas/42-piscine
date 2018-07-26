/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_combo(char *combo, int n)
{
	int i;
	int display;

	display = 1;
	i = 0;
	while (++i < n)
		if (combo[i - 1] >= combo[i])
			display = 0;
	if (!display)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(combo[i]);
	if (combo[0] < ('9' + 1 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	combo[10];

	i = -1;
	while (++i < n)
		combo[i] = i + 48;
	while (combo[0] <= ('9' + 1 - n) && n >= 1)
	{
		print_combo(combo, n);
		if (n == 10)
			break ;
		combo[n - 1]++;
		i = n;
		while (i > 0 && n > 1)
		{
			i--;
			if (combo[i] > '9')
			{
				combo[i - 1]++;
				combo[i] = '0';
			}
		}
	}
}
