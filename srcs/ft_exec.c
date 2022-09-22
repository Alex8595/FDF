/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:29 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/22 11:39:25 by ahernand         ###   ########.fr       */
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
	sc->width = 950;
	sc->height = 600;

	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, sc->width, sc->height, "kus (soon) plsss :)");

	sc->img = mlx_new_image(sc->mlx, sc->width, sc->height);
	sc->addr = mlx_get_data_addr(sc->img, &sc->bits_per_pixel, &sc->line_length, &sc->endian);

	ft_coordinates(sc);
	ft_paint_up(sc);
	ft_paint_down(sc);
	printf("_y: %d_\n", sc->size_y);
	printf("_x :%d_\n", sc->size_x);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}







/*
**		Down
*/

void	ft_paint_down(t_dt *sc)
{
	int k = 0;
	int l = 0;

	while (k < sc->size_y - 1)
	{
		while (l < sc->size_x)
		{
			join_dots_down_hub(sc, k, l);
			l++;
		}
		l = 0;
		++k;
	}
}

void	join_dots_down_hub(t_dt *sc, int k, int l)
{
	if (abs(sc->i[k + 1][l] - sc->i[k][l]) > abs(sc->j[k + 1][l] - sc->j[k][l]))
		join_dots_down_more_y(sc, k, l);
	else
		join_dots_down_more_x(sc, k, l);

}

void	join_dots_down_more_y(t_dt *sc, int k, int l)
{
	int		a;
	double	b;

	a = 0;
	b = 0;
	while (a + sc->i[k][l] < sc->i[k + 1][l])
	{
		b += fabs((float)sc->j[k + 1][l] - sc->j[k][l]) / fabs((float)sc->i[k + 1][l] - sc->i[k][l]);
		if (sc->i[k + 1][l] < sc->i[k][l])
			dot(sc, sc->j[k][l] + b, sc->i[k][l] - a, 0xFFFFFF);
		else
			dot(sc, sc->j[k][l] + b, sc->i[k][l] + a, 0xFFFFFF);
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
		b += fabs((float)sc->i[k + 1][l] - sc->i[k][l]) / abs(sc->j[k + 1][l] - sc->j[k][l]);
		if (sc->i[k + 1][l] < sc->i[k][l])
			dot(sc, sc->j[k][l] + a, sc->i[k][l] - b, 0xFFFFFF);
		else
			dot(sc, sc->j[k][l] + a, sc->i[k][l] + b, 0xFFFFFF);
		++a;
	}
}





































/*
**		UP
*/

void	ft_paint_up(t_dt *sc)
{
	int k = 0;
	int l = 0;

	while (k < sc->size_y)
	{
		while (l < sc->size_x - 1)
		{
			join_dots_up_hub(sc, k, l);
			l++;
		}
		l = 0;
		++k;
	}
}

void	join_dots_up_hub(t_dt *sc, int k, int l)
{
	if (abs(sc->i[k][l + 1] - sc->i[k][l]) > abs(sc->j[k][l + 1] - sc->j[k][l]))
		join_dots_up_more_y(sc, k, l);
	else
		join_dots_up_more_x(sc, k, l);

}

void	join_dots_up_more_x(t_dt *sc, int k, int l)
{
	int		a;
	double	b;

	a = 0;
	b = 0;

	while (a + sc->j[k][l] < sc->j[k][l + 1])
	{
		b += abs(sc->i[k][l + 1] - sc->i[k][l]) / fabs((float)sc->j[k][l + 1] - sc->j[k][l]);
		if (sc->i[k][l + 1] < sc->i[k][l])
			dot(sc, sc->j[k][l] + a, sc->i[k][l] - b, 0xFFFFFF);
		else
			dot(sc, sc->j[k][l] + a, sc->i[k][l] + b, 0xFFFFFF);
		++a;
	}
}

void	join_dots_up_more_y(t_dt *sc, int k, int l)
{
	int		a;
	double	b;

	a = 0;
	b = 0;
	while (a < abs(sc->i[k][l] - sc->i[k][l + 1]))
	{
		b += fabs((float)sc->j[k][l + 1] - sc->j[k][l]) / abs(sc->i[k][l + 1] - sc->i[k][l]);
		if (sc->i[k][l + 1] < sc->i[k][l])
			dot(sc, sc->j[k][l] + b, sc->i[k][l] - a, 0xFFFFFF);
		else
			dot(sc, sc->j[k][l] + b, sc->i[k][l] + a, 0xFFFFFF);
		++a;
	}
}
































/*
//		OLD PAINT AND JOIN UP
void	ft_paint_up(t_dt *sc)
{
	int i = 250;
	int j = 10;
	double k = 0;
	int l = 0;

	
	int x = 0;
	int y = 0;
	while (i < 250 + (7 * sc->size_y))
	{
		while (j < (sc->size_x * 14) - 4 + l)
		{
			if ((j - 10) % 14 == 0)
			{
				join_dots_up(sc, (double)j, i - k);
				printf("_%f_\n", i - k);
			}
			k += 0.5;
			j++;
		}
		k = 0;
		l += 14;
		j = 10 + l;
		i += 7;
	}
}

void	join_dots_up(t_dt *sc, double j, double i)
{
	int		k;
	double	l;

	k = 0;
	l = 0;
//	dot(sc, j, i, 0xFFFFFF);
	if (fabs((j + 14) - j) > fabs(i - (i - 7)))
	{
		while (k < fabs((j + 14) - j))
		{
			l += fabs(i - (i - 7)) / fabs((j + 14) - j);
			dot(sc, j + k, i - l, 0xFFFFFF);
			++k;
		}
	}
	//else
	//	Do the reverse, change the x/y to y/x 
}

*/





















//	printf("Prior: j: %d ,i: %f\n", j, i);
//	printf("Next:  j: %d ,i: %f\n\n\n\n", j + 14, i - 7);





/*
OLD PAINT DOWN
void	ft_paint_down(t_dt *sc)
{
	int i = 250;
	int j = 10;
	double k = 0;
	int l = 0;

	while (i > 30 + (7 * (32 - sc->size_x)))
	{
		while (j < (sc->size_y * 14) - 4 + l)
		{
			if ((j - 10) % 14 == 0)
				join_dots_down(sc, (double)j, i + k);
			//	dot(sc, j, i + k, 0xFFFFFF);
			k += 0.5;
			j++;
		}
		k = 0;
		l += 14;
		j = 10 + l;
		i -= 7;
	}
}

void	join_dots_down(t_dt *sc, double j, double i)
{
	int		k;
	double	l;

	k = 0;
	l = 0;
	if (fabs((j + 14) - j) > fabs(i - (i + 7)))
	{
		while (k < fabs((j + 14) - j))
		{
			l += fabs(i - (i + 7)) / fabs((j + 14) - j);
			dot(sc, j + k, i + l, 0xFFFFFF);
			++k;
		}
	}
	//else
	//	Do the reverse, change the x/y to y/x 
}

*/




void	dot(t_dt *sc, int j, int i, int color)
{
	my_mlx_pixel_put(sc, j, i, color);
}
