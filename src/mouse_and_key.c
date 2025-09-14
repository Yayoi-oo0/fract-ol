/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:25:40 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/09/14 18:52:53 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event(int keycode, t_data *param)
{
	if (keycode == ESC_KEY)
		close_window(param);
	else if (keycode == UP_KEY)
		param->offset_y -= param->zoom * 0.1;
	else if (keycode == DOWN_KEY)
		param->offset_y += param->zoom * 0.1;
	else if (keycode == LEFT_KEY)
		param->offset_x -= param->zoom * 0.1;
	else if (keycode == RIGHT_KEY)
		param->offset_x += param->zoom * 0.1;
	draw_fractal(param);
	return (0);
}

int	mouse_event(int button, int x, int y, t_data *param)
{
	(void)x;
	(void)y;
	if (button == MOUSE_DOWN)
		param->zoom *= 1.05;
	else if (button == MOUSE_UP)
		param->zoom *= 0.95;
	draw_fractal(param);
	return (0);
}
