/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:46:52 by osamooja          #+#    #+#             */
/*   Updated: 2019/11/01 12:51:14 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Shifts a piece 'n' places along the x-axis
*/

void	shift_x(t_piece *piece, int n)
{
	piece->tetrimino[0] += n;
	piece->tetrimino[2] += n;
	piece->tetrimino[4] += n;
	piece->tetrimino[6] += n;
}

/*
**		Shifts a piece 'n' places along the y-axis
*/

void	shift_y(t_piece *piece, int n)
{
	piece->tetrimino[1] += n;
	piece->tetrimino[3] += n;
	piece->tetrimino[5] += n;
	piece->tetrimino[7] += n;
}
