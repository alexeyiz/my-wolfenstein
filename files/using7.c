/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:37:17 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 19:40:55 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*put_word(char *str, char c)
{
	int		i;
	char	*arr;

	i = 0;
	arr = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(arr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(arr, str, i + 1);
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**array;

	i = -1;
	if (!s)
		return (NULL);
	words = count_words((char*)s, c);
	if (!(array = malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		if (!(array[i] = put_word((char*)s, c)))
		{
			while (i > 0)
				free(array[i--]);
			free(array);
			return (NULL);
		}
		s += ft_strlen(array[i]);
	}
	array[i] = 0;
	return (array);
}

int				check_line_break(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char			*push_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*cut_next_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(line) - i + 1))))
		return (0);
	i++;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(line);
	return (str);
}
