/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_5_to_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:10:20 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/11 11:14:40 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	color5(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k][l + 1] - sc->r[k][l])
								/ fabs(sc->j[k][l] - sc->j[k][l + 1])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k][l + 1] - sc->g[k][l])
							/ fabs(sc->j[k][l] - sc->j[k][l + 1]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k][l + 1] - sc->b[k][l])
					/ fabs(sc->j[k][l] - sc->j[k][l + 1]))));
	return (c);
}

int	color6(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k][l + 1] - sc->r[k][l])
								/ fabs(sc->j[k][l] - sc->j[k][l + 1])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k][l + 1] - sc->g[k][l])
							/ fabs(sc->j[k][l] - sc->j[k][l + 1]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k][l + 1] - sc->b[k][l])
					/ fabs(sc->j[k][l] - sc->j[k][l + 1]))));
	return (c);
}

int	color7(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k][l + 1] - sc->r[k][l])
								/ fabs(sc->i[k][l] - sc->i[k][l + 1])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k][l + 1] - sc->g[k][l])
							/ fabs(sc->i[k][l] - sc->i[k][l + 1]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k][l + 1] - sc->b[k][l])
					/ fabs(sc->i[k][l] - sc->i[k][l + 1]))));
	return (c);
}

int	color8(t_dt *sc, int k, int l)
{
	int	c;

	c = ((((int)(sc->r[k][l] + (sc->a * ((sc->r[k][l + 1] - sc->r[k][l])
								/ fabs(sc->i[k][l] - sc->i[k][l + 1])))) << 8)
				+ (int)(sc->g[k][l] + (sc->a * ((sc->g[k][l + 1] - sc->g[k][l])
							/ fabs(sc->i[k][l] - sc->i[k][l + 1]))))) << 8)
		+ (int)(sc->b[k][l] + (sc->a * ((sc->b[k][l + 1] - sc->b[k][l])
					/ fabs(sc->i[k][l] - sc->i[k][l + 1]))));
	return (c);
}
