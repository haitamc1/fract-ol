/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julias.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:09:00 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:29:53 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double cr, double ci, t_p *p)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < p->max_it && (zr * zr) + (zi * zi) <= 4)
	{
		tmp = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zr * zi) + ci;
		cr = p->x;
		ci = p->y;
		zr = tmp;
		i++;
	}
	return (i);
}
