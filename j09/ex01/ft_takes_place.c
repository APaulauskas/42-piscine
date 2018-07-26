/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <paulauskas.adam@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:45 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	convert_hour(int *hour, int *pm)
{
	if (*hour == 0)
	{
		*hour = 12;
		return ;
	}
	if (*hour == 12)
	{
		*pm = 1;
		return ;
	}
	if (*hour > 12)
	{
		*pm = 1;
		*hour -= 12;
		return ;
	}
}

void	ft_takes_place(int hour)
{
	int hour2;
	int pm1;
	int pm2;

	pm1 = 0;
	pm2 = 0;
	if (hour > 23)
		hour -= 24;
	hour2 = hour + 1;
	if (hour2 > 23)
		hour2 -= 24;
	convert_hour(&hour, &pm1);
	convert_hour(&hour2, &pm2);
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %s AND %d.00 %s\n",
		hour, pm1 ? "P.M." : "A.M.",
		hour2, pm2 ? "P.M." : "A.M.");
}
