/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:44:52 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 18:55:24 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			tochka(char **tochka)
{
	int i;
	int j;

	i = 0;
	while (tochka[i])
	{
		j = 0;
		while (tochka[i][j])
		{
			if (tochka[i][j] == 'N' || tochka[i][j] == 'S' ||
				tochka[i][j] == 'E' || tochka[i][j] == 'W')
				tochka_cheker(i, j, tochka);
			j++;
		}
		i++;
	}
}

void			cheker2(char **tochka, t_all *all)
{
	check_line(tochka);
}

int				keys(int key, t_all *all)
{
	if (all->klava.esc == 1)
		ft_exit();
	else if (all->klava.w == 1)
		move(all, W);
	else if (all->klava.s == 1)
		move(all, S);
	else if (all->klava.left == 1)
		povorot(all, LEFT, 0, 0);
	else if (all->klava.right == 1)
		povorot(all, RIGHT, 0, 0);
	else if (all->klava.a == 1)
		move_side(all, A);
	else if (all->klava.d == 1)
		move_side(all, D);
	return (0);
}

void			pusk(t_all *all)
{
	mlx_hook(all->process->win, 17, 1L << 0, ft_exit, (void*)0);
	mlx_hook(all->process->win, 3, 0, do_somethink, all);
	mlx_hook(all->process->win, 2, 0, press_somethink, all);
	mlx_loop_hook(all->process->mlx, starting, all);
	mlx_loop(all->process->mlx);
}

int				use_key(t_all *all, int key, int i)
{
	if (key == ESC)
		all->klava.esc = i;
	else if (key == W)
		all->klava.w = i;
	else if (key == A)
		all->klava.a = i;
	else if (key == S)
		all->klava.s = i;
	else if (key == D)
		all->klava.d = i;
	else if (key == LEFT)
		all->klava.left = i;
	else if (key == RIGHT)
		all->klava.right = i;
	return (1);
}
