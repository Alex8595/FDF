/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:39:32 by ahernand          #+#    #+#             */
/*   Updated: 2022/08/16 20:26:52 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_close(int keycode, t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	keycode = 0;
	exit(0);
	return (0);
}

int main()
{
	t_data		data;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 600, "kus");
	
	data.img = mlx_new_image(data.mlx, 800, 600);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);


	int i = 0;
	int j = 0;
	
	while (j < 800)
	{
		while (i < 600)
		{
			my_mlx_pixel_put(&data, j, i, 0x6F8FAF);
			i++;
		}
		i = 0;
		j++;
	}

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

	mlx_hook(data.win, 2, 1L<<0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}