/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:29 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/14 15:47:55 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_exec(t_dt *sc)
{
	sc->width = 950;
	sc->height = 600;

	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, sc->width, sc->height, "kus :)");

	sc->img = mlx_new_image(sc->mlx, sc->width, sc->height);
	sc->addr = mlx_get_data_addr(sc->img, &sc->bits_per_pixel, &sc->line_length, &sc->endian);

	ft_paint_x(sc);
	ft_paint_y(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}

void	ft_paint_x(t_dt *sc)
{
	int i = 250;
	int j = 10;
	double k = 0;
	int l = 0;

	while (i < 264)
	{
		while (j < 445 + l)
		{
			dot(sc, j, i - k, 0xFFFFFF);
			k += 0.5;
			j++;
		}
		k = 0;
		l += 14;
		j = 10 + l;
		i += 7;
	}
}

void	ft_paint_y(t_dt *sc)
{
	int i = 250;
	int j = 10;
	double k = 0;
	int l = 0;

	while (i > 30)
	{
		while (j < 500 + l)
		{
			dot(sc, j, i + k, 0xFFFFFF);
			k += 0.5;
			j++;
		}
		k = 0;
		l += 14;
		j = 10 + l;
		i -= 7;
	}
}

void	dot(t_dt *sc, int j, int i, int color)
{
	my_mlx_pixel_put(sc, j, i, color);
}
