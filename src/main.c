/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:07 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/30 23:42:12 by okamotoyayo      ###   ########.fr       */
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
		set_fractal_type(&img, argv[1]);
		init_data(&img);
		draw_fractal(&img);
		mlx_key_hook(img.mlx_win, key_event, &img);
		mlx_mouse_hook(img.mlx_win, mouse_event, &img);
		mlx_hook(img.mlx_win, 17, 0, close_window, &img);
		mlx_loop(img.mlx);
	}
	else
	{
		ft_putstr_fd("Error: Usage:./fractol mandelbrot ./fractol julia\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	set_fractal_type(t_data *img, char *argv)
{
	img->name = argv;
}

void	draw_fractal(t_data *img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (ft_strncmp(img->name, "mandelbrot", 10) == 0)
		render_mandelbrot(img);
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
