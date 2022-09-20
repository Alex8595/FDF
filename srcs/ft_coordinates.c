/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:20 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/20 12:29:02 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_coordinates(t_dt *sc)
{
	printf("_ X: %d , Y %d\n", sc->size_x, sc->size_y);
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < sc->size_y)
	{
		while (x < sc->size_x)
		{
			printf("%c ", sc->lines[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		++y;
	}
	ft_allocate_ij(sc);
	ft_fill_i(sc);
//	ft_fill_j();
}


void	ft_allocate_ij(t_dt *sc)
{
	int	i;

	i = 0;
	sc->i = malloc(sizeof(int *) * (sc->size_y));
	sc->j = malloc(sizeof(int *) * (sc->size_y));
	while (i < sc->size_y)
	{
		sc->i[i] = malloc(sizeof(int) * sc->size_x);
		sc->j[i] = malloc(sizeof(int) * sc->size_x);
		++i;
	}
}


void	ft_fill_i(t_dt *sc)
{
	int i;
	int j;
	int margin;

	i = 0;
	j = 1;
	margin = 10;
	sc->i[0][0] = margin;
	while (i < sc->size_y)
	{
		while (j < sc->size_x)
		{
			sc->i[i][j] = sc->i[i][j - 1] + 14;
			++j;
		}
		++i;
		if (i < sc->size_y)
		{
			j = 0;
			margin += 14; 
			sc->i[i][j] = margin;
			j = 1;
		}
	}


	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < sc->size_y)
	{
		while (x < sc->size_x)
		{
			printf("%d ", sc->i[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		++y;
	}
}
