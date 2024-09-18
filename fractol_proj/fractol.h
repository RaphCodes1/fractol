/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:33:42 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/18 17:48:57 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

// Colors
# define BLACK 0x000000   // RGB: (0, 0, 0)
# define WHITE 0xFFFFFF   // RGB: (255, 255, 255)
# define RED 0xFF0000     // RGB: (255, 0, 0)
# define GREEN 0x00FF00   // RGB: (0, 255, 0)
# define BLUE 0x0000FF    // RGB: (0, 0, 255)
# define YELLOW 0xFFFF00  // RGB: (255, 255, 0)
# define CYAN 0x00FFFF    // RGB: (0, 255, 255)
# define MAGENTA 0xFF00FF // RGB: (255, 0, 255)
# define GRAY 0x808080    // RGB: (128, 128, 128)
# define ORANGE 0xFFA500  // RGB: (255, 165, 0)
# define PURPLE 0x800080  // RGB: (128, 0, 128)

# define PSYCHEDELIC_PINK 0xFF00FF   // Bright Pink (255, 0, 255)
# define NEON_GREEN 0x39FF14         // Neon Green (57, 255, 20)
# define ELECTRIC_BLUE 0x7DF9FF      // Electric Blue (125, 249, 255)
# define VIVID_PURPLE 0x9400D3       // Vivid Purple (148, 0, 211)
# define HOT_PINK 0xFF69B4           // Hot Pink (255, 105, 180)
# define LIME_GREEN 0x32CD32         // Lime Green (50, 205, 50)
# define SUNSET_ORANGE 0xFF4500      // Sunset Orange (255, 69, 0)
# define BRIGHT_YELLOW 0xFFFF00      // Bright Yellow (255, 255, 0)
# define TURQUOISE 0x40E0D0          // Turquoise (64, 224, 208)
# define PSYCHEDELIC_RED 0xFF073A    // Psychedelic Red (255, 7, 58)
# define FLUORESCENT_PURPLE 0xFF00FF // Fluorescent Purple (255, 0, 255)
# define CYBER_YELLOW 0xFFD300       // Cyber Yellow (255, 211, 0)
# define VIBRANT_ORANGE 0xFF6347     // Vibrant Orange (255, 99, 71)
# define RADIOACTIVE_LIME 0xCCFF00   // Radioactive Lime (204, 255, 0)
# define ULTRA_MAGENTA 0xFF00AA      // Ultra Magenta (255, 0, 170)

typedef struct s_img
{
	void		*img_ptr;
	char		*pixel_str;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_con;
	void		*mlx_win;

	// hooks member variable
	t_img		img;
	t_complex	nums;

	double		esc_value; // hypotenuse
	int			iteration_def;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;

	int			x_mouse;
	int			y_mouse;
	int			freeze_julia;
}				t_fractal;

int				ft_strncmp(char *s1, char *s2, int len);
void			putstr_fd(char *s, int fd);
double			string_to_double(char *s);

void			fractal_init(t_fractal *fractal);

void			fractal_render(t_fractal *fractal);
double			map(double unscaled_num, double new_min, double new_max,
					double old_max);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z, char *s);

int				key_handler(int keysym, t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				julia_track(int x, int y, t_fractal *fractal);

#endif