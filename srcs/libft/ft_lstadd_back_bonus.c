/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:37:48 by ahernand          #+#    #+#             */
/*   Updated: 2019/12/27 13:56:53 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return ;
		}
		while (((*alst)->next) != NULL)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
	}
}
