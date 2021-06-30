/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:53:33 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/07 22:16:51 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				dlina1(char **arr)
{
	int res;
	int temp;
	int i;
	int j;

	i = 0;
	temp = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			j++;
		if (j > temp)
		{
			temp = j;
			res = i;
		}
		i++;
	}
	return (res);
}

void			tochka1(char **tochka, int y, int x)
{
	if (x >= ft_strlen(tochka[y + 1]) ||
					x >= ft_strlen(tochka[y - 1]))
		error_cheker("THE MAP IS NOT CLOSED!\n");
	if (tochka[y][x - 1] == ' ' || (tochka[y][x + 1] == ' ' ||
				tochka[y][x + 1] == '\0') || tochka[y - 1][x] == ' ' ||
				tochka[y + 1][x] == ' ' || tochka[y - 1][x - 1] == ' '
				|| tochka[y - 1][x + 1] == ' ' || tochka[y + 1][x - 1] == ' '
				|| tochka[y + 1][x + 1] == ' ' || tochka[y + 1][x + 1] == '\0'
				|| tochka[y - 1][x + 1] == '\0')
		error_cheker("THE MAP IS NOT CLOSED!\n");
}

void			check_trans(char **tochka, int shirina, int dlina)
{
	int x;
	int y;

	y = 0;
	while (tochka[y])
	{
		x = 0;
		while (tochka[y][x])
		{
			if (tochka[y][x] != '1' && tochka[y][x] != ' ')
			{
				tochka1(tochka, y, x);
			}
			x++;
		}
		y++;
	}
}

char			**trans_map(char **tochka)
{
	int		i;
	int		dlina;
	int		shirina;
	char	**a;

	shirina = shirina1(tochka);
	dlina = ft_strlen(tochka[dlina1(tochka)]);
	if (!(a = (char**)malloc(sizeof(char*) * dlina + 1)))
		return (NULL);
	i = 0;
	while (i < dlina)
	{
		if (!(a[i] = (char*)malloc(sizeof(char) * shirina)))
		{
			while (a[--i])
				free(a[i]);
			free(a);
		}
		i++;
	}
	a[dlina] = NULL;
	check_trans(tochka, shirina, dlina);
	return (write_map(a, tochka));
}

char			**check_map(char **tochka)
{
	char	**a;
	int		dlina;
	int		i;

	dlina = shirina1(tochka);
	if (!(a = (char**)malloc(sizeof(char*) * (dlina + 1))))
		return (NULL);
	i = 0;
	while (tochka[i])
	{
		a[i] = ft_strtrim(tochka[i], " ");
		i++;
	}
	a[i] = NULL;
	return (a);
}
