/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:23:51 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/09 11:57:07 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			j;
	unsigned char	*a;

	a = s;
	j = 0;
	while (n > j)
	{
		a[j] = '\0';
		j++;
	}
}

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*cpy_str;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1)));
	if (!str)
		return (0);
	cpy_str = str;
	if (s1)
		while (*s1 != '\0')
			*cpy_str++ = *s1++;
	if (s2)
		while (*s2 != '\0')
			*cpy_str++ = *s2++;
	*cpy_str = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * (int)len + 1);
		if (!str)
			return (NULL);
		ft_bzero(str, len);
		if (start <= ft_strlen(s))
		{
			while (i < len && s[i])
			{
				str[i] = s[i + start];
				i++;
			}
		}
		if (len < i + 1)
			str[i] = '\0';
		return (str);
	}
	return (0);
}
