/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:20 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/19 17:23:27 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_coordinates(t_dt *sc)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (x < sc->size_x)
	{
		while (y < sc->size_y)
		{
			printf("%c ", sc->lines[x][y]);
			y++;
		}
		printf("\n");
		++x;
		y = 0;
	}
	ft_allocate_ij(sc);
}


void	ft_allocate_ij(t_dt *sc)
{
	int i;

	i = 0;
	sc->i = malloc(sizeof(int *) * (2 + 1));
	sc->j = malloc(sizeof(int *) * (2 + 1));
	printf("_%d_\n", sc->size_y);
}
