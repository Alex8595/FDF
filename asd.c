/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:14:14 by ahernand          #+#    #+#             */
/*   Updated: 2022/07/30 17:45:11 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
	int i;
	int j;
	int found; 

	i = 0;
	j = 0;
	*z = n1;
	while (i < n2)
	{
		found = 0;
		while (j < n1 && found)
		{
			if (arr1[i] == arr2[j])
			{
				found = 1;
				*z = *z - 1;
			}
			++j;
		}
		j = 0;
		i++;
	}
	return (z);
}