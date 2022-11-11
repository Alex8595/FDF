/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1_to_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:10:15 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/11 11:24:10 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	color1(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k + 1][l] - sc->r[k][l])
								/ fabs(sc->i[k][l] - sc->i[k + 1][l])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k + 1][l] - sc->g[k][l])
							/ fabs(sc->i[k][l] - sc->i[k + 1][l]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k + 1][l] - sc->b[k][l])
					/ fabs(sc->i[k][l] - sc->i[k + 1][l]))));
	return (c);
}

int	color2(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k + 1][l] - sc->r[k][l])
								/ fabs(sc->i[k][l] - sc->i[k + 1][l])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k + 1][l] - sc->g[k][l])
							/ fabs(sc->i[k][l] - sc->i[k + 1][l]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k + 1][l] - sc->b[k][l])
					/ fabs(sc->i[k][l] - sc->i[k + 1][l]))));
	return (c);
}

int	color3(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k + 1][l] - sc->r[k][l])
								/ fabs(sc->j[k][l] - sc->j[k + 1][l])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k + 1][l] - sc->g[k][l])
							/ fabs(sc->j[k][l] - sc->j[k + 1][l]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k + 1][l] - sc->b[k][l])
					/ fabs(sc->j[k][l] - sc->j[k + 1][l]))));
	return (c);
}

int	color4(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k + 1][l] - sc->r[k][l])
								/ fabs(sc->j[k][l] - sc->j[k + 1][l])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k + 1][l] - sc->g[k][l])
							/ fabs(sc->j[k][l] - sc->j[k + 1][l]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k + 1][l] - sc->b[k][l])
					/ fabs(sc->j[k][l] - sc->j[k + 1][l]))));
	return (c);
}
