/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:49:02 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 18:15:01 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_raycasting(t_all *all)
{
	all->dda->screen_x = 0;
	while (all->dda->screen_x < all->info->x)
	{
		math(all);
		printing(all);
		all->data->buffer[all->dda->screen_x] = all->dda->walldist;
		all->dda->screen_x++;
	}
	sprites(all);
}

int		starting(t_all *all)
{
	if (all->klava.esc == 1)
		ft_exit();
	if (all->klava.w == 1)
		move(all, W);
	if (all->klava.s == 1)
		move(all, S);
	if (all->klava.left == 1)
		povorot(all, LEFT, 0, 0);
	if (all->klava.right == 1)
		povorot(all, RIGHT, 0, 0);
	if (all->klava.a == 1)
		move_side(all, A);
	if (all->klava.d == 1)
		move_side(all, D);
	start_raycasting(all);
	mlx_put_image_to_window(all->process->mlx, all->process->win,
		all->pain[0]->process, 0, 0);
	return (0);
}

void	move_right(t_all *all)
{
	if (all->info->tochka[(int)(all->position->camera_x +
		all->position->plane_x * all->position->masshtab)]
		[(int)all->position->camera_y] != '1' && all->info->tochka
		[(int)(all->position->camera_x + all->position->plane_x *
		all->position->masshtab)][(int)all->position->camera_y] != '2')
		all->position->camera_x += all->position->plane_x *
			all->position->masshtab;
	if (all->info->tochka[(int)all->position->camera_x]
		[(int)(all->position->camera_y +
			all->position->plane_y * all->position->masshtab)] != '1' &&
			all->info->tochka[(int)all->position->plane_x]
			[(int)(all->position->plane_y + all->position->plane_y *
			all->position->masshtab)] != '2')
		all->position->camera_y += all->position->plane_y *
			all->position->masshtab;
}

void	move_left(t_all *all)
{
	if (all->info->tochka[(int)(all->position->camera_x -
		all->position->plane_x * all->position->masshtab)]
			[(int)all->position->camera_y] != '1' &&
			all->info->tochka[(int)(all->position->camera_x -
				all->position->plane_x * all->position->masshtab)]
				[(int)all->position->camera_y] != '2')
		all->position->camera_x -= all->position->plane_x *
			all->position->masshtab;
	if (all->info->tochka[(int)all->position->camera_x]
		[(int)(all->position->camera_y - all->position->plane_y *
		all->position->masshtab)] != '1' && all->info->tochka[(int)
			all->position->plane_x][(int)(all->position->plane_y
			- all->position->plane_y * all->position->masshtab)] != '2')
		all->position->camera_y -= all->position->plane_y
			* all->position->masshtab;
}

void	move_side(t_all *all, int key)
{
	if (key == 2)
	{
		move_right(all);
	}
	if (key == 0)
	{
		move_left(all);
	}
}
