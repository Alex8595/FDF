/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:39:32 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/21 17:51:11 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//void	ft_leaks(void)
//{
//	system("leaks fdf");
//}
//atexit(ft_leaks);

int	main(int argc, char **argv)
{
	t_dt		sc;

	ft_init_vars(&sc);
	if (argc == 2)
	{
		if (ft_read(&sc, argv[1]) == 0)
		{
			ft_exec(&sc);
			mlx_hook(sc.win, 2, 1L << 0, ft_close, &sc);
			mlx_hook(sc.win, 17, (1L << 2), ft_cross, &sc);
			mlx_loop(sc.mlx);
		}
		else
			exit(1);
	}
	exit(ft_error(1));
}

void	ft_init_vars(t_dt *sc)
{
	sc->angle = 0;
	sc->highest_y = 0;
	sc->lowest_y = 0;
	sc->highest_y_i = 0;
	sc->highest_y_j = 0;
	sc->lowest_y_i = 0;
	sc->lowest_y_j = 0;
	sc->line_height = 7;
	sc->line_width = 14;
	sc->line_depth = 20;
	sc->fullcreen = 0;
	sc->fullcreen_vertical = 0;
	sc->h = 0;
	sc->k = 0;
	sc->l = 0;
	sc->a = 0;
	sc->b = 0;
	sc->width = 0;
	sc->height = 0;
}
