/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int numbers[2];

	numbers[0] = 0;
	while (numbers[0] <= 98)
	{
		numbers[1] = numbers[0] + 1;
		while (numbers[1] <= 99)
		{
			ft_putchar(numbers[0] / 10 + 48);
			ft_putchar(numbers[0] % 10 + 48);
			ft_putchar(' ');
			ft_putchar(numbers[1] / 10 + 48);
			ft_putchar(numbers[1] % 10 + 48);
			if (!(numbers[0] == 98 && numbers[1] == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			numbers[1]++;
		}
		numbers[0]++;
	}
}
