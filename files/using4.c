/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:15:54 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/07 22:51:05 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int				check_color(t_all *all)
{
	return (all->pain[5]->adress[all->pain[5]->dlina * all->data->tex_y +
		all->data->tex_x * all->pain[5]->bpp / 8] == 0 && all->pain[5]->adress
		[(all->pain[5]->dlina * all->data->tex_y + all->data->tex_x *
			all->pain[5]->bpp / 8) + 1] == 0 && all->pain[5]->adress
		[(all->pain[5]->dlina * all->data->tex_y + all->data->tex_x *
			all->pain[5]->bpp / 8) + 2] == 0);
}

void			checker_sprite(t_all *all)
{
	all->data->sprite_x = abs((int)((all->info->x / all->data->a) * 0.75));
	all->data->draw_x = -all->data->sprite_x / 2 + all->data->screen_x;
	all->data->end_x = all->data->sprite_x / 2 + all->data->screen_x;
	if (all->data->draw_y < 0)
		all->data->draw_y = 0;
	if (all->data->end_y >= all->info->y)
		all->data->end_y = all->info->y - 1;
	if (all->data->draw_x < 0)
		all->data->draw_x = 0;
	if (all->data->end_x >= all->info->x)
		all->data->end_x = all->info->x - 1;
}

void			whiler(int b, int i, char *line)
{
	while (line[i] == ' ')
	{
		if (line[i] == ' ')
			b++;
		i++;
	}
}

void			zero_result(int fd, char *line, t_all *all, int b)
{
	int		res;
	char	*tmp;
	int		i;

	res = 1;
	i = 0;
	while (res > 0)
	{
		if ((res = get_next_line(fd, &line)) == (-1))
			error_cheker("Problem with fd\n");
		tmp = line;
		whiler(b, i, line);
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
		{
			all->prov->map++;
			look_map(fd, line, all);
			free(tmp);
			break ;
		}
		transform_objects(&line[i], all, b);
		if (line != NULL && *line == 0)
			free(line);
	}
}

void			prov_line(int fd, t_all *all, int c)
{
	char	*tmp;
	int		res;
	char	*line;
	int		b;

	res = 1;
	b = 0;
	init7(all);
	if (c == 1)
		all->info->save = 1;
	if (c == 0)
		all->info->save = 0;
	zero_result(fd, line, all, b);
	checker_objects(all);
}
