/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:06:56 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/08 02:37:22 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		color_texture(t_all *all, int y)
{
	all->pain[0]->adress[all->dda->screen_x * all->pain[0]->bpp / 8 +
	all->pain[0]->dlina * y] = all->pain[all->dda->sign]->adress
	[all->dda->tex_x * (all->pain
			[all->dda->sign]->bpp / 8) + all->dda->tex_y *
			all->pain[all->dda->sign]->dlina];
	all->pain[0]->adress[(all->dda->screen_x * all->pain[0]->bpp / 8 +
		all->pain[0]->dlina * y) + 1] = all->pain[all->dda->sign]->adress
		[(all->dda->tex_x * (all->pain[all->dda->sign]->bpp / 8) +
		all->dda->tex_y * all->pain[all->dda->sign]->dlina) + 1];
	all->pain[0]->adress[(all->dda->screen_x * all->pain[0]->bpp / 8 +
		all->pain[0]->dlina * y) + 2] = all->pain[all->dda->sign]->adress
		[(all->dda->tex_x * (all->pain[all->dda->sign]->bpp / 8) +
		all->dda->tex_y * all->pain[all->dda->sign]->dlina) + 2];
}

void		init5(t_all *all)
{
	if (!(all->dda = (t_dda*)malloc(sizeof(t_dda))))
		error_cheker("malloc in init_5\n");
}

void		parcer(t_all *all)
{
	tochka(all->info->tochka);
	all->info->space = check_map(all->info->tochka);
	checker(all->info->space);
	check_line(all->info->tochka);
	all->info->trans = trans_map(all->info->tochka);
	init3(all);
	texture(all, 1, ft_strtrim(all->info->north, " "));
	texture(all, 2, ft_strtrim(all->info->souse, " "));
	texture(all, 3, ft_strtrim(all->info->west, " "));
	texture(all, 4, ft_strtrim(all->info->east, " "));
	texture(all, 5, ft_strtrim(all->info->sprite, " "));
	init4(all);
	init5(all);
	init6(all);
	all->process->win = mlx_new_window(all->process->mlx, all->info->x,
		all->info->y, "cub3D");
	all->pain[0]->process = mlx_new_image(all->process->mlx,
		all->info->x, all->info->y);
	all->pain[0]->adress = mlx_get_data_addr(all->pain[0]->process,
		&all->pain[0]->bpp, &all->pain[0]->dlina, &all->pain[0]->endian);
}

void		how_many_sprite(t_all *all)
{
	int x;
	int y;

	x = 0;
	all->data->col = 0;
	while (all->info->tochka[x])
	{
		y = 0;
		while (all->info->tochka[x][y])
		{
			if (all->info->tochka[x][y] == '2')
				all->data->col++;
			y++;
		}
		x++;
	}
}

void		move(t_all *all, int key)
{
	if (key == 13)
	{
		up(all);
	}
	if (key == 1)
	{
		down(all);
	}
}
