/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:38:21 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/09/14 18:10:29 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_julia(t_data *img)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = calc_julia((x - WIDTH / 2) / img->zoom, (y - HEIGHT
						/ 2) / img->zoom, img->julia_a, img->julia_b);
			if (iter > 0)
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF - (img->color * iter));
			x++;
		}
		y++;
	}
}

int	calc_julia(double x0, double y0, double a, double b)
{
	double	x;
	double	y;
	double	x_temp;
	int		iter;

	x = x0;
	y = y0;
	iter = 0;
	while (x * x + y * y <= 2.0 * 2.0 && iter < MAX_ITER)
	{
		x_temp = x * x - y * y + a;
		y = 2 * x * y + b;
		x = x_temp;
		iter++;
	}
	if (iter < MAX_ITER)
		return (iter);
	else
		return (0);
}
