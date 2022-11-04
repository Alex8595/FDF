/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:14:26 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/02 14:02:37 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (dst == '\0' && src == '\0')
		return (0);
	if (dst > src)
	{
		while (++i <= len)
		{
			d[len - i] = s[len - i];
		}
	}
	else
	{
		while (len > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
