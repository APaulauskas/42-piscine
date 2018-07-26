/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:09:25 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 20:09:37 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "program.h"

#define BUFFER_SIZE 1000

void	print_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_size;

	while ((read_size = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_size] = '\0';
		ft_putstr(1, buffer);
	}
}

void	display_input(void)
{
	char in;

	while (read(STDIN_FILENO, &in, 1) > 0)
		write(1, &in, 1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	if (ac == 1)
		display_input();
	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0)
		{
			ft_putstr(2, "cat: ");
			ft_putstr(2, av[i]);
			if (errno == 21)
				ft_putstr(2, ": Is a directory\n");
			else
				ft_putstr(2, ": No such file or directory\n");
		}
		else
			print_file(fd);
		close(fd);
	}
	return (0);
}
