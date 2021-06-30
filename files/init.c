/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:43:49 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 18:29:14 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			rass(t_all *all)
{
	all->dda->hit = 0;
	all->dda->sign = 0;
	while (all->dda->hit == 0)
	{
		if (all->dda->sidedist_x < all->dda->sidedist_y)
		{
			all->dda->sidedist_x += all->dda->deltadist_x;
			all->dda->map_x += all->dda->stepx;
			all->dda->sign = 0;
		}
		else
		{
			all->dda->sidedist_y += all->dda->deltadist_y;
			all->dda->map_y += all->dda->stepy;
			all->dda->sign = 1;
		}
		if (all->info->tochka[all->dda->map_x][all->dda->map_y] == '1')
			where_side(all);
	}
	if (all->dda->sign == 1 || all->dda->sign == 2)
		all->dda->walldist = (all->dda->map_x - all->position->camera_x +
			(1 - all->dda->stepx) / 2) / all->dda->raydir_x;
	else if (all->dda->sign == 3 || all->dda->sign == 4)
		all->dda->walldist = (all->dda->map_y - all->position->camera_y +
			(1 - all->dda->stepy) / 2) / all->dda->raydir_y;
}

void			math(t_all *all)
{
	all->dda->cam_x = 2 * (double)all->dda->screen_x / (double)all->info->x - 1;
	all->dda->raydir_x = all->position->direction_x + all->position->plane_x
		* all->dda->cam_x;
	all->dda->raydir_y = all->position->direction_y + all->position->plane_y
		* all->dda->cam_x;
	all->dda->map_x = (int)all->position->camera_x;
	all->dda->map_y = (int)all->position->camera_y;
	all->dda->deltadist_x = fabs(1 / all->dda->raydir_x);
	all->dda->deltadist_y = fabs(1 / all->dda->raydir_y);
	check_riht(all);
	rass(all);
}

void			colors(t_all *all, int i)
{
	all->pain[0]->adress[all->data->stripe * all->pain[0]->bpp / 8 +
		all->pain[0]->dlina * i] = all->pain[5]->adress[all->pain[5]->dlina
		* all->data->tex_y + all->data->tex_x * all->pain[5]->bpp / 8];
	all->pain[0]->adress[(all->data->stripe * all->pain[0]->bpp / 8 +
		all->pain[0]->dlina * i) + 1] = all->pain[5]->adress
		[(all->pain[5]->dlina * all->data->tex_y + all->data->tex_x *
			all->pain[5]->bpp / 8) + 1];
	all->pain[0]->adress[(all->data->stripe * all->pain[0]->bpp / 8 +
		all->pain[0]->dlina * i) + 2] = all->pain[5]->adress
		[(all->pain[5]->dlina * all->data->tex_y + all->data->tex_x *
			all->pain[5]->bpp / 8) + 2];
}

void			create_sprite(t_all *all)
{
	int i;

	while (all->data->stripe < all->data->end_x)
	{
		all->data->tex_x = (int)(256 * (all->data->stripe -
					(-all->data->sprite_x / 2 + all->data->screen_x))
				* all->pain[5]->x / all->data->sprite_x) / 256;
		if (all->data->a > 0 && all->data->stripe > 0 && all->data->stripe <
			all->info->x && all->data->a < all->data->buffer[all->data->stripe])
		{
			i = all->data->draw_y;
			while (i < all->data->end_y)
			{
				all->data->d = i * 256 - all->info->y * 128 +
					all->data->spriteheight * 128;
				all->data->tex_y = ((all->data->d * all->pain[5]->y) /
					all->data->sprite_x) / 256;
				if (!(check_color(all)))
					colors(all, i);
				i++;
			}
		}
		all->data->stripe++;
	}
}

void			sprites(t_all *all)
{
	int i;

	i = 0;
	checker_distant(all);
	while (i < all->data->col)
	{
		work_sprite(all, i);
		i++;
	}
}
