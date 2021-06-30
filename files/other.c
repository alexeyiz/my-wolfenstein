/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:30 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/08 02:35:12 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			checker(char **tochka)
{
	int i;
	int j;

	i = 1;
	while (tochka[i])
	{
		j = 0;
		while (tochka[i][j])
		{
			if (tochka[i][j] != ' ' && (tochka[i][j] != '0' &&
						tochka[i][j] != '2' && tochka[i][j] != '1') &&
					tochka[i][j] != 'N' && tochka[i][j] != 'E' &&
					tochka[i][j] != 'S' && tochka[i][j] != 'W')
				error_cheker("Spaces\n");
			j++;
		}
		i++;
	}
}

void			init3(t_all *all)
{
	int i;

	i = 0;
	if (!(all->process = (t_process*)malloc(sizeof(t_process))))
		error_cheker("problem with mallc process\n");
	if (!(all->process->mlx = mlx_init()))
		error_cheker("problem\n");
	if (!(all->position = (t_position*)malloc(sizeof(t_position))))
		error_cheker("problem with malloc position\n");
	if (!(all->data = (t_data*)malloc(sizeof(t_data))))
		error_cheker("problem with malloc data\n");
	if (!(all->data->buffer = malloc(sizeof(double) * (all->info->x + 1))))
		error_cheker("malloc budder\n");
	if (!(all->pain = (t_pain**)malloc(sizeof(t_pain*) * 7)))
		error_cheker("malloc pain\n");
	ft_bzero(all->pain, sizeof(t_pain*) * 7);
	while (i <= 5)
	{
		if (!(all->pain[i] = (t_pain*)malloc(sizeof(t_pain))))
			error_cheker("malloc pain\n");
		ft_bzero(all->pain[i], sizeof(t_pain));
		i++;
	}
}

int				ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	len = 0;
	s = (char*)src;
	if (!dst)
		return (0);
	len = ft_strlen(s);
	if (!size)
		return (len);
	while (s[i] && i < size - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

void			checker_distant(t_all *a)
{
	int			i;
	t_sprite	*sprite;

	i = 0;
	while (i < a->data->col)
	{
		a->sprite[i]->dlina = ((a->position->camera_x - a->sprite[i]->x) *
				(a->position->camera_x - a->sprite[i]->x) +
				(a->position->camera_y - a->sprite[i]->y) *
				(a->position->camera_y - a->sprite[i]->y));
		i++;
	}
	i = 0;
	while (i < a->data->col)
	{
		if (a->sprite[i]->dlina < a->sprite[i + 1]->dlina && (i + 1) <
			a->data->col)
		{
			sprite = a->sprite[i];
			a->sprite[i] = a->sprite[i + 1];
			a->sprite[i + 1] = sprite;
			i = -1;
		}
		i++;
	}
}
