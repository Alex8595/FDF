/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:21:13 by ahernand          #+#    #+#             */
/*   Updated: 2019/11/28 20:38:54 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_chorizo(size_t i, char *sstr,
						char *tto_find, size_t len)
{
	int		k;
	int		j;
	char	*str;
	char	*to_find;

	k = 0;
	j = 0;
	str = sstr;
	to_find = tto_find;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0'
				&& i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len)
{
	size_t	i;
	char	*sstr;
	char	*tto_find;

	i = 0;
	sstr = (char*)haystack;
	tto_find = (char*)needle;
	return (ft_chorizo(i, sstr, tto_find, len));
}
