/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:16:27 by ahernand          #+#    #+#             */
/*   Updated: 2019/11/13 16:50:35 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((*ss1 != '\0') && (*ss2 != '\0') && (*ss1 == *ss2) && (n - 1 > 0))
	{
		ss1++;
		ss2++;
		n--;
	}
	if (*ss1 == *ss2)
		return (0);
	else
		return (*ss1 - *ss2);
}
