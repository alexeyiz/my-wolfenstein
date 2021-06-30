/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:11:42 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 18:09:43 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		up(t_all *all)
{
	if (all->info->tochka[(int)(all->position->camera_x +
		all->position->direction_x * all->position->masshtab)]
		[(int)all->position->camera_y] != '1' && all->info->tochka
		[(int)(all->position->camera_x + all->position->direction_x *
		all->position->masshtab)][(int)all->position->camera_y] != '2')
		all->position->camera_x += all->position->direction_x *
			all->position->masshtab;
	if (all->info->tochka[(int)all->position->camera_x]
		[(int)(all->position->camera_y + all->position->direction_y *
		all->position->masshtab)] != '1' && all->info->tochka
		[(int)all->position->camera_x][(int)(all->position->camera_y +
		all->position->direction_y * all->position->masshtab)] != '2')
		all->position->camera_y += all->position->direction_y *
			all->position->masshtab;
}

void		down(t_all *all)
{
	if (all->info->tochka[(int)(all->position->camera_x -
			all->position->direction_x * all->position->masshtab)]
			[(int)all->position->camera_y] != '1' && all->info->tochka
			[(int)(all->position->camera_x - all->position->direction_x *
			all->position->masshtab)][(int)all->position->camera_y] != '2')
		all->position->camera_x -= all->position->direction_x *
			all->position->masshtab;
	if (all->info->tochka[(int)all->position->camera_x]
			[(int)(all->position->camera_y - all->position->direction_y *
			all->position->masshtab)] != '1' && all->info->tochka
			[(int)all->position->camera_x][(int)(all->position->camera_y -
			all->position->direction_y * all->position->masshtab)] != '2')
		all->position->camera_y -= all->position->direction_y *
			all->position->masshtab;
}

void		povorot(t_all *all, int key, double x, double x1)
{
	if (key == 123)
	{
		pov_left(x, x1, all);
	}
	if (key == 124)
	{
		pov_right(x, x1, all);
	}
}

void		pov_left(double x, double x1, t_all *all)
{
	x = all->position->direction_x;
	all->position->direction_x = all->position->direction_x *
			cos(all->position->angle) - all->position->direction_y *
			sin(all->position->angle);
	all->position->direction_y = x * sin(all->position->angle) +
			all->position->direction_y * cos(all->position->angle);
	x1 = all->position->plane_x;
	all->position->plane_x = all->position->plane_x *
			cos(all->position->angle) - all->position->plane_y *
			sin(all->position->angle);
	all->position->plane_y = x1 * sin(all->position->angle)
			+ all->position->plane_y * cos(all->position->angle);
}

void		pov_right(double x, double x1, t_all *all)
{
	x = all->position->direction_x;
	all->position->direction_x = all->position->direction_x *
			cos(-all->position->angle) - all->position->direction_y *
			sin(-all->position->angle);
	all->position->direction_y = x * sin(-all->position->angle) +
		all->position->direction_y * cos(-all->position->angle);
	x1 = all->position->plane_x;
	all->position->plane_x = all->position->plane_x *
			cos(-all->position->angle) - all->position->plane_y *
			sin(-all->position->angle);
	all->position->plane_y = x1 * sin(-all->position->angle)
			+ all->position->plane_y * cos(-all->position->angle);
}
