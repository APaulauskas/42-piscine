/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:48:35 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/13 13:51:55 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>

enum			e_prof
{
	SAVE_THE_WORLD
};

typedef struct	s_perso
{
	char		*name;
	double		life;
	int			age;
	enum e_prof	profession;
}				t_perso;

#endif
