/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:03:26 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/02 14:55:08 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_bstrlen(const char *usrc)
{
	size_t	z;
	char	*p;

	p = (char *)usrc;
	z = 0;
	while (usrc[z] != '\0')
		z++;
	return (z);
}

static size_t	ft_help(char *ddst, const char *ssrc, size_t size, size_t i)
{
	size_t	j;
	size_t	z;
	char	*udest;
	char	*usrc;

	j = 0;
	udest = (char *)ddst;
	usrc = (char *)ssrc;
	while (udest[i] != '\0' && i < size)
		i++;
	z = ft_bstrlen(usrc);
	if (size == 0 || i > (size - 1))
		return (size + z);
	while (usrc[j] != '\0' && j + i < (size - 1))
	{
		udest[i + j] = usrc[j];
		j++;
	}
	while (i + j < (size - 1))
	{
		udest[i + j] = '\0';
		j++;
	}
	udest[i + j] = '\0';
	return (i + z);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	char	*ddest;
	char	*ssrc;

	i = 0;
	ddest = (char *)dst;
	ssrc = (char *)src;
	return (ft_help(ddest, ssrc, size, i));
}
