/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:21:05 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 19:30:24 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			choose_floor(char *line, int i, t_all *all)
{
	rgb(&line[i + 1], &(all->info->floor), line[i], all);
	free(line);
}

void			choose_vverh(char *line, int i, t_all *all)
{
	rgb(&line[i + 1], &(all->info->vverh), line[i], all);
	free(line);
}

void			choose_res(char *line, int i, t_all *all)
{
	resolution(&line[i + 1], all);
	free(line);
}

void			transform_objects(char *line, t_all *all, int b)
{
	int i;

	i = 0;
	if (line[i] == '\0' || line[i] == 13)
		return ;
	if (line[i] == 'R' && (line[i + 1] == ' ' && b == 0))
	{
		choose_res(line, i, all);
	}
	else if (((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' &&
		line[i + 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E') ||
		(line[i] == 'E' && line[i + 1] == 'A')) && (line[i + 2] == ' '))
		tex(&line[i + 2], all, &line[i], 0);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		tex(&line[i + 1], all, "S", 0);
	else if (line[i] == 'F' && line[i + 1] == ' ' && b == 0)
	{
		choose_floor(line, i, all);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ' && b == 0)
	{
		choose_vverh(line, i, all);
	}
	else
		error_cheker("Problem with info\n");
}

void			checker_objects(t_all *all)
{
	if (all->prov->resolution != 1)
		error_cheker("too many resolution\n");
	if (all->prov->north != 1)
		error_cheker("too many north\n");
	if (all->prov->south != 1)
		error_cheker("too many south\n");
	if (all->prov->west != 1)
		error_cheker("too many west\n");
	if (all->prov->east != 1)
		error_cheker("too many east\n");
	if (all->prov->sprite != 1)
		error_cheker("too many sprite\n");
	if (all->prov->floor != 1)
		error_cheker("too many floor\n");
	if (all->prov->vverh != 1)
		error_cheker("too many pootolok\n");
	if (all->prov->map != 1)
		error_cheker("too many map\n");
	if (all->prov->position != 1)
		error_cheker("too many player\n");
}
