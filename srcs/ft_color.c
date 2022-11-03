/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:24:19 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/03 12:23:06 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_color_alloc(t_dt *sc, char **raw)
{
	int	i;

	i = 0;
	sc->R = malloc(sizeof(int *) * sc->size_y);
	sc->G = malloc(sizeof(int *) * sc->size_y);
	sc->B = malloc(sizeof(int *) * sc->size_y);
	while (i < sc->size_y)
	{
		sc->R[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		sc->G[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		sc->B[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		array_int_init_to_0(sc->R[i], sc->size_x);
		array_int_init_to_0(sc->G[i], sc->size_x);
		array_int_init_to_0(sc->B[i], sc->size_x);
		++i;
	}
}

void	array_int_init_to_0(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 255;
		++i;
	}
}
