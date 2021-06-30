/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:31:37 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 18:18:26 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			choose_sign(t_all *all)
{
	if (all->dda->sign == 1 || all->dda->sign == 2)
	{
		all->dda->wallx = all->position->camera_y + all->dda->walldist *
			all->dda->raydir_y;
		all->dda->wallx -= floor(all->dda->wallx);
		all->dda->tex_x = (int)(all->dda->wallx *
				(double)all->pain[all->dda->sign]->x);
		if (all->dda->raydir_x > 0)
			all->dda->tex_x = all->pain[all->dda->sign]->x -
				all->dda->tex_x - 1;
	}
	else if (all->dda->sign == 3 || all->dda->sign == 4)
	{
		all->dda->wallx = all->position->camera_x + all->dda->walldist *
			all->dda->raydir_x;
		all->dda->wallx -= floor(all->dda->wallx);
		all->dda->tex_x = (int)(all->dda->wallx *
				(double)all->pain[all->dda->sign]->
			x);
		if (all->dda->raydir_y < 0)
			all->dda->tex_x = all->pain[all->dda->sign]->x - all->dda->tex_x
				- 1;
	}
}

int				wall(t_all *all, int y)
{
	int i;

	i = 0;
	choose_sign(all);
	all->dda->step = 1.0 * all->pain[all->dda->sign]->y / all->dda->lineheight;
	all->dda->textpos = (all->dda->drawstart - all->info->y / 2
			+ all->dda->lineheight
		/ 2) * all->dda->step;
	while (y < all->dda->drawend)
	{
		all->dda->tex_y = (int)all->dda->textpos & (all->pain[all->dda->sign]->y
			- 1);
		all->dda->textpos += all->dda->step;
		color_texture(all, y);
		y++;
		i++;
	}
	return (i);
}

void			floors(t_all *all, int i)
{
	int r;
	int g;
	int b;

	r = all->info->floor % 256;
	g = (all->info->floor / 256) % 256;
	b = ((all->info->floor / 256) / 256) % 256;
	while (i < all->info->y)
	{
		all->pain[0]->adress
			[all->dda->screen_x * all->pain[0]->bpp / 8 +
			all->pain[0]->dlina * i] = r;
		all->pain[0]->adress
			[(all->dda->screen_x * all->pain[0]->bpp / 8 +
					all->pain[0]->dlina * i) + 1] = g;
		all->pain[0]->adress
			[(all->dda->screen_x * all->pain[0]->bpp / 8 +
					all->pain[0]->dlina * i) + 2] = b;
		i++;
	}
}

int				vverh(t_all *all, int i)
{
	int r;
	int g;
	int b;

	r = all->info->vverh % 256;
	g = (all->info->vverh / 256) % 256;
	b = ((all->info->vverh / 256) / 256) % 256;
	while (i < all->dda->drawstart)
	{
		all->pain[0]->adress
			[all->dda->screen_x * all->pain[0]->bpp / 8 +
			all->pain[0]->dlina * i] = r;
		all->pain[0]->adress
			[(all->dda->screen_x * all->pain[0]->bpp / 8 +
					all->pain[0]->dlina * i) + 1] = g;
		all->pain[0]->adress
			[(all->dda->screen_x * all->pain[0]->bpp / 8 +
					all->pain[0]->dlina * i) + 2] = b;
		i++;
	}
	return (i);
}

void			printing(t_all *all)
{
	int i;

	i = 0;
	all->dda->lineheight = (int)((all->info->x / all->dda->walldist) * 0.75);
	all->dda->drawstart = -all->dda->lineheight / 2 + all->info->y / 2;
	if (all->dda->drawstart < 0)
		all->dda->drawstart = 0;
	all->dda->drawend = all->dda->lineheight / 2 + all->info->y / 2;
	if (all->dda->drawend > all->info->y)
		all->dda->drawend = all->info->y - 1;
	i += vverh(all, i);
	i += wall(all, i);
	floors(all, i);
}
