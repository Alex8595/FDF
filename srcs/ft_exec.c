/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:29 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/12 14:18:47 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_exec(t_dt *sc)
{
	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, 800, 600, "kus");

	sc->img = mlx_new_image(sc->mlx, 800, 600);
	sc->addr = mlx_get_data_addr(sc->img, &sc->bits_per_pixel, &sc->line_length, &sc->endian);

	int i = 0;
	int j = 0;

	while (j < 800)
	{
		while (i < 600)
		{
			my_mlx_pixel_put(sc, j, i, 0x6F8FAF);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}
