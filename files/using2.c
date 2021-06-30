/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:53:33 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/07 22:20:31 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			provim1(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] == b[i])
	{
		if (a[i] == '\0' && b[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void		create_bmp(t_all *all, int fd)
{
	unsigned char	color[3];
	int				j;
	int				i;
	int				x;
	int				y;

	y = all->info->y - 1;
	i = 0;
	while (i < y)
	{
		x = all->info->x;
		j = 0;
		while (j < x)
		{
			color[0] = all->pain[0]->adress[j * all->pain[0]->bpp / 8 +
				all->pain[0]->dlina * y];
			color[1] = all->pain[0]->adress[(j * all->pain[0]->bpp / 8 +
				all->pain[0]->dlina * y) + 1];
			color[2] = all->pain[0]->adress[(j * all->pain[0]->bpp / 8 +
				all->pain[0]->dlina * y) + 2];
			write(fd, color, 3);
			j++;
		}
		y--;
	}
}

char		**check_map1(char **a)
{
	int i;
	int j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] != ' ' && !(a[i][j] >= '0' && a[i][j] <= '2')
					&& a[i][j] != 'N' && a[i][j] != 'S' && a[i][j] != 'E' &&
				a[i][j] != 'W' && a[i][j] != '\t')
				a[i][j] = ' ';
			j++;
		}
		a[i][j] = '\0';
		i++;
	}
	return (a);
}

char		**write_map(char **a, char **tochka)
{
	int i;
	int j;

	i = 0;
	while (tochka[i])
	{
		j = 0;
		while (tochka[i][j])
		{
			a[j][i] = tochka[i][j];
			j++;
		}
		i++;
	}
	return (check_map1(a));
}

int			shirina1(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
