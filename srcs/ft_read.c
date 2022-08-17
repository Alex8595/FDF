/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:52 by ahernand          #+#    #+#             */
/*   Updated: 2022/08/17 20:39:23 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i);
}
int			ft_read(t_dt *sc, char *file)
{
	int		fd;
	char	*raw;
	int		size;

	if (ft_strlen(file) <= 0)
		return (ft_error(2));
	fd = open(file, O_READONLY);
	if (fd < 0)
		return (ft_error(3));
	raw = malloc(sizeof(char) * 500000);
	size
	return (0);
}