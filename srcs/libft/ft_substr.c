/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:43:02 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/02 15:20:37 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;
	char	*cpy_str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !str)
		return (0);
	if (start > ft_strlen(s))
		str[0] = '\0';
	else
	{
		ptr = (char *)s + start;
		cpy_str = str;
		while (*ptr && len-- > 0)
			*cpy_str++ = *ptr++;
		*cpy_str = '\0';
	}
	return (str);
}
