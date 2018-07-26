/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:48:06 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/21 20:48:33 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "character.h"
#include "bsq.h"

void	handle_result(int result, int print_nl)
{
	if (!result)
	{
		ft_putstr(2, "map error\n");
		if (print_nl)
			ft_putchar(2, '\n');
	}
	else if (print_nl)
		ft_putchar(1, '\n');
}

int		main(int argc, char **argv)
{
	int i;
	int fd;

	if (argc == 1)
		handle_result(bsq(0), 0);
	else
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 0)
				handle_result(bsq(fd), (i != argc - 1));
			else
				handle_result(0, (i != argc - 1));
			close(fd);
		}
	}
	return (0);
}
