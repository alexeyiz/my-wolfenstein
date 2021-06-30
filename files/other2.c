/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:28:29 by ichariss          #+#    #+#             */
/*   Updated: 2021/04/07 23:41:05 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*str_join(char *a, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (a != NULL && a[i] != '\0')
		i++;
	while (buf[j] != '\0')
		j++;
	if (!(tmp = malloc(sizeof(char) * (i + j + 1))))
		return (error_gnl(a));
	i = 0;
	j = 0;
	while (a != NULL && a[i] != '\0')
		tmp[i++] = a[j++];
	j = 0;
	while (buf[j] != '\0')
		tmp[i++] = buf[j++];
	tmp[i] = '\0';
	if (a != NULL)
		free(a);
	return (tmp);
}

char			*razrez(char *a)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (a[i] != '\n' && a[i] != '\0')
		i++;
	while (a[i++] != '\0')
		j++;
	if (!(tmp = malloc(sizeof(char) * j + 1)))
		return (error_gnl(a));
	i = 0;
	j = 0;
	while (a[i] != '\n' && a[i] != '\0')
		i++;
	if (a[i] == '\0')
		i--;
	i++;
	while (a[i] != '\0')
		tmp[j++] = a[i++];
	tmp[j] = '\0';
	free(a);
	return (tmp);
}

char			*new_line(char *a)
{
	int		i;
	char	*line;

	i = 0;
	while (a[i] != '\n' && a[i] != '\0')
		i++;
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (error_gnl(a));
	i = 0;
	while (a[i] != '\n' && a[i] != '\0')
	{
		line[i] = a[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int				get_next_line(int fd, char **line)
{
	int			len;
	char		buf[4096];
	static char	*a = NULL;

	if (line == NULL || fd < 0)
		return (-3);
	*line = NULL;
	len = 1;
	while (!(analise(a, len)))
	{
		if ((len = read(fd, buf, 4095)) == -1)
			return (-3);
		buf[len] = '\0';
		if ((a = str_join(a, buf)) == NULL)
			return (-3);
	}
	if ((*line = new_line(a)) == NULL)
		return (-3);
	if (len == 0)
		free(a);
	if (len == 0)
		return (0);
	if ((a = razrez(a)) == NULL)
		return (-3);
	return (1);
}
