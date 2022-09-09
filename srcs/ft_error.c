/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:52:30 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/09 18:32:42 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int		ft_error(int code)
{
	if (code == 1)
		printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
	if (code == 2)
		printf("Map empty.\n");
	if (code == 3)
		printf("Can't read the map.\n");
	if (code == 4)
		printf("Size of map too big.\n");
	if (code == 100)
		printf("Malloc Error.\n");
	return (1);
}
