/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:12:53 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/24 16:39:04 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}	t_data;

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 100

# define ESC_KEY 0xFF1B

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		calc_mandelbrot(double x0, double y0);
int		close_window(t_data *param);
int		key_event(int keycode, t_data *param);

#endif