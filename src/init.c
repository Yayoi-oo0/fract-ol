/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:15:36 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/09/14 18:41:30 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		exit(EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	if (!data->mlx_win)
	{
		ft_putstr_fd("Error: mlx_new_window failed\n", 2);
		exit(EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_putstr_fd("Error: mlx_new_image failed\n", 2);
		exit(EXIT_FAILURE);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->zoom = 300.0;
}
