/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:13:53 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:37:55 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "mlx.h"
# include<math.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
// KEYS
//--------------------------------------------
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define Q 12
# define ESC 53
# define PLUS 69
# define MINUS 78
# define ZOOM 
# define C 8
// DIMENSIONS
//-----------------------
# define WIDTH 600
# define HEIGHT 600

// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	// int		color;
// }	t_data;

typedef struct p{
	void	*mlx;
	void	*win;
	int		max_it;
	int		color;
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;
	double	x;
	double	y;
	double	scope;
	int		julia_mov;

	int		set;

	double	r_or;
	double	i_or;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_p;

void	my_mlx_pixel_put(t_p *p, int x, int y, int color);
void	color(t_p *p, int i, int j, int n);
double	map(int x, double max, double min);
void	draw(t_p *p);

void	udlr(int key, t_p *p);
void	zoom(int key, t_p *p, int i, int j);
int		mouse_hook(int key, int i, int j, t_p *p);
int		mouse_move(int i, int j, t_p *p);
int		key(int key, t_p *p);
int		cross(t_p *p);

int		julia(double cr, double ci, t_p *p);
int		julia3(double cr, double ci, t_p *p);
int		julia4(double cr, double ci, t_p *p);
int		burning_ship(double cr, double ci, int max_iter);
int		feigenbaum(double cr, double ci, int max_iter);
int		mandelbrot(double cr, double ci, int max_iter);
int		mandelbrot3(double cr, double ci, int max_iter);
int		mandelbrot4(double cr, double ci, int max_iter);

int		wich_set(t_p *p, double cr, double ci);
int		ft_atoi(const char *str);
void	guides(void);
void	sets(void);

#endif
