/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:16:24 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/02 14:07:46 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*s;
	unsigned char	loc;
	int				i;

	s = (char *)str;
	loc = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == loc)
			return (&s[i]);
		i++;
	}
	if (s[i] == loc)
		return (&s[i]);
	return (0);
}
