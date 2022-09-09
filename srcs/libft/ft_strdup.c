/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:36:35 by ahernand          #+#    #+#             */
/*   Updated: 2019/11/18 20:31:43 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*cstr;
	char	*empty;
	int		l;
	int		j;

	str = (char*)s1;
	l = 0;
	j = 0;
	if (!(str[0]))
		return (empty = ft_calloc(1, 1));
	while (str[l] != '\0')
		l++;
	if ((cstr = (malloc(l + 1))) == NULL)
		return (0);
	while (j < (l + 1))
	{
		cstr[j] = str[j];
		j++;
	}
	return (cstr);
}
