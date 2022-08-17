/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:52:30 by ahernand          #+#    #+#             */
/*   Updated: 2022/08/17 20:38:31 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int		ft_error(int code)
{
	if (code == 1)
		printf("Usage : ./fdf <filename> [ case_size z_size ]");
	if (code == 2)
		printf("Map empty.");
	if (code == 3)
		printf("Can't read the map.");
	return (1);
}