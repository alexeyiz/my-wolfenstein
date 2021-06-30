/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:41:44 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 19:46:17 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_set(char ch, char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (ch == set[j])
			return (1);
		j++;
	}
	return (0);
}

void			check_line(char **tochka)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tochka[i][j])
	{
		if (tochka[i][j] != '1' && tochka[i][j] != ' ')
			error_cheker("First line not closed\n");
		j++;
	}
	while (tochka[i])
		i++;
	j = 0;
	i--;
	while (tochka[i][j])
	{
		if (tochka[i][j] != '1' && tochka[i][j] != ' ')
			error_cheker("Last line not closed\n");
		j++;
	}
}

void			prov_map_y(char *line, t_all *all)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i] >= '0' && line[i] <= '2') &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
			line[i] != 'W' && line[i] != '\t' && !line[i])
			error_cheker("Not right, paren. You shouid ispravit eto\n");
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
			line[i] == 'W')
		{
			all->info->direction = line[i];
			all->prov->position++;
		}
		i++;
	}
}

void			look_map(int fd, char *line, t_all *all)
{
	int		ress;
	char	*tmp;

	ress = 1;
	prov_map_y(line, all);
	all->info->line = ft_strjoin(line, "$");
	while (ress > 0)
	{
		if ((ress = get_next_line(fd, &line)) == (-1))
			error_cheker("Problem with fd\n");
		if (line[0] == '\0')
			error_cheker("NE GUNDI\n");
		prov_map_y(line, all);
		tmp = all->info->line;
		all->info->line = ft_strjoin(all->info->line, line);
		free(tmp);
		tmp = all->info->line;
		all->info->line = ft_strjoin(all->info->line, "$");
		free(tmp);
		free(line);
	}
	all->info->tochka = ft_split(all->info->line, '$');
	free(all->info->line);
}

int				count_words(char *str, char c)
{
	int i;
	int count;
	int word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			word = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}
