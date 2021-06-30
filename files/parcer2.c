/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:40:59 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/08 02:36:33 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			where_sprite(t_all *all)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (all->info->tochka[x])
	{
		y = 0;
		while (all->info->tochka[x][y])
		{
			if (all->info->tochka[x][y] == '2')
			{
				all->sprite[i]->x = x;
				all->sprite[i]->y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

void			ft_bzero(void *s, size_t n)
{
	char *str;

	str = (char*)s;
	while (n--)
		*str++ = 0;
}

void			init6(t_all *all)
{
	int	i;

	i = 0;
	how_many_sprite(all);
	if (!(all->sprite = malloc(sizeof(t_sprite*) * (all->data->col + 1))))
		error_cheker("Problen with malloc in init6\n");
	ft_bzero(all->sprite, sizeof(t_sprite*) * (all->data->col + 1));
	while (i <= all->data->col)
	{
		if (!(all->sprite[i] = malloc(sizeof(t_sprite))))
			error_cheker("Problen with malloc in init6\n");
		ft_bzero(all->sprite[i++], sizeof(t_sprite));
	}
	where_sprite(all);
}

void			pech(t_all *all, int fd)
{
	int b;

	b = 1;
	init(all);
	prov_line(fd, all, b);
	parcer(all);
	all->pain[0]->process = mlx_new_image(all->process->mlx, all->info->x,
		all->info->y);
	all->pain[0]->adress = mlx_get_data_addr(all->pain[0]->process,
		&all->pain[0]->bpp, &all->pain[0]->dlina, &all->pain[0]->endian);
	start_raycasting(all);
}

unsigned char	*bitmap_header(int y, int x)
{
	static unsigned char	header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(x);
	header[5] = (unsigned char)(x >> 8);
	header[6] = (unsigned char)(x >> 16);
	header[7] = (unsigned char)(x >> 24);
	header[8] = (unsigned char)(y);
	header[9] = (unsigned char)(y >> 8);
	header[10] = (unsigned char)(y >> 16);
	header[11] = (unsigned char)(y >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(3 * 8);
	return (header);
}
