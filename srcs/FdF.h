/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:33:13 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/09 18:32:44 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../srcs/libft/libft.h"

typedef struct		t_dt
{
	void			*mlx;
	void			*win;

	void			*img;
	char			*addr;

	int				bits_per_pixel;
	int				line_length;
	int				endian;


	int				size_x;
	int				size_y;

}					t_dt;

/*
**					Mlx Functions
*/

void				my_mlx_pixel_put(t_dt *sc, int x, int y, int color);
int					ft_close(int keycode, t_dt *vars);
int					ft_read(t_dt *sc, char *ft_read);
void				ft_exec(t_dt *sc);
int					ft_error(int code);

#endif
