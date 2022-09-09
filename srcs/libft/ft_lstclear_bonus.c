/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:06:19 by ahernand          #+#    #+#             */
/*   Updated: 2019/12/27 13:58:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*loc;

	if (lst && *lst && del)
	{
		ptr = *lst;
		while (ptr)
		{
			loc = ptr->next;
			(*del)(ptr->content);
			free(ptr);
			ptr = loc;
		}
		(*lst) = NULL;
	}
}
