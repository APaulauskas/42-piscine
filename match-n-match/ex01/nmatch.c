/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:37:45 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/14 09:44:50 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nmatch(char *s1, char *s2)
{
	int result;

	result = 0;
	if (*s1 && *s2 == '*')
		result += (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
	else if (!(*s1) && *s2 == '*')
		result += (nmatch(s1, s2 + 1));
	else if (*s1 && *s2 && *s1 == *s2)
		result += (nmatch(s1 + 1, s2 + 1));
	else if (!(*s1) && !(*s2))
		result += 1;
	return (result);
}
