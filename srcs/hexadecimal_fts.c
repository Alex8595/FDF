/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_fts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:57:03 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/09 11:33:28 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
**		Hexa functions
*/

int	ft_hextoint(char *str)
{
	int	num;
	int	i;

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

int	ft_ishexa(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	else
		return (0);
}
