/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:12:53 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/05/30 04:24:04 by okamotoyayo      ###   ########.fr       */
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
	double	zoom;
}	t_data;

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 100

# define ESC_KEY 0xFF1B
# define MOUSE_DOWN 4
# define MOUSE_UP 5

//main.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		calc_mandelbrot(double x0, double y0);
int		close_window(t_data *param);
void	draw_fractal(t_data *img);
void	render_mandelbrot(t_data *img);

// mouse_and_key.c
int		key_event(int keycode, t_data *param);
int		mouse_event(int button, int x, int y, t_data *param);

// init.c
void	init_data(t_data *data);

#endif