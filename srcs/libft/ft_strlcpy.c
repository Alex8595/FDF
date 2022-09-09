/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:44:22 by ahernand          #+#    #+#             */
/*   Updated: 2019/11/28 19:38:07 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;
	char	*ddst;
	char	*ssrc;

	i = 0;
	ls = 0;
	ddst = (char*)dst;
	ssrc = (char*)src;
	if (!dst || !src)
		return (0);
	while (ssrc[ls] != '\0')
		ls++;
	if (size == 0)
		return (ls);
	while (ssrc[i] != '\0' && i < size - 1)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	ddst[i] = '\0';
	return (ls);
}
