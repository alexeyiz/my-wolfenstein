/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:10:02 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/07 23:13:16 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*error_gnl(char *a)
{
	free(a);
	return (NULL);
}

int				analise(char *a, int len)
{
	int	i;

	i = 0;
	if (a == NULL)
		return (0);
	if (len == 0)
		return (1);
	while (a[i] != '\0')
	{
		if (a[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void			tex(char *line, t_all *all, char *c, int i)
{
	if (c[i] == 'N' && c[i + 1] == 'O')
	{
		write_route(&(all->info->north), line);
		all->prov->north++;
	}
	else if (c[i] == 'S' && c[i + 1] == 'O')
	{
		write_route(&(all->info->souse), line);
		all->prov->south++;
	}
	else if (c[i] == 'W' && c[i + 1] == 'E')
	{
		write_route(&(all->info->west), line);
		all->prov->west++;
	}
	else if (c[i] == 'E' && c[i + 1] == 'A')
	{
		write_route(&(all->info->east), line);
		all->prov->east++;
	}
	else if (c[i] == 'S' && c[i + 1] == '\0')
	{
		write_route(&(all->info->sprite), line);
		all->prov->sprite++;
	}
}

void			rgb_error(int r, int g, int b, char a)
{
	if (!((r >= 0 && r <= 255) && ((g >= 0 && g <= 255)) &&
		((b >= 0 && b <= 255))) || a != '\0')
		error_cheker("che tak mnogo cala\n");
}

void			rgb(char *line, int *rgb, char c, t_all *all)
{
	int r;
	int g;
	int b;
	int i;

	i = 0;
	r = ft_atoi(&line[i]);
	spaces(line, &i);
	while (line[i] != ',')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' &&
			line[i] != '3' & line[i] != '4' && line[i] != '5' && line[i] != '6'
			&& line[i] != '7' && line[i] != '8' && line[i] != '9')
		error_cheker("error\n");
		i++;
	}
	i++;
	g = ft_atoi(&line[i]);
	while (line[i] != ',')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' &&
			line[i] != '3' & line[i] != '4' && line[i] != '5' && line[i] != '6'
			&& line[i] != '7' && line[i] != '8' && line[i] != '9')
		error_cheker("error\n");
		i++;
	}
	i++;
	b = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	rgb_error(r, g, b, line[i]);
	*rgb = r;
	*rgb = (*rgb << 8) + g;
	*rgb = (*rgb << 8) + b;
	if (c == 'F')
		all->prov->floor++;
	else if (c == 'C')
		all->prov->vverh++;
}
