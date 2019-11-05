/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:11:50 by osamooja          #+#    #+#             */
/*   Updated: 2019/11/05 11:40:14 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_piece
{
	int				tetrimino[8];
	char			pieceletter;
	int				x_offset;
	int				y_offset;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_map
{
	char		**array;
}				t_map;

int				in_bounds(t_piece *piece, int map_size, char axis);
int				overlap(t_map *map, t_piece *piece);
int				solve_map(t_map *map, t_piece *piecelist, int map_size);
void			place(t_piece *piece, t_map *map, char letter);
size_t			count_pieces(t_piece *piecelist);
void			print_map(t_map *map, int size);
int				round_up_sq_rt(int num);
t_map			*new_map(int size);
void			solve(t_piece *piecelist);
t_piece			*parser(char *filename);
t_piece			*makepiece(char *buf, char pieceletter);
t_piece			*makelist(char *buf, int size);
t_piece			*align(t_piece *piece);
void			shift_x(t_piece *piece, int n);
void			shift_y(t_piece *piece, int y);
int				validation(char *buf, int size);
int				charcount(char *buf);
int				adjacenct(char *buf);
void			free_piecelist(t_piece *list);
void			free_map(t_map *map, int map_size);

#endif
