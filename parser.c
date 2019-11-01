/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:12:30 by osamooja          #+#    #+#             */
/*   Updated: 2019/11/01 13:12:34 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Frees the piece list one piece at a time
*/

void		free_piecelist(t_piece *list)
{
	t_piece *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

/*
**	Aligns piece to upper-left corner of its field using shifters
*/

t_piece		*align(t_piece *piece)
{
	while (piece->blockcoords[0] != 0 && \
			piece->blockcoords[2] != 0 && \
			piece->blockcoords[4] != 0 && \
			piece->blockcoords[6] != 0)
		shift_x(piece, -1);
	while (piece->blockcoords[1] != 0 && \
			piece->blockcoords[3] != 0 && \
			piece->blockcoords[5] != 0 && \
			piece->blockcoords[7] != 0)
		shift_y(piece, -1);
	return (piece);
}

/*
** Mallocs a new piece struct
** Finds & stores coordinates of '#' characters
** Initializes offsets to zero
** Returns aligned piece struct
*/

t_piece		*makepiece(char *buf, char pieceletter)
{
	t_piece	*piece_ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(piece_ptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			piece_ptr->blockcoords[x] = (i >= 5) ? (i % 5) : i;
			piece_ptr->blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece_ptr->x_offset = 0;
	piece_ptr->y_offset = 0;
	piece_ptr->pieceletter = pieceletter;
	return (align(piece_ptr));
}

/*
** Passes the buffer to makepiece() one piece-chunk at a time (21 chars)
** Assigns letter to the made piece
** Returns a linked list of piece structs
*/

t_piece		*makelist(char *buf, int size)
{
	t_piece *current;
	t_piece *beginning;
	int		i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < size)
	{
		if (pieceletter == 'A')
		{
			beginning = makepiece(buf + i, pieceletter);
			current = beginning;
		}
		else
		{
			current->next = makepiece(buf + i, pieceletter);
			current = current->next;
		}
		pieceletter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

/*
** Control function for all file parsing functions
** Opens & reads file into a buffer of size 545 (max file size + 1)
** Rejects a file if too small or too large
** Calls valid() to check validity of file
** returns list of piece structs
*/

t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	close(fd);
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	buf[bytecount] = '\0';
	if (!valid(buf, bytecount))
		return (NULL);
	return (makelist(buf, bytecount));
}
