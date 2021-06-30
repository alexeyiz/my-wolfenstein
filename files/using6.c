/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:32:35 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/08 02:38:04 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*array;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(array = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = -1;
	if (s1)
		while (s1[++j])
			array[i++] = s1[j];
	j = -1;
	while (s2[++j])
		array[i++] = s2[j];
	array[i] = '\0';
	return (array);
}

void			init7(t_all *all)
{
	if (!(all->info = (t_info*)malloc(sizeof(t_info))))
		error_cheker("Problem in malloc in init7\n");
}

void			y(t_all *all, char *line, int i, int b)
{
	int c;

	c = 0;
	all->info->y = ft_atoi(&line[i]);
	c = all->info->y;
	spaces(line, &i);
	while (line[i] >= '0' && line[i] <= '9')
	{
		i++;
		b++;
	}
	if (all->info->save == 0 && (all->info->y > 1440 || b > 9))
		all->info->y = 1440;
	if (all->info->save == 1 && all->info->y > 15000)
		all->info->y = 15000;
	spaces(line, &i);
	if (line[i] != '\0' || all->info->y <= 0 || all->info->x <= 0)
		error_cheker("Problem with revolution\n");
}

void			resolution(char *line, t_all *all)
{
	int i;
	int b;
	int	c;

	i = 0;
	b = 0;
	while (line[i] == ' ')
		i++;
	all->info->x = ft_atoi(&line[i]);
	c = all->info->x;
	while (line[i] >= '0' && line[i] <= '9')
	{
		i++;
		b++;
	}
	if (all->info->save == 0 && (all->info->x > 2560 || b > 9))
		all->info->x = 2560;
	if (all->info->save == 1 && all->info->x > 15000)
		all->info->x = 15000;
	b = 0;
	y(all, line, i, b);
	all->prov->resolution++;
}

void			write_route(char **tochka, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
		*tochka = line;
	else
		error_cheker("Problem with route");
}
