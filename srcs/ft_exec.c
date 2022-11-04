/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:29 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/04 11:50:45 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_exec
**
**		Draws the Fils in the screen.
**
**
*/

void	ft_exec(t_dt *sc)
{
	ft_lenght_lines(sc);
	sc->width = 100 + (sc->line_width * (sc->size_x - 1)) + ((sc->size_y - 1) * sc->line_width);
	sc->height = ft_calculate_height(sc);
	ft_coordinates(sc);
	sc->mlx = mlx_init();
	if (sc->fullcreen)
	{
		sc->win = mlx_new_window(sc->mlx, 1920, 1080, "FdF");
		sc->img = mlx_new_image(sc->mlx, 1920, 1080);
		sc->width = 1920;
		sc->height = 1080;
	}
	else
	{
		sc->win = mlx_new_window(sc->mlx, sc->width, sc->height, "FdF");
		sc->img = mlx_new_image(sc->mlx, sc->width, sc->height);
	}
	sc->addr = mlx_get_data_addr(sc->img, &sc->bits_per_pixel, &sc->line_length, &sc->endian);
	ft_paint_up(sc);
	ft_paint_down(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}

/*
**			ft_lenght_lines
**
**
**			Calculates the lenght of the lines
**
*/

void	ft_lenght_lines(t_dt *sc)
{
	ft_calculate_height(sc);
	if ((((sc->size_x - 1) * 14) + ((sc->size_y - 1) * 14) + 100 <= 1920)
		&& ft_calculate_height(sc) <= 1080)
	{
		sc->line_height = 7;
		sc->line_width = 14;
		sc->line_depth = 20;
	}
	else if ((((sc->size_x - 1) * 14) + ((sc->size_y - 1) * 14) + 100) > ft_calculate_height(sc))
	{
		sc->fullcreen = 1;
		sc->line_width = (double) 1820 / (double)((sc->size_x - 1) + (double)(sc->size_y - 1));
		sc->line_height = (double)sc->line_width / (double) 2;
		sc->line_depth = sc->line_width * 20 / 14;
	}
	else
	{
		sc->fullcreen = 1;
		sc->fullcreen_vertical = 1;
		sc->line_depth = 980 / ((((double)((double) 7 / 20) *(((sc->size_y - 1) - (sc->highest_y_i)) + sc->highest_y_j)) + sc->lines[sc->highest_y_i][sc->highest_y_j])
				+ abs(sc->lines[sc->lowest_y_i][sc->lowest_y_j]));
		sc->line_width = sc->line_depth * (double) 0.7;
		sc->line_height = (double)sc->line_width / (double) 2;
	}
}

int	ft_calculate_height(t_dt *sc)
{
	int		i;
	int		j;
	double	dif;

	i = 0;
	j = 0;
	sc->highest_y = 0;
	sc->lowest_y = 0;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			dif = (j * sc->line_height) + (sc->lines[i][j] * sc->line_depth) - (i * sc->line_height);
			if (dif > sc->highest_y)
			{
				sc->highest_y = dif;
				sc->highest_y_i = i;
				sc->highest_y_j = j;
			}
			if (dif < sc->lowest_y)
			{
				sc->lowest_y = dif;
				sc->lowest_y_i = i;
				sc->lowest_y_j = j;
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (sc->highest_y + fabs(sc->lowest_y) + 100);
}

/*
**		Down
*/

void	ft_paint_down(t_dt *sc)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < sc->size_y - 1)
	{
		while (l < sc->size_x)
		{
			if (fabs(sc->i[k + 1][l] - sc->i[k][l]) > fabs(sc->j[k + 1][l] - sc->j[k][l]))
				join_dots_down_more_y(sc, k, l);
			else
				join_dots_down_more_x(sc, k, l);
			l++;
		}
		l = 0;
		++k;
	}
}

void	join_dots_down_more_y(t_dt *sc, int k, int l)
{
	double	a;
	double	b;

	a = 0;
	b = 0;
	while (a < fabs(sc->i[k][l] - sc->i[k + 1][l]))
	{
		b += fabs(sc->j[k + 1][l] - (sc->j[k][l])) / (sc->i[k + 1][l] - sc->i[k][l]);
		if (sc->i[k + 1][l] < sc->i[k][l])
			dot(sc, sc->j[k][l] - b, sc->i[k][l] - a,
				((((int)(sc->r[k][l] + (a * ((sc->r[k + 1][l] - sc->r[k][l]) / fabs(sc->i[k][l] - sc->i[k + 1][l])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k + 1][l] - sc->g[k][l]) / fabs(sc->i[k][l] - sc->i[k + 1][l]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k + 1][l] - sc->b[k][l]) / fabs(sc->i[k][l] - sc->i[k + 1][l])))));
		else
			dot(sc, sc->j[k][l] + b, sc->i[k][l] + a,
				((((int)(sc->r[k][l] + (a * ((sc->r[k + 1][l] - sc->r[k][l]) / fabs(sc->i[k][l] - sc->i[k + 1][l])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k + 1][l] - sc->g[k][l]) / fabs(sc->i[k][l] - sc->i[k + 1][l]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k + 1][l] - sc->b[k][l]) / fabs(sc->i[k][l] - sc->i[k + 1][l])))));
		++a;
	}
}

