/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:07 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/26 15:13:33 by oyayoi           ###   ########.fr       */
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
	t_data	img;
	int		i;
	int		j;
	double	scale;
	int		color;

	i = 0.0;
	j = 0.0;
	scale = 0.004;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			color = calc_mandelbrot((i - WIDTH / 2) * scale, (j - HEIGHT / 2) * scale);
			if (color > 0)
				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF - (color * 0x00FCBE11));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, key_event, &img);
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
}

int	key_event(int keycode, t_data *param)
{
	if (keycode == ESC_KEY)
		close_window(param);
	return (0);
}

int	mouse_event(int button, int x, int y, t_data *param)
{
	if (button == MOUSE_DOWN)
	{
		// Handle mouse down event
	}
	else if (button == MOUSE_UP)
	{
		// Handle mouse up event
	}
	return (0);
}

int	close_window(t_data *param)
{
	mlx_destroy_window(param->mlx, param->mlx_win);
	exit(0);
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
