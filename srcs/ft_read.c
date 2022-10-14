/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:52 by ahernand          #+#    #+#             */
/*   Updated: 2022/10/14 12:35:12 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		ft_read
**
**		This function will save the information given though a file
**
*/

int	ft_read(t_dt *sc, char *file)
{
	int		fd;
	int		i;
	int		size;
	char	**raw;

	i = 0;
	raw = malloc(sizeof(char *) * 3000);
	if (!raw)
		return (ft_error(100));
	if (ft_strlen(file) <= 0)
		return (ft_error(2));
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(raw);
		return (ft_error(3));
	}
	while (i < 3000 && get_next_line(fd, &raw[i]))
		++i;
	if (i >= 3000)
		return (ft_error(4));
	ft_save_raw(sc, raw, i);
	ft_free_raw(sc, raw);
	close(fd);
	return (0);
}

/*
**
**
**
**
*/


void	ft_fix_empty_line(t_dt *sc, char **raw)
{
	if (sc->size_y - 1 > 0 && raw[sc->size_y - 1][0] == '\0')
	{
		if (sc->size_y - 2 > 0 && raw[sc->size_y - 2][0] == '\0')
			exit(ft_error(5));
		free(raw[sc->size_y - 1]);
		sc->size_y--;
	}
}



int	ft_longest_str(t_dt *sc, char **raw)
{
	int	longest;
	int	i;
	
	i = 0;
	longest = 0;
	while (i < sc->size_y)
	{
		if (ft_strlen(raw[i]) > ft_strlen(raw[longest]))
			longest = i;
		++i;
	}
	return (longest);
}

void	ft_save_raw(t_dt *sc, char **raw, int i)
{
	sc->size_y = i + 1;
	ft_fix_empty_line(sc, raw);
	sc->size_x = ft_n_dots(raw[ft_longest_str(sc, raw)]);
	sc->lines = malloc(sizeof(int*) * sc->size_y);
	if (!raw)
		return ;
	i = 0;
	while (i < sc->size_y)
	{
		printf("_ %d _\n", ft_n_dots(raw[i]));
		printf("Start \n");
		sc->lines[i] = malloc(sizeof(int) * (ft_n_dots(raw[i])));
		printf("End\n");
		//ft_fill_lines(sc, raw, i);
		i++;
	}
}




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
			while (ft_isdigit(raw[i][j + k]) || raw[i][j + k] == 'A' || raw[i][j + k] == 'B' ||
				raw[i][j + k] == 'C' || raw[i][j + k] == 'D' || raw[i][j + k] == 'E' || raw[i][j + k] == 'F')
				++k;
			aux = ft_strdup(raw[i]);
			aux[j + k] = '\0';
			free(aux);
			j += k;
			k = 0;
		}
		else if (raw[i][j] != '\0')
		{
//			printf("_%d . %d . %c_\n", i, j, raw[i][j]);
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

/*
**
**
**
**
*/

int	ft_n_dots(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) && ((i != 0 && str[i - 1] != ',' && str[i - 1] != 'x') || (i == 0)))
		{
			n++;
			while (str[i] != '\0' && (ft_ishexa(str[i]) || str[i] == 'x' || str[i] == ','))
				++i;
		}
		else if (str[i] != '\0')
			++i;
	}
	return (n);
}

/*
**
**
**
**
**
**
**
**
**
*/

void	ft_free_raw(t_dt *sc, char **raw)
{
	int	j;

	j = 0;
	while (j < sc->size_y)
	{
		free(raw[j]);
		++j;
	}
	free(raw);
}
