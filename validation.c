/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamooja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:59:33 by osamooja          #+#    #+#             */
/*   Updated: 2019/11/01 11:25:43 by osamooja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		charcount(char *buf)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	(!buf[i] || buf[i] != '\n')
		return (0);
	return (count);
}

int		adjacent(char *buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i -5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int		validation(char *buf, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (charcount(buf + i) != 4)
			return (0);
		if (adjacent(buf + i) != 6 && adjacent(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
