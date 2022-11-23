/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:11:03 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/21 17:23:49 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_save_raw
**
**		gets ready for saving info and allocates memory for depth info.
**		Leads to ft_fill_lines.c
**
*/

void	ft_save_raw(t_dt *sc, char **raw, int i)
{
	sc->size_y = i + 1;
	ft_fix_empty_line(sc, raw);
	sc->size_x = ft_n_dots(raw[ft_longest_str(sc, raw)]);
	sc->lines = malloc(sizeof(int *) * sc->size_y);
	ft_color_alloc(sc, raw);
	if (!raw)
		return ;
	i = 0;
	while (i < sc->size_y)
	{
		sc->lines[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		ft_fill_lines(sc, raw, i);
		i++;
	}
}

void	ft_fix_empty_line(t_dt *sc, char **raw)
{
	if (sc->size_y - 1 > 0 && raw[sc->size_y - 1][0] == '\0')
	{
		if (sc->size_y - 2 > 0 && raw[sc->size_y - 2][0] == '\0')
			exit(ft_error(5));
		free(raw[sc->size_y - 1]);
		sc->size_y--;
	}
}

int	ft_longest_str(t_dt *sc, char **raw)
{
	int	longest;
	int	i;

	i = 0;
	longest = 0;
	while (i < sc->size_y)
	{
		if (ft_strlen(raw[i]) > ft_strlen(raw[longest]))
			longest = i;
		if (ft_n_dots(raw[i]) != ft_n_dots(raw[0]))
			exit(ft_error(7));
		++i;
	}
	return (longest);
}

int	ft_n_dots(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) && ((i != 0 && str[i - 1] != ','
					&& str[i - 1] != 'x') || (i == 0)))
		{
			n++;
			while (str[i] != '\0' && (ft_ishexa(str[i])
					|| str[i] == 'x' || str[i] == ','))
				++i;
		}
		else if (str[i] != '\0')
			++i;
	}
	return (n);
}
