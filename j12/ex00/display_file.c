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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "program.h"

#define BUFFER_SIZE 1000

int	main(int ac, char **av)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		read_size;

	if (ac > 2)
		ft_putstr(2, "Too many arguments.\n");
	else if (ac < 2)
		ft_putstr(2, "File name missing.\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		while ((read_size = read(fd, buffer, BUFFER_SIZE)))
		{
			buffer[read_size] = '\0';
			ft_putstr(1, buffer);
		}
		close(fd);
	}
	return (0);
}
