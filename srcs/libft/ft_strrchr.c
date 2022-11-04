/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:29:10 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/02 15:16:14 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*s;
	unsigned char	loc;
	int				i;
	int				y;

	s = (char *)str;
	loc = c;
	i = 0;
	y = -1;
	while (s[i] != '\0')
	{
		if (s[i] == loc)
			y = i;
		i++;
	}
	if (y != -1)
		return (&s[y]);
	else if (s[i] == loc)
		return (&s[i]);
	else
		return (0);
}
