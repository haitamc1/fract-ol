/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:11:07 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:29:20 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	sets(void)
{
	write(1, "\033[0;32m------------Available Sets------------\n", 49);
	write(1, "\033[0;34m.For Mandelbrot press 1\n", 34);
	write(1, "\033[0;34m.For Julia press 2\n", 29);
	write(1, "\033[0;32m-------------------------------------\n", 48);
}

void	guides(void)
{
	write(1, "\033[0;33m|----------------CONTROLS--------------|\n", 50);
	write(1, "\033[0;33m|                                      |\n", 50);
	write(1, "\033[0;33m|       ↑        : Move Up             |\n", 50);
	write(1, "\033[0;33m|       →        : Move Right          |\n", 50);
	write(1, "\033[0;33m|       ↓        : Move Down           |\n", 50);
	write(1, "\033[0;33m|       ←        : Move Left           |\n", 50);
	write(1, "\033[0;33m|       +        : Increase Iteration  |\n", 50);
	write(1, "\033[0;33m|       -        : Decrease Iteration  |\n", 50);
	write(1, "\033[0;33m|   Scroll UP    : Zoom_In             |\n", 48);
	write(1, "\033[0;33m|   Scroll Down  : Zoom_Out            |\n", 48);
	write(1, "\033[0;33m|   Left Click   : Stop Julia Set      |\n", 48);
	write(1, "\033[0;33m|   C            : Change Color        |\n", 48);
	write(1, "\033[0;33m|   ESC || Q     : QUIT                |\n", 48);
	write(1, "\033[0;33m|                                      |\n", 48);
	write(1, "\033[0;33m|--------------------------------------|\n", 48);
}
