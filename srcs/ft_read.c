/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:52 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/14 12:41:00 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_read
**
**		This function will save the information given though a file
**
*/

int	ft_empty(char *file)
{
	int		fd;
	char	tmp;
	char	prev_c;

	fd = open(file, O_RDONLY);
	if (read(fd, &tmp, 1) == 0)
		return (1);
	prev_c = tmp;
	while (read(fd, &tmp, 1) > 0)
	{
		if (prev_c == '\n' && tmp == '\n')
			return (1);
		prev_c = tmp;
	}
	return (0);
}

int	ft_right_end(char *file)
{
	int	last_c;

	last_c = ft_strlen(file);
	if (file[last_c - 1] == 'f' && file[last_c - 2] == 'd'
		&& file[last_c - 3] == 'f' && file[last_c - 4] == '.')
		return (0);
	return (1);
}

int	ft_read(t_dt *sc, char *file)
{
	int		fd;
	int		i;
	char	**raw;

	i = 0;
	raw = malloc(sizeof(char *) * 3000);
	if (!raw || ft_empty(file))
		exit(ft_error(100));
	if (ft_right_end(file))
		exit(ft_error(6));
	if (ft_strlen(file) <= 0)
		exit(ft_error(2));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(ft_error(3));
	while (i < 3000 && get_next_line(fd, &raw[i], i))
		++i;
	if (i >= 3000)
		return (ft_error(4));
	ft_save_raw(sc, raw, i);
	ft_free_raw(sc, raw);
	close(fd);
	return (0);
}

void	ft_free_raw(t_dt *sc, char **raw)
{
	int	j;

	j = 0;
	while (j < sc->size_y)
	{
		free(raw[j]);
		++j;
	}
	free(raw);
}
