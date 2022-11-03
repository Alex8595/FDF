/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:46:24 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/03 12:18:31 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_fill_lines
**	
**		Saves depth and color info
**
*/

int ft_hextoint(char *str)
{
	int	num;
	int aux;
	int i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			str[i] = (int)str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = (int)str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			str[i] = (int)str[i] - 'A' + 10;
		num = num << 4;
		num += str[i];
		i++;
	}
	return (num);
}

int		ft_ishexa(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	else
		return (0);
}


void    ft_fill_lines(t_dt *sc, char **raw, int i)
{
	int	j;
	int	k;
	int	l;
	char	*aux;

	k = 0;
	j = 0;
	l = 0;
	while (raw[i][j] != '\0')
	{
		while (raw[i][j] != '\0' && !ft_isdigit(raw[i][j]))
			++j;
		if (raw[i][j] != '\0' && j != 0 && raw[i][j - 1] == ',')
		{
			j += 2;
			while (raw[i][j + k] != '\0' && ft_ishexa(raw[i][j + k]))
				++k;
			aux = ft_strdup(raw[i]);
			if (k == 6)
			{
				aux[j + k] = '\0';
				sc->B[i][l - 1] = ft_hextoint(&aux[j + 4]);
				aux[j + k - 2] = '\0';
				sc->G[i][l - 1] = ft_hextoint(&aux[j + 2]);
				aux[j + k - 4] = '\0';
				sc->R[i][l - 1] = ft_hextoint(&aux[j]);
			}
			if (k == 4)
			{
				sc->R[i][l - 1] = 0;
				aux[j + k - 2] = '\0';
				sc->G[i][l - 1] = ft_hextoint(&aux[j]);
				aux[j + k] = '\0';
				sc->B[i][l - 1] = ft_hextoint(&aux[j + 2]);
			}
			if (k == 2)
			{
				sc->R[i][l - 1] = 0;
				sc->G[i][l - 1] = 0;
				aux[j + k] = '\0';
				sc->B[i][l - 1] = ft_hextoint(&aux[j]);
			}
			free(aux);
			j += k;
			k = 0;
		}
		else if (raw[i][j] != '\0')
		{
			while (raw[i][j] != '\0' && ft_isdigit(raw[i][j + k]))
				++k;
			aux = ft_strdup(raw[i]);
			aux[j + k] = '\0';
			if (j != 0 && aux[j - 1] == '-')
				sc->lines[i][l] = ft_atoi(&aux[j - 1]);
			else
				sc->lines[i][l] = ft_atoi(&aux[j]);
			l++;
			free(aux);
			j += k;
			k = 0;
		}
	}
}
