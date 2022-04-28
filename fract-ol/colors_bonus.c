/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:24:18 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:37:08 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color(t_p *p, int i, int j, int n)
{	
	if (p->color == 1)
		my_mlx_pixel_put(p, i, j, n * 0x50505);
	else if (p->color == 2)
		my_mlx_pixel_put(p, i, j, n * 0x00f00ff0);
	else if (p->color == 3)
		my_mlx_pixel_put(p, i, j, n * 0xfff8dc);
	else if (p->color == 4)
		my_mlx_pixel_put(p, i, j, n * 0x9a32cd);
	else if (p->color == 5)
		my_mlx_pixel_put(p, i, j, n * 0x87cefa);
	else if (p->color == 6)
		my_mlx_pixel_put(p, i, j, n * 0xf5fffa);
	else if (p->color == 7)
		my_mlx_pixel_put(p, i, j, n * 0xffe4b5);
	else
	{
		p->color = 1;
		color(p, i, j, n);
	}
}
