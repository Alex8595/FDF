/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_paint_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:10:10 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/11 11:24:03 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_paint_up
**
**		Join the dots, draws the upwards going lines
**
*/

void	ft_paint_down(t_dt *sc)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < sc->size_y - 1)
	{
		while (l < sc->size_x)
		{
			if (fabs(sc->i[k + 1][l] - sc->i[k][l])
				> fabs(sc->j[k + 1][l] - sc->j[k][l]))
				join_dots_down_more_y(sc, k, l);
			else
				join_dots_down_more_x(sc, k, l);
			l++;
		}
		l = 0;
		++k;
	}
}

void	join_dots_down_more_y(t_dt *sc, int k, int l)
{
	sc->a = 0;
	sc->bb = 0;
	while (sc->a < fabs(sc->i[k][l] - sc->i[k + 1][l]))
	{
		sc->bb += fabs(sc->j[k + 1][l] - (sc->j[k][l]))
			/ (sc->i[k + 1][l] - sc->i[k][l]);
		if (sc->i[k + 1][l] < sc->i[k][l])
			dot(sc, sc->j[k][l] - sc->bb, sc->i[k][l] - sc->a,
				color1(sc, k, l));
		else
			dot(sc, sc->j[k][l] + sc->bb, sc->i[k][l] + sc->a,
				color2(sc, k, l));
		++sc->a;
	}
}

void	join_dots_down_more_x(t_dt *sc, int k, int l)
{
	sc->a = 0;
	sc->bb = 0;
	while (sc->a + sc->j[k][l] < sc->j[k + 1][l])
	{
		sc->bb += fabs(sc->i[k + 1][l] - sc->i[k][l])
			/ fabs(sc->j[k + 1][l] - sc->j[k][l]);
		if (sc->i[k + 1][l] < sc->i[k][l])
			dot(sc, sc->j[k][l] + sc->a, sc->i[k][l] - sc->bb + 1,
				color3(sc, k, l));
		else
			dot(sc, sc->j[k][l] + sc->a, sc->i[k][l] + sc->bb - 1,
				color4(sc, k, l));
		++sc->a;
	}
}
