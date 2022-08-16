/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:33:13 by ahernand          #+#    #+#             */
/*   Updated: 2022/08/16 20:10:39 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx/mlx.h"

typedef struct		s_data
{
	void			*mlx;
	void			*win;

	void			*img;
	char			*addr;

	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

/*
**					Mlx Functions
*/

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif