/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:07 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/23 17:38:04 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;
	double  scale;
	int 	color;

	i = 0.0;
	j = 0.0;
	scale = 0.004;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			color = calc_mandelbrot((i - 1920 / 2) * scale, (j - 1080 / 2) * scale);
			if (color > 0)
				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF - (color * 0x00FCBE11));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	calc_mandelbrot(double x0, double y0)
{
	double	x;
	double	y;
	double	x_temp;
	int		iter;
	int		max_iter;

	x = 0.0;
	y = 0.0;
	iter = 0;
	max_iter = 100;
	while (x * x + y * y <= 2.0 * 2.0 && iter < max_iter)
	{
		x_temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = x_temp;
		iter++;
	}
	if (iter < max_iter)
		return (iter);
	else
		return (0);
}
