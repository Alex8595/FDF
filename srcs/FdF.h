/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:33:13 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/14 12:17:26 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../minilibx/mlx.h"
# include "../srcs/libft/libft.h"

typedef struct t_dt
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

	int				fullcreen;
	int				fullcreen_vertical;

	double			highest_y;
	int				highest_y_i;
	int				highest_y_j;

	double			lowest_y;
	int				lowest_y_i;
	int				lowest_y_j;

	double			line_height;
	double			line_width;
	double			line_depth;

	int				angle;

	int				size_x;
	int				size_y;

	int				**lines;

	double			**i;
	double			**j;

	int				**r;
	int				**g;
	int				**b;

	int				h;
	int				k;
	int				l;

	double			a;
	double			bb;

}					t_dt;

/*
**					FdF
*/

void				ft_init_vars(t_dt *sc);

/*
**					ft_read
*/

int					ft_empty(char *file);
int					ft_right_end(char *file);
int					ft_read(t_dt *sc, char *ft_read);
void				ft_free_raw(t_dt *sc, char **raw);

/*
**					ft_save_raw
*/

int					ft_n_dots(char *str);
int					ft_longest_str(t_dt *sc, char **raw);
void				ft_fix_empty_line(t_dt *sc, char **raw);
void				ft_save_raw(t_dt *sc, char **raw, int i);

/*
**					ft_fill_lines
*/

void				ft_store_hexa(t_dt *sc, char *aux, int *i);
void				ft_fill_lines(t_dt *sc, char **raw, int i);
void				ft_store_depth(t_dt *sc, char **raw, char *aux, int *i);

/*
**					hexadecimal_fts
*/

int					ft_ishexa(int c);
int					ft_hextoint(char *str);

/*
**					Mlx Functions
*/

int					ft_cross(void);
int					ft_close(int keycode, t_dt *vars);
void				dot(t_dt *sc, int j, int i, int color);
void				my_mlx_pixel_put(t_dt *sc, int x, int y, int color);

/*
**					ft_error
*/

int					ft_error(int code);

/*
**					ft_color
*/

void				ft_color_alloc(t_dt *sc, char **raw);
void				array_int_init_to_0(int *arr, int size);

/*
**					ft_coordinates
*/

void				ft_fill_i(t_dt *sc);
void				ft_fill_j(t_dt *sc);
void				ft_fill_depth(t_dt *sc);
void				ft_coordinates(t_dt *sc);
void				ft_allocate_ij(t_dt *sc);

/*
**					ft_exec
*/

void				ft_exec(t_dt *sc);
void				ft_lenght_lines(t_dt *sc);
int					ft_calculate_height(t_dt *sc);
void				ft_fullscreen_vertical_helper(t_dt *sc);

/*
**					ft_exec_paint_up
*/

void				ft_paint_up(t_dt *sc);
void				join_dots_up(t_dt *sc, int j, int i);
void				join_dots_up_hub(t_dt *sc, int j, int i);
void				join_dots_up_more_x(t_dt *sc, int j, int i);
void				join_dots_up_more_y(t_dt *sc, int j, int i);

/*
**					ft_exec_paint_down
*/

void				ft_paint_down(t_dt *sc);
void				join_dots_down(t_dt *sc, int j, int i);
void				join_dots_down_hub(t_dt *sc, int j, int i);
void				join_dots_down_more_x(t_dt *sc, int j, int i);
void				join_dots_down_more_y(t_dt *sc, int j, int i);

/*
**					color_1_to_4
*/

int					color1(t_dt *sc, int k, int l);
int					color2(t_dt *sc, int k, int l);
int					color3(t_dt *sc, int k, int l);
int					color4(t_dt *sc, int k, int l);

/*
**					color_5_to_8
*/

int					color5(t_dt *sc, int k, int l);
int					color6(t_dt *sc, int k, int l);
int					color7(t_dt *sc, int k, int l);
int					color8(t_dt *sc, int k, int l);

#endif