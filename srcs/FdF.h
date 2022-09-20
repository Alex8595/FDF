/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:33:13 by ahernand          #+#    #+#             */
/*   Updated: 2022/09/20 11:30:55 by ahernand         ###   ########.fr       */
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
# include <math.h>
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

	int				width;
	int				height;


	/*
	**
	*/

	int				size_x;
	int				size_y;
	
	char			**lines;


	int				**i;
	int				**j;
}					t_dt;

/*
**					Mlx Functions
*/

void				my_mlx_pixel_put(t_dt *sc, int x, int y, int color);
int					ft_close(int keycode, t_dt *vars);
void				ft_exec(t_dt *sc);
int					ft_error(int code);
int					ft_clean_dt(t_dt *vars);
int					ft_cross(int keycode, t_dt *vars);




/*
**					ft_read
*/

int					ft_read(t_dt *sc, char *ft_read);
void    			ft_save_raw(t_dt *sc, char **raw, int i);
int					ft_n_dots(char *str);
void    			ft_free_raw(char **raw, int i);



/*
**					ft_exec
*/

void    			ft_paint_up(t_dt *sc);
void    			ft_paint_down(t_dt *sc);
void    			dot(t_dt *sc, int j, int i,  int color);
void    			join_dots_up(t_dt *sc, double j, double i);
void    			join_dots_down(t_dt *sc, double j, double i);

void				ft_leaks();

/*
**					ft_coordinates
*/

void				ft_coordinates(t_dt *sc);
void				ft_allocate_ij(t_dt *sc);
void 				ft_fill_i(t_dt *sc);

#endif
