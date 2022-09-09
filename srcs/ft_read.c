/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:29:52 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/09 18:32:51 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int			ft_read(t_dt *sc, char *file)
{
	int		fd;
	int		i;
	int		size;
	char	**lines;

	i = 0;
	if (!(lines = malloc((sizeof(char *) * 500))))
		return (100);
	if (ft_strlen(file) <= 0)
		return (ft_error(2));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(3));
	while (i < 500 && get_next_line(fd, &lines[i]))
		++i;
	if (i >= 500)
		return (ft_error(4));
	printf("__-%s__", lines[0]);
	return (0);
}
