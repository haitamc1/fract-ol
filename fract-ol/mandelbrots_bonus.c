/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrots_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:06:58 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:40:28 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	mandelbrot3(double cr, double ci, int max_iter)
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
		tmp = (zr * zr * zr) - (3 * zr * zi * zi) + cr;
		zi = (3 * zr * zr * zi) - (zi * zi * zi) + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	mandelbrot4(double cr, double ci, int max_iter)
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
		tmp = (zr * zr * zr * zr) - (6 * zr * zr * zi * zi)
			+ (zi * zi * zi * zi) + cr;
		zi = (4 * zr * zr * zr * zi) - (4 * zr * zi * zi * zi) + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
