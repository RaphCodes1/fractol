/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:17:42 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/18 17:50:22 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_msg(void)
{
	putstr_fd("Please enter: \n\" ./fractol mandelbrot \"\n", 2);
	putstr_fd("or\n\"./fractol julia <num1> <num2> \"\n ", 2);
	putstr_fd("or\n./fractol \"burning ship\" \n", 2);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)) || (ac == 2 && !ft_strncmp(av[1],
				"burning ship", 12)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractal.julia_x = string_to_double(av[2]);
			fractal.julia_y = string_to_double(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_con);
	}
	else
	{
		error_msg();
		exit(EXIT_FAILURE);
	}
}
