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
**		Shift along x-axis.
*/

void	shift_x(t_piece *piece)
{
	piece->tetrimino[0] += -1;
	piece->tetrimino[2] += -1;
	piece->tetrimino[4] += -1;
	piece->tetrimino[6] += -1;
}

/*
**		Shift along y-axis.
*/

void	shift_y(t_piece *piece)
{
	piece->tetrimino[1] += -1;
	piece->tetrimino[3] += -1;
	piece->tetrimino[5] += -1;
	piece->tetrimino[7] += -1;
}
