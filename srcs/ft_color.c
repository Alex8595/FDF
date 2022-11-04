/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:24:19 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/04 11:01:39 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_color_alloc(t_dt *sc, char **raw)
{
	int	i;

	i = 0;
	sc->r = malloc(sizeof(int *) * sc->size_y);
	sc->g = malloc(sizeof(int *) * sc->size_y);
	sc->b = malloc(sizeof(int *) * sc->size_y);
	while (i < sc->size_y)
	{
		sc->r[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		sc->g[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		sc->b[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		array_int_init_to_0(sc->r[i], sc->size_x);
		array_int_init_to_0(sc->g[i], sc->size_x);
		array_int_init_to_0(sc->b[i], sc->size_x);
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
