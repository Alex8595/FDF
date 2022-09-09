/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:08:06 by ahernand          #+#    #+#             */
/*   Updated: 2019/12/03 17:20:32 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *pers;

	if ((pers = (t_list *)malloc(sizeof(t_list))) == 0)
		return (0);
	pers->content = content;
	pers->next = NULL;
	return (pers);
}
