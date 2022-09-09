/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:54:13 by ahernand          #+#    #+#             */
/*   Updated: 2019/11/18 20:29:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	cc;

	cc = c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		if (s[i] == cc)
		{
			i++;
			return (&d[i]);
		}
		i++;
	}
	return (0);
}
