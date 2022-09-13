/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:29 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/13 12:22:51 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_exec(t_dt *sc)
{
	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, 800, 600, "kus");

	sc->img = mlx_new_image(sc->mlx, 800, 600);
	sc->addr = mlx_get_data_addr(sc->img, &sc->bits_per_pixel, &sc->line_length, &sc->endian);

	ft_paint(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}

void	ft_paint(t_dt *sc)
{
	int i = 299;
	int j = 50;

	while (j < 750)
	{
		while (i < 550)
		{
//			if (i % 10 == 0 && j % 10 == 0)
				dot(sc, j, i, 0xFFFFFF);
			i++;
		}
		j++;
	}
}

void	dot(t_dt *sc, int j, int i, int color)
{
	my_mlx_pixel_put(sc, j, i, color);
	my_mlx_pixel_put(sc, j + 1, i, color);
	my_mlx_pixel_put(sc, j + 1, i + 1, color);
	my_mlx_pixel_put(sc, j, i + 1, color);
}
