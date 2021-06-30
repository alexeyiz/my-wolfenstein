/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:06:29 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/23 19:14:32 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len;
	int				count;
	char			*start;
	char			*end;
	char			*array;

	if (!s1 || !set)
		return (NULL);
	count = 0;
	while (s1[count] && check_set((char)s1[count], (char*)set))
		count++;
	start = (char*)&s1[count];
	count = ft_strlen(s1) - 1;
	if (count != -1)
		while (count >= 0 && check_set((char)s1[count], (char*)set))
			count--;
	end = (char*)&s1[count];
	len = (!*s1 || end == start) ? 2 : end - start + 2;
	if (!(array = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(array, start, len);
	return (array);
}

void			ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(fd, &str[i++], 1);
}

void			error_cheker(char *a)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(a, 1);
	exit(EXIT_FAILURE);
}

int				ft_exit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int				provim(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	if ((i > 4 && a[i - 1] == b[2] && a[i - 2] == b[1])
		&& (a[i - 3] == b[0] && a[i - 4] == '.'))
		return (1);
	return (0);
}