void	join_dots_down_more_x(t_dt *sc, int k, int l)
{
	int		a;
	double	b;

	a = 0;
	b = 0;
	while (a + sc->j[k][l] < sc->j[k + 1][l])
	{
		b += fabs(sc->i[k + 1][l] - sc->i[k][l]) / fabs(sc->j[k + 1][l] - sc->j[k][l]);
		if (sc->i[k + 1][l] < sc->i[k][l])
			dot(sc, sc->j[k][l] + a, sc->i[k][l] - b + 1,
				((((int)(sc->r[k][l] + (a * ((sc->r[k + 1][l] - sc->r[k][l]) / fabs(sc->j[k][l] - sc->j[k + 1][l])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k + 1][l] - sc->g[k][l]) / fabs(sc->j[k][l] - sc->j[k + 1][l]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k + 1][l] - sc->b[k][l]) / fabs(sc->j[k][l] - sc->j[k + 1][l])))));
		else
			dot(sc, sc->j[k][l] + a, sc->i[k][l] + b - 1,
				((((int)(sc->r[k][l] + (a * ((sc->r[k + 1][l] - sc->r[k][l]) / fabs(sc->j[k][l] - sc->j[k + 1][l])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k + 1][l] - sc->g[k][l]) / fabs(sc->j[k][l] - sc->j[k + 1][l]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k + 1][l] - sc->b[k][l]) / fabs(sc->j[k][l] - sc->j[k + 1][l])))));
		++a;
	}
}

/*
**		UP
*/

void	ft_paint_up(t_dt *sc)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < sc->size_y)
	{
		while (l < sc->size_x - 1)
		{
			if (fabs(sc->i[k][l + 1] - sc->i[k][l]) > fabs(sc->j[k][l + 1] - sc->j[k][l]))
				join_dots_up_more_y(sc, k, l);
			else
				join_dots_up_more_x(sc, k, l);
			l++;
		}
		l = 0;
		++k;
	}
}

void	join_dots_up_more_x(t_dt *sc, int k, int l)
{
	int		a;
	double	b;

	a = 0;
	b = 0;
	while (a + sc->j[k][l] < sc->j[k][l + 1])
	{
		b += fabs(sc->i[k][l + 1] - sc->i[k][l]) / fabs(sc->j[k][l + 1] - sc->j[k][l]);
		if (sc->i[k][l + 1] < sc->i[k][l])
		{
			dot(sc, sc->j[k][l] + a, sc->i[k][l] - b,
				((((int)(sc->r[k][l] + (a * ((sc->r[k][l + 1] - sc->r[k][l]) / fabs(sc->j[k][l] - sc->j[k][l + 1])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k][l + 1] - sc->g[k][l]) / fabs(sc->j[k][l] - sc->j[k][l + 1]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k][l + 1] - sc->b[k][l]) / fabs(sc->j[k][l] - sc->j[k][l + 1])))));
		}
		else
			dot(sc, sc->j[k][l] + a, sc->i[k][l] + b,
				((((int)(sc->r[k][l] + (a * ((sc->r[k][l + 1] - sc->r[k][l]) / fabs(sc->j[k][l] - sc->j[k][l + 1])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k][l + 1] - sc->g[k][l]) / fabs(sc->j[k][l] - sc->j[k][l + 1]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k][l + 1] - sc->b[k][l]) / fabs(sc->j[k][l] - sc->j[k][l + 1])))));
		++a;
	}
}

void	join_dots_up_more_y(t_dt *sc, int k, int l)
{
	int		a;
	double	b;

	a = 0;
	b = 0;
	while (a < fabs(sc->i[k][l] - sc->i[k][l + 1]))
	{
		b += fabs((sc->j[k][l + 1]) - sc->j[k][l]) / fabs(sc->i[k][l + 1] - sc->i[k][l]);
		if (sc->i[k][l + 1] < sc->i[k][l])
			dot(sc, sc->j[k][l] + b, sc->i[k][l] - a,
				((((int)(sc->r[k][l] + (a * ((sc->r[k][l + 1] - sc->r[k][l]) / fabs(sc->i[k][l] - sc->i[k][l + 1])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k][l + 1] - sc->g[k][l]) / fabs(sc->i[k][l] - sc->i[k][l + 1]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k][l + 1] - sc->b[k][l]) / fabs(sc->i[k][l] - sc->i[k][l + 1])))));
		else
			dot(sc, sc->j[k][l] + b, sc->i[k][l] + a,
				((((int)(sc->r[k][l] + (a * ((sc->r[k][l + 1] - sc->r[k][l]) / fabs(sc->i[k][l] - sc->i[k][l + 1])))) << 8)
						+ (int)(sc->g[k][l] + (a * ((sc->g[k][l + 1] - sc->g[k][l]) / fabs(sc->i[k][l] - sc->i[k][l + 1]))))) << 8)
				+ (int)(sc->b[k][l] + (a * ((sc->b[k][l + 1] - sc->b[k][l]) / fabs(sc->i[k][l] - sc->i[k][l + 1])))));
		++a;
	}
}

void	dot(t_dt *sc, int j, int i, int color)
{
	my_mlx_pixel_put(sc, j, i, color);
}
