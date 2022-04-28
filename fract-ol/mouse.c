/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:26:03 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:32:15 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		zoom(key, p);
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

void	zoom(int key, t_p *p)
{
	if (key == 4)
		p->scope *= 1.1;
	if (key == 5)
		p->scope /= 1.1;
}
