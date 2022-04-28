/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:26:03 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:40:42 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	cross(t_p *p)
{
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}

int	mouse_hook(int key, int i, int j, t_p *p)
{
	double	ax;
	double	ay;
	double	bx;
	double	by;

	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
			&(p->line_length), &(p->endian));
	if (key == 4 || key == 5)
		zoom(key, p, i, j);
	if (key == 1)
		p->julia_mov = 0;
	mlx_clear_window(p->mlx, p->win);
	draw(p);
	return (0);
}

int	mouse_move(int i, int j, t_p *p)
{
	if (p->julia_mov)
	{
		mlx_clear_window(p->mlx, p->win);
		p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
		p->addr = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
				&(p->line_length), &(p->endian));
		p->x = map(i, p->r_or + p->scope, p->r_or - p->scope);
		p->y = map(j, p->i_or + p->scope, p->i_or - p->scope);
		draw(p);
	}
	return (0);
}

void	zoom(int key, t_p *p, int i, int j)
{
	double	ax;
	double	ay;
	double	bx;
	double	by;

	bx = map(i, p->r_or + p->scope, p->r_or - p->scope);
	by = map(j, p->i_or + p->scope, p->i_or - p->scope);
	if (key == 4)
		p->scope *= 1.1;
	if (key == 5)
		p->scope /= 1.1;
	ax = map(i, p->r_or + p->scope, p->r_or - p->scope);
	ay = map(j, p->i_or + p->scope, p->i_or - p->scope);
	p->r_or += bx - ax;
	p->i_or += by - ay;
}
