/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:06:58 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:30:01 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_iter && (zr * zr) + (zi * zi) <= 4)
	{
		tmp = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zr * zi) + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
