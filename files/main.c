/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:55:21 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/19 18:11:22 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		press_somethink(int key, void *a)
{
	use_key(a, key, 1);
	return (1);
}

void	init(t_all *all)
{
	if (!(all->prov = (t_prov*)malloc(sizeof(t_prov))))
		error_cheker("malloc in init\n");
	all->prov->resolution = 0;
	all->prov->north = 0;
	all->prov->south = 0;
	all->prov->west = 0;
	all->prov->east = 0;
	all->prov->sprite = 0;
	all->prov->floor = 0;
	all->prov->vverh = 0;
	all->prov->map = 0;
	all->prov->position = 0;
}

void	initkeys(t_all *all)
{
	all->klava.a = 0;
	all->klava.d = 0;
	all->klava.w = 0;
	all->klava.s = 0;
	all->klava.left = 0;
	all->klava.right = 0;
	all->klava.esc = 0;
}

void	two_arg(t_all *all, char **b)
{
	int c;

	c = 0;
	if (provim(b[1], "cub"))
	{
		init(all);
		initkeys(all);
		prov_line(open(b[1], O_RDONLY), all, c);
		parcer(all);
		pusk(all);
	}
	else
		error_cheker("ERROR : Problem with name\n");
}

int		main(int a, char **b)
{
	int			fd;
	t_all		all;

	fd = 0;
	if (a == 2)
	{
		two_arg(&all, b);
	}
	else if (a == 3)
	{
		if (provim(b[1], "cub") && provim1(b[2], "--save"))
			bmpfile(&all, fd, b[1]);
		else
			error_cheker("ERROR : Problem with name\n");
	}
	else
		error_cheker("ERROR : Invalid argument\n");
	return (0);
}
