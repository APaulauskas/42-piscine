/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:28:01 by apaulaus          #+#    #+#             */
/*   Updated: 2018/07/15 16:28:33 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

int	count_line_numbers(char line[9]);
int	get_best_line(char grid[9][9]);
int	increment_pos(char grid[9][9], int *x, int *y, int find_best);

#endif
