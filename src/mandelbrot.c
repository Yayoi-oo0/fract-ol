/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:23:35 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/30 15:24:22 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_data *img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = calc_mandelbrot((x - WIDTH / 2) / img->zoom, (y - HEIGHT
						/ 2) / img->zoom);
			if (color > 0)
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF - (color * 0x00FCBE11));
			x++;
		}
		y++;
	}
}

int	calc_mandelbrot(double x0, double y0)
{
	double	x;
	double	y;
	double	x_temp;
	int		iter;

	x = 0.0;
	y = 0.0;
	iter = 0;
	while (x * x + y * y <= 2.0 * 2.0 && iter < MAX_ITER)
	{
		x_temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = x_temp;
		iter++;
	}
	if (iter < MAX_ITER)
		return (iter);
	else
		return (0);
}
