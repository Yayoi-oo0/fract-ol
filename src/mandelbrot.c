/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:23:35 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/09/14 19:17:03 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_data *img)
{
	int	x;
	int	y;
	int	iter;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = calc_mandelbrot((x - WIDTH / 2 + img->offset_x) / img->zoom,
					(y - HEIGHT / 2 + img->offset_y) / img->zoom);
			if (iter > 0)
			{
				color = get_color_from_iter(iter * 9);
				my_mlx_pixel_put(img, x, y, color);
			}
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
