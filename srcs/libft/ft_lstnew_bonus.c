/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:08:06 by ahernand          #+#    #+#             */
/*   Updated: 2021/08/02 13:45:37 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pers;

	per = (t_list *)malloc(sizeof(t_list));
	if (!pers)
		return (0);
	pers->content = content;
	pers->next = NULL;
	return (pers);
}
