/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_paint_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:10:11 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/11 11:23:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_paint_up
**
**		Join the dots, draws the upwards going lines
**
*/

void	ft_paint_up(t_dt *sc)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < sc->size_y)
	{
		while (l < sc->size_x - 1)
		{
			if (fabs(sc->i[k][l + 1] - sc->i[k][l])
				> fabs(sc->j[k][l + 1] - sc->j[k][l]))
				join_dots_up_more_y(sc, k, l);
			else
				join_dots_up_more_x(sc, k, l);
			l++;
		}
		l = 0;
		++k;
	}
}

void	join_dots_up_more_x(t_dt *sc, int k, int l)
{
	sc->a = 0;
	sc->bb = 0;
	while (sc->a + sc->j[k][l] < sc->j[k][l + 1])
	{
		sc->bb += fabs(sc->i[k][l + 1] - sc->i[k][l])
			/ fabs(sc->j[k][l + 1] - sc->j[k][l]);
		if (sc->i[k][l + 1] < sc->i[k][l])
			dot(sc, sc->j[k][l] + sc->a, sc->i[k][l] - sc->bb,
				color5(sc, k, l));
		else
			dot(sc, sc->j[k][l] + sc->a, sc->i[k][l] + sc->bb,
				color6(sc, k, l));
		++sc->a;
	}
}

void	join_dots_up_more_y(t_dt *sc, int k, int l)
{
	sc->a = 0;
	sc->bb = 0;
	while (sc->a < fabs(sc->i[k][l] - sc->i[k][l + 1]))
	{
		sc->bb += fabs((sc->j[k][l + 1]) - sc->j[k][l])
			/ fabs(sc->i[k][l + 1] - sc->i[k][l]);
		if (sc->i[k][l + 1] < sc->i[k][l])
			dot(sc, sc->j[k][l] + sc->bb, sc->i[k][l] - sc->a,
				color7(sc, k, l));
		else
			dot(sc, sc->j[k][l] + sc->bb, sc->i[k][l] + sc->a,
				color8(sc, k, l));
		++sc->a;
	}
}
