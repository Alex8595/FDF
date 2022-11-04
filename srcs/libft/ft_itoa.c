/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:18:47 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/13 18:15:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digit(unsigned int n)
{
	unsigned int	cnt;

	cnt = 0;
	while (n >= 10)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt + 1);
}

static void	assign_num(unsigned int num, char *ptr)
{
	*ptr-- = '\0';
	if (num == 0)
		*ptr = '0';
	while (num)
	{
		*ptr-- = (num % 10) + '0';
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	cnt;
	unsigned int	sign;
	unsigned int	num;

	sign = 0;
	num = n;
	if (n < 0)
	{
		num = -n;
		sign = 1;
	}
	cnt = count_digit(num);
	str = (char *)malloc(sizeof(char) * (cnt + sign + 1));
	if (!str)
		return (0);
	if (sign == 1)
	{
		*str = '-';
		assign_num(num, str + cnt + 1);
	}
	else
		assign_num(num, str + cnt);
	return (str);
}
