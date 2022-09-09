/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:51:03 by ahernand          #+#    #+#             */
/*   Updated: 2019/12/27 12:24:35 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (fd > 0)
	{
		if (n < 0)
			write(fd, "-", 1);
		num = (n < 0) ? -n : n;
		if (num < 10)
			ft_putchar_fd(num + '0', fd);
		else
		{
			ft_putnbr_fd(num / 10, fd);
			ft_putchar_fd(num % 10 + '0', fd);
		}
	}
}
