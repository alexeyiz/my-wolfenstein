/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub11.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:14:11 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 19:48:07 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			texture(t_all *all, int i, char *a)
{
	if (!(all->pain[i]->process = mlx_xpm_file_to_image(all->process->mlx,
		a, &all->pain[i]->x, &all->pain[i]->y)))
		error_cheker("Invalid texture\n");
	all->pain[i]->adress = mlx_get_data_addr(all->pain[i]->process,
		&all->pain[i]->bpp, &all->pain[i]->dlina, &all->pain[i]->endian);
	free(a);
}

void			sign(t_all *all, char c)
{
	if (c == 'N')
	{
		all->position->plane_y = 0.66;
		all->position->direction_x = -1;
	}
	else if (c == 'S')
	{
		all->position->plane_y = -0.66;
		all->position->direction_x = 1;
	}
	else if (c == 'W')
	{
		all->position->plane_x = -0.66;
		all->position->direction_y = -1;
	}
	else if (c == 'E')
	{
		all->position->plane_x = 0.66;
		all->position->direction_y = 1;
	}
}

int				side(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void			init4(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (all->info->tochka[++i])
	{
		j = -1;
		while (all->info->tochka[i][++j])
			if (side(all->info->tochka[i][j]))
			{
				all->position->camera_x = (double)i + 0.45;
				all->position->camera_y = (double)j + 0.45;
				break ;
			}
	}
	all->position->direction_x = 0.0;
	all->position->direction_y = 0.0;
	all->position->plane_x = 0.0;
	all->position->plane_y = 0.0;
	all->position->masshtab = 0.1;
	all->position->angle = 0.1;
	sign(all, all->info->direction);
}

void			tochka_cheker(int i, int j, char **tochka)
{
	int k;

	k = j;
	while (tochka[i][k] != '1' && tochka[i][k])
		k--;
	if (tochka[i][k] != '1')
		error_cheker("not in map\n");
	k = j;
	while (tochka[i][k] != '1' && tochka[i][k])
		k++;
	if (tochka[i][k] != '1')
		error_cheker("not in map\n");
	k = i;
	while (tochka[k] && tochka[k][j] != '1')
		k++;
	if (!tochka[k] || tochka[k][j] != '1')
		error_cheker("not in map\n");
	k = i;
	while (k >= 1 && tochka[k][j] != '1')
		k--;
	if (!tochka[k] || tochka[k][j] != '1')
		error_cheker("not in map\n");
}
