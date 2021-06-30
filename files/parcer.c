/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:19:53 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/08 02:36:59 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			work_sprite(t_all *all, int i)
{
	all->data->spritex = all->sprite[i]->x - all->position->camera_x + 0.5;
	all->data->spritey = all->sprite[i]->y - all->position->camera_y + 0.5;
	all->data->invdet = 1.0 / (all->position->plane_x *
	all->position->direction_y - all->position->direction_x *
	all->position->plane_y);
	all->data->transformx = all->data->invdet *
	(all->position->direction_y * all->data->spritex -
	all->position->direction_x * all->data->spritey);
	all->data->a = all->data->invdet * (-all->position->plane_y *
	all->data->spritex + all->position->plane_x * all->data->spritey);
	all->data->screen_x = (int)((all->info->x / 2) * (1 +
	all->data->transformx / all->data->a));
	all->data->spriteheight = abs((int)((all->info->x / all->data->a) * 0.75));
	all->data->draw_y = -all->data->spriteheight / 2 + all->info->y / 2;
	all->data->end_y = all->data->spriteheight / 2 + all->info->y / 2;
	checker_sprite(all);
	all->data->stripe = all->data->draw_x;
	create_sprite(all);
}

unsigned char	*bitmap_info(int y, int x)
{
	int						i;
	static unsigned char	info[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	int						a;

	a = (4 - (x * 3) % 4) % 4;
	i = 14 + 40 + (3 * x + a) * y;
	info[0] = (unsigned char)('B');
	info[1] = (unsigned char)('M');
	info[2] = (unsigned char)(i);
	info[3] = (unsigned char)(i >> 8);
	info[4] = (unsigned char)(i >> 16);
	info[5] = (unsigned char)(i >> 24);
	info[10] = (unsigned char)(54);
	return (info);
}

void			bmpfile(t_all *all, int fd, char *cub)
{
	unsigned char *a;
	unsigned char *b;

	fd = open(cub, O_RDONLY);
	pech(all, fd);
	close(fd);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	a = bitmap_info(all->info->y - 1, all->info->x);
	b = bitmap_header(all->info->y - 1, all->info->x);
	write(fd, a, 14);
	write(fd, b, 40);
	create_bmp(all, fd);
	close(fd);
	ft_exit();
}

void			check_riht(t_all *all)
{
	if (all->dda->raydir_x < 0)
	{
		all->dda->stepx = -1;
		all->dda->sidedist_x = (all->position->camera_x - all->dda->map_x) *
			all->dda->deltadist_x;
	}
	else
	{
		all->dda->stepx = 1;
		all->dda->sidedist_x = (all->dda->map_x + 1.0 -
			all->position->camera_x) * all->dda->deltadist_x;
	}
	if (all->dda->raydir_y < 0)
	{
		all->dda->stepy = -1;
		all->dda->sidedist_y = (all->position->camera_y - all->dda->map_y) *
			all->dda->deltadist_y;
	}
	else
	{
		all->dda->stepy = 1;
		all->dda->sidedist_y = (all->dda->map_y + 1.0 -
			all->position->camera_y) * all->dda->deltadist_y;
	}
}

void			where_side(t_all *all)
{
	all->dda->hit = 1;
	if (!all->dda->sign)
	{
		if (all->dda->raydir_x < 0)
			all->dda->sign = 1;
		else if (all->dda->raydir_x > 0)
			all->dda->sign = 2;
	}
	else if (all->dda->sign == 1)
	{
		if (all->dda->raydir_y < 0)
			all->dda->sign = 3;
		else if (all->dda->raydir_y > 0)
			all->dda->sign = 4;
	}
}
