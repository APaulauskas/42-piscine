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

void	print_file(int fd, int offset)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_size;

	if (offset < 0)
		lseek(fd, offset + 1, SEEK_END);
	else
		lseek(fd, offset, SEEK_SET);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_size] = '\0';
		ft_putstr(1, buffer);
	}
}

void	print_header(char *file_name, int *first)
{
	if (!*first)
		ft_putchar(1, '\n');
	else
		*first = 0;
	ft_putstr(1, "==> ");
	ft_putstr(1, file_name);
	ft_putstr(1, " <==\n");
}

int		print_error(char *arg, char *message, int order)
{
	if (errno == 21)
		return (1);
	ft_putstr(2, "tail: ");
	if (!order)
		ft_putstr(2, arg);
	ft_putstr(2, message);
	if (order)
	{
		ft_putstr(2, arg);
		ft_putchar(2, '\n');
	}
	return (0);
}

void	handle_files(int ac, char **av, int offset)
{
	int i;
	int fd;
	int first_header;

	i = 2;
	first_header = 1;
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0)
		{
			if (print_error(av[i], ": No such file or directory\n", 0))
				print_header(av[i], &first_header);
		}
		else
		{
			if (ac > 4)
				print_header(av[i], &first_header);
			print_file(fd, offset);
		}
		close(fd);
	}
}

int		main(int ac, char **av)
{
	char		a;
	t_result	offset;

	if (ac <= 3)
		while (read(STDIN_FILENO, &a, 1) > 0)
			;
	if (ft_strncmp(av[1], "-c", -1) != 0)
	{
		print_error(av[1], "expected '-c'; got: ", 1);
		return (0);
	}
	offset = ft_atoi(av[2]);
	if (offset.status != 1)
	{
		print_error(av[2], "illegal offset -- ", 1);
		return (0);
	}
	handle_files(ac, av, offset.value);
	return (0);
}
