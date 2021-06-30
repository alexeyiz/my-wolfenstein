/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:25:07 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/07 23:42:16 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct s_place
{
	int shir;
	int vis;
	char znak;
}t_place;

typedef struct s_list
{
	char type;
	float x;
	float y;
	float rad;
	char color;
}t_list;

int ft_strlen(char *a)
{
	int i = 0;
	while(a[i])
	i++;
	return(i);
}

free_pro(FILE *file, char *draw)
{
	fclose(file);
	if(draw)
		free(draw);
	return(1);
}

int error_cheker(char *a)
{
	write(1, a, ft_strlen(a));
	return(1);	
}

int prov_place(t_place *place)
{
	return((place->vis >= 0 && place->vis <= 300) && (place->shir >= 0 && place->shir <= 300));
}


char *create_place(FILE *file, t_place *place)
{
	int i = 0;
	char *a;
	int b;
	if((b = fscanf(file, "%d%d%c", &place->shir, &place->vis, &place->znak) != 3))
		return(NULL);
	if(b == (-1))
		return(NULL);
	if(!(prov_place(place)))
		return(NULL);
	if(!(a = (char*)malloc(sizeof(char) * place->shir * place->vis)))
		return(NULL);
	while (i < place->shir * place->vis)
	{
		a[i] = place->znak;
		i++;
	}
	return(a);
} 

int check_a(t_list *a)
{
	return((a->rad> 0.00000000) && (a->type == "С" || a->type == "с"));
}
 
int prov_i(float x, float y, t_list *a)
{
	float i;
	i = sqrt((x - a->x)*(x - a->x) + (y - a->y) * (y - a->y));
	if (i <= a->rad)
	{
		if(a->rad - i < 1.0000000)
			return(2);
		return(1);
	}
	return(0);
}

void new_img(t_place *place, char **draw, t_list *a)
{
	int i, x, y;
	y = 0;
	while (y < place->vis)
	{
		x = 0;
		while(x < place->shir)
		{
			i = prov_i(x, y, a);
			if((a->type == "c" && i == 2) || (a->type == "C" && i))
				(*draw)[(y * place->shir) + x] = a->color;
			x++;
		}
		y++; 
	} 
}

int create_draw(FILE *file, t_place *place, char **draw)
{
	int i;
	t_list a;
	while((i = fscanf(file, "%c%f%f%f%c", &a.type, &a.x, &a.y, &a.rad, &a.color)) == 5)
	{
		if(!(check_a(&a)))
			return(0);
		new_img(place, draw, &a);
	}
	if(i != (-1))
		return(0);
	return(1);
}

void start_print(char *draw, t_place *place)
{
	int i = 0;
	while (i < place->vis)
	{
		write(1, draw + (i * place->shir), place->shir);
		write(1, '\n',1);
		i++;
	}
}

int main (int a, char **b)
{
	FILE *file;
	char *draw;
	t_place place;
	if (a != 2)
		return(error_cheker("Error: argument\n"));
	if(!(file = fopen(b[1], "r")))
		return(error_cheker("Error: Operation file corrupted\n"));
	if (!(draw = create_place(file, &place)))
		return(error_cheker("Error: Operation file corrupted\n") && free_pro(file, NULL));
	if (!(create_draw(file, &place, &draw)))
		return(error_cheker("Error: Operation file corrupted\n") && free_pro(file, draw));
	start_print(draw, &place);
	free_pro(file, draw);
	return (0);
}
