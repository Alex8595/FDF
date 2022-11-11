/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:43:01 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/11 11:07:40 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_mlx_pixel_put(t_dt *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < data->width && y < data->height)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_close(int keycode, t_dt *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_cross(void)
{
	exit(0);
}

void	dot(t_dt *sc, int j, int i, int color)
{
	my_mlx_pixel_put(sc, j, i, color);
}
