/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:52 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/19 15:30:50 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_read
**
**		This function will save the information given though a file
**
*/

int	ft_read(t_dt *sc, char *file)
{
	int		fd;
	int		i;
	int		size;
	char	**raw;

	i = 0;
	raw = malloc(sizeof(char *) * 3000);
	if (!raw)
		return (ft_error(100));
	if (ft_strlen(file) <= 0)
		return (ft_error(2));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(3));
	while (i < 3000 && get_next_line(fd, &raw[i]))
		++i;
	if (i >= 3000)
		return (ft_error(4));
	
	ft_save_raw(sc, raw, i);

	ft_free_raw(raw, i);
	close(fd);
	sc->size_x = ft_strlen(sc->lines[0]);
	return (0);
}

/*
**
**
**
**
*/

void	ft_save_raw(t_dt *sc, char **raw, int i)
{
	int	y;
	int	j;

	sc->size_y = i + 1;
	sc->lines = malloc(sizeof(char *) * sc->size_y);
	if (!raw)
		return ;
	i = 0;
	y = 0;
	j = 0;
	while (i < sc->size_y)
	{
		sc->lines[i] = malloc(sizeof(char) * (ft_n_dots(raw[i]) + 1));
		sc->lines[i][ft_n_dots(raw[i])] = '\0';
		while (raw[i][y] != '\0')
		{
			if (raw[i][y] != ' ')
			{
				sc->lines[i][j] = raw[i][y];
				++j;
			}
			++y;
		}
		y = 0;
		j = 0;
		i++;
	}
}

/*
**
**
**
**
*/

int	ft_n_dots(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			++n;
		++i;
	}
	return (n);
}

/*
**
**
**
**
**
**
**
**
**
*/

void	ft_free_raw(char **raw, int i)
{
	int	j;

	j = 0;
	while (j < i + 1)
	{
		free(raw[j]);
		++j;
	}
	free(raw);
}
