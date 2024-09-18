/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:14:46 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/18 17:42:14 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_con, fractal->img.img_ptr);
	mlx_clear_window(fractal->mlx_con, fractal->mlx_win);
	free(fractal->mlx_con);
	exit(EXIT_SUCCESS);
}

static void	freeze_julia(int keysym, t_fractal *fractal)
{
	if (keysym == 15)
	{
		if (fractal->freeze_julia == -1)
			fractal->freeze_julia = 1;
		else
			fractal->freeze_julia = -1;
	}
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
		close_handler(fractal);
	else if (keysym == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 24)
		fractal->iteration_def += 2;
	else if (keysym == 27)
		fractal->iteration_def -= 2;
	else if (keysym == 49)
	{
		fractal->shift_x = 0.0;
		fractal->shift_y = 0.0;
		fractal->nums.x = map(400, -2, +2, WIDTH);
		fractal->nums.y = map(400, -2, +2, HEIGHT);
		fractal->zoom = 1.0;
	}
	freeze_julia(keysym, fractal);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	x_m;
	double	y_m;
	double	new_x;
	double	new_y;

	mlx_mouse_get_pos(fractal->mlx_win, &fractal->x_mouse, &fractal->y_mouse);
	x = x * 1;
	y = y * 1;
	x_m = (map(fractal->x_mouse, -2, 2, WIDTH) * fractal->zoom)
		+ fractal->shift_x;
	y_m = (map(fractal->y_mouse, -2, 2, HEIGHT) * fractal->zoom)
		+ fractal->shift_y;
	if (button == 4 || button == 1)
		fractal->zoom /= 2;
	else if (button == 5 || button == 2)
		fractal->zoom *= 2;
	new_x = (map(fractal->x_mouse, -2, 2, WIDTH) * fractal->zoom)
		+ fractal->shift_x;
	new_y = (map(fractal->y_mouse, -2, 2, HEIGHT) * fractal->zoom)
		+ fractal->shift_y;
	fractal->shift_x += x_m - new_x;
	fractal->shift_y += y_m - new_y;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (fractal->freeze_julia == 1)
	{
		if (!ft_strncmp(fractal->name, "julia", 5))
		{
			fractal->julia_x = (map(x, -2, 2, HEIGHT) * fractal->zoom)
				+ fractal->shift_x;
			fractal->julia_y = (map(y, -2, +2, HEIGHT) * fractal->zoom)
				+ fractal->shift_y;
			fractal_render(fractal);
		}
	}
	else if (fractal->freeze_julia == -1)
	{
		fractal->julia_x = fractal->julia_x;
		fractal->julia_y = fractal->julia_y;
		fractal_render(fractal);
	}
	return (0);
}
