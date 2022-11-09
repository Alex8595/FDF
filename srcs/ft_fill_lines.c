/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:46:24 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/09 11:23:17 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_fill_lines
**	
**		Saves depth and color info
**
*/

void	ft_fill_lines(t_dt *sc, char **raw, int i)
{
	char	*aux;

	while (raw[i][sc->h] != '\0')
	{
		while (raw[i][sc->h] != '\0' && !ft_isdigit(raw[i][sc->h]))
			++sc->h;
		if (raw[i][sc->h] != '\0' && sc->h != 0 && raw[i][sc->h - 1] == ',')
		{
			sc->h += 2;
			while (raw[i][sc->h + sc->k] != '\0'
					&& ft_ishexa(raw[i][sc->h + sc->k]))
				++sc->k;
			aux = ft_strdup(raw[i]);
			ft_store_hexa(sc, aux, &i);
			free(aux);
			sc->h += sc->k;
			sc->k = 0;
		}
		else if (raw[i][sc->h] != '\0')
			ft_store_depth(sc, raw, aux, &i);
	}
	sc->h = 0;
	sc->k = 0;
	sc->l = 0;
}

void	ft_store_depth(t_dt *sc, char **raw, char *aux, int *i)
{
	while (raw[*i][sc->h] != '\0' && ft_isdigit(raw[*i][sc->h + sc->k]))
		++sc->k;
	aux = ft_strdup(raw[*i]);
	aux[sc->h + sc->k] = '\0';
	if (sc->h != 0 && aux[sc->h - 1] == '-')
		sc->lines[*i][sc->l] = ft_atoi(&aux[sc->h - 1]);
	else
		sc->lines[*i][sc->l] = ft_atoi(&aux[sc->h]);
	sc->l++;
	free(aux);
	sc->h += sc->k;
	sc->k = 0;
}

void	ft_store_hexa(t_dt *sc, char *aux, int *i)
{
	if (sc->k == 6)
	{
		aux[sc->h + sc->k] = '\0';
		sc->b[*i][sc->l - 1] = ft_hextoint(&aux[sc->h + 4]);
		aux[sc->h + sc->k - 2] = '\0';
		sc->g[*i][sc->l - 1] = ft_hextoint(&aux[sc->h + 2]);
		aux[sc->h + sc->k - 4] = '\0';
		sc->r[*i][sc->l - 1] = ft_hextoint(&aux[sc->h]);
	}
	if (sc->k == 4)
	{
		sc->r[*i][sc->l - 1] = 0;
		aux[sc->h + sc->k - 2] = '\0';
		sc->g[*i][sc->l - 1] = ft_hextoint(&aux[sc->h]);
		aux[sc->h + sc->k] = '\0';
		sc->b[*i][sc->l - 1] = ft_hextoint(&aux[sc->h + 2]);
	}
	if (sc->k == 2)
	{
		sc->r[*i][sc->l - 1] = 0;
		sc->g[*i][sc->l - 1] = 0;
		aux[sc->h + sc->k] = '\0';
		sc->b[*i][sc->l - 1] = ft_hextoint(&aux[sc->h]);
	}
}
