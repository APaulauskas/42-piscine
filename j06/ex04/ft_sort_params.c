/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:09:25 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 20:09:37 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(int argc, char **argv, int *pos)
{
	int i;
	int j;

	i = 0;
	while (i < argc - 2)
	{
		j = 0;
		while (j < argc - 2)
		{
			if (ft_strcmp(argv[pos[j]], argv[pos[j + 1]]) > 0)
				ft_swap(&pos[j], &pos[j + 1]);
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int pos[argc - 1];
	int temp;

	i = 0;
	while (i++ < argc)
		pos[i - 1] = i;
	sort(argc, argv, pos);
	i = 0;
	while (i < argc - 1)
	{
		ft_putstr(argv[pos[i]]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
