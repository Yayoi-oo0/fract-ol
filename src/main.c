/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:07 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/26 22:57:23 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	img;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0
			&& ft_strlen(argv[1]) == 10) || (argc == 4 && ft_strncmp(argv[1],
				"julia", 5) && ft_strlen(argv[1]) == 5))
	{
		init_data(&img);
		draw_fractal(&img);
		mlx_key_hook(img.mlx_win, key_event, &img);
		mlx_mouse_hook(img.mlx_win, mouse_event, &img);
		mlx_hook(img.mlx_win, 17, 0, close_window, &img);
		mlx_loop(img.mlx);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	draw_fractal(t_data *img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
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
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	close_window(t_data *param)
{
	if (param->img)
		mlx_destroy_image(param->mlx, param->img);
	if (param->mlx_win)
		mlx_destroy_window(param->mlx, param->mlx_win);
	if (param->mlx)
		free(param->mlx);
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
