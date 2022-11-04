/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:20 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/04 11:18:46 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_coordinates
**
**		Stores the coordinates of the dots in arrays
**
**
*/

void	ft_coordinates(t_dt *sc)
{
	ft_allocate_ij(sc);
	ft_fill_j(sc);
	ft_fill_i(sc);
	ft_fill_depth(sc);
}

void	ft_allocate_ij(t_dt *sc)
{
	int	i;

	i = 0;
	sc->i = malloc(sizeof(double *) * (sc->size_y));
	sc->j = malloc(sizeof(double *) * (sc->size_y));
	while (i < sc->size_y)
	{
		sc->i[i] = malloc(sizeof(double) * sc->size_x);
		sc->j[i] = malloc(sizeof(double) * sc->size_x);
		++i;
	}
}

void	ft_fill_j(t_dt *sc)
{
	int		i;
	int		j;
	double	margin;

	i = 0;
	j = 1;
	margin = 50;
	if (sc->fullcreen_vertical)
		margin = (1920 / 2) - (sc->size_y * sc->line_width);
	sc->j[0][0] = margin;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->j[i][j] = sc->j[i][j - 1] + sc->line_width;
			++j;
		}
		++i;
		if (i < sc->size_y)
		{
			margin += sc->line_width;
			sc->j[i][0] = margin;
			j = 1;
		}
	}
}

void	ft_fill_i(t_dt *sc)
{
	int		i;
	int		j;
	double	margin;

	i = 0;
	j = 1;
	margin = sc->highest_y + 50;
	sc->i[0][0] = margin;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->i[i][j] = sc->i[i][j - 1] - sc->line_height;
			++j;
		}
		++i;
		if (i < sc->size_y)
		{
			j = 0;
			margin += sc->line_height;
			sc->i[i][j] = margin;
			j = 1;
		}
	}
}

void	ft_fill_depth(t_dt *sc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->i[i][j] = sc->i[i][j] - (sc->lines[i][j] * sc->line_depth);
			++j;
		}
		j = 0;
		++i;
	}
}
