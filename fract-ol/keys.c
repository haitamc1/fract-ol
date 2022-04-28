/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:18:03 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/25 23:06:43 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key(int key, t_p *p)
{
	if (key == ESC || key == Q)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
			&(p->line_length), &(p->endian));
	if (key == C)
		p->color++;
	else if (key == PLUS)
		p->max_it += 20;
	else if (key == MINUS && p->max_it >= 255)
		p->max_it -= 20;
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		udlr(key, p);
	draw(p);
	return (0);
}

void	udlr(int key, t_p *p)
{
	if (key == RIGHT)
		p->r_or -= 0.1;
	else if (key == LEFT)
		p->r_or += 0.1;
	else if (key == UP)
		p->i_or += 0.1;
	else if (key == DOWN)
		p->i_or -= 0.1;
}
