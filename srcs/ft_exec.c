/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:29 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/17 12:02:53 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_exec
**
**		Draws "les Fils" in the screen.
**
*/

void	ft_exec(t_dt *sc)
{
	ft_lenght_lines(sc);
	sc->width = 100 + (sc->line_width * (sc->size_x - 1))
		+ ((sc->size_y - 1) * sc->line_width);
	sc->height = ft_calculate_height(sc);
	ft_coordinates(sc);
	sc->mlx = mlx_init();
	if (sc->fullcreen)
	{
		sc->width = 1920;
		sc->height = 1080;
	}
	sc->win = mlx_new_window(sc->mlx, sc->width, sc->height, "FdF");
	sc->img = mlx_new_image(sc->mlx, sc->width, sc->height);
	sc->addr = mlx_get_data_addr(sc->img,
			&sc->bits_per_pixel, &sc->line_length, &sc->endian);
	ft_paint_up(sc);
	ft_paint_down(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}

/*
**			ft_lenght_lines
**
**			Calculates the lenght of the lines
**
*/

void	ft_fullscreen_vertical_helper(t_dt *sc)
{
	sc->fullcreen = 1;
	sc->fullcreen_vertical = 1;
	sc->line_depth = 980 / ((((double)((double) 7 / 20) *(((sc->size_y - 1)
							- (sc->highest_y_i)) + sc->highest_y_j))
				+ sc->lines[sc->highest_y_i][sc->highest_y_j])
			+ abs(sc->lines[sc->lowest_y_i][sc->lowest_y_j]));
	sc->line_width = sc->line_depth * (double) 0.7;
	sc->line_height = (double)sc->line_width / (double) 2;
}

void	ft_lenght_lines(t_dt *sc)
{
	ft_calculate_height(sc);
	if ((((sc->size_x - 1) * 14) + ((sc->size_y - 1) * 14) + 100 <= 1920)
		&& ft_calculate_height(sc) <= 1080)
	{
		sc->line_depth = 20;
		sc->line_height = 7;
		sc->line_width = 14;
	}
	else if ((((sc->size_x - 1) * 14) + ((sc->size_y - 1) * 14) + 100)
		> ft_calculate_height(sc))
	{
		sc->fullcreen = 1;
		sc->line_width = (double) 1820 / (double)((sc->size_x - 1)
				+ (double)(sc->size_y - 1));
		sc->line_height = (double)sc->line_width / (double) 2;
		sc->line_depth = sc->line_width * 20 / 14;
	}
	else
	{
		ft_fullscreen_vertical_helper(sc);
	}
}

/*
**			ft_calculate_height
**
**			Calculates the size of the screen, given the size of poly
**
*/

void	ft_calculate_height_help(t_dt *sc, int *i, int *j)
{
	double	dif;

	while (*j < sc->size_x)
	{
		dif = (*j * sc->line_height) + (sc->lines[*i][*j] * sc->line_depth)
			- (*i * sc->line_height);
		if (dif > sc->highest_y)
		{
			sc->highest_y = dif;
			sc->highest_y_i = *i;
			sc->highest_y_j = *j;
		}
		if (dif < sc->lowest_y)
		{
			sc->lowest_y = dif;
			sc->lowest_y_i = *i;
			sc->lowest_y_j = *j;
		}
		++(*j);
	}
	*j = 0;
	++*i;
}

int	ft_calculate_height(t_dt *sc)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	sc->highest_y = 0;
	sc->lowest_y = 0;
	while (i < sc->size_y)
	{
		ft_calculate_height_help(sc, &i, &j);
	}
	return (sc->highest_y + fabs(sc->lowest_y) + 100);
}
