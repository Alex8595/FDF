/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:43:01 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/12 13:05:48 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_mlx_pixel_put(t_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(int keycode, t_dt *vars)
{
	ft_clean_dt(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	keycode = 0;
	
	exit(0);
	return (0);
}

void	ft_clean_dt(t_dt *vars)
{
	int	i;

	i = 0;
	while (i < vars->size_y)
	{
		free(vars->lines[i]);
		++i;
	}	
	free(vars->lines);
}
