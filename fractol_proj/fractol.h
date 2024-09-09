#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"

# define ERROR_MSG "Please enter: \n\" ./fractol mandelbrot \" \nor \n\" ./fractol julia <num1> <num2> \" \n"

typedef struct s_img
{
    void *img_ptr;
    char *pixel_str;
    int bpp;
    int endian;
    int line_len;
}   t_img;

typedef struct s_fractal
{
    void *mlx_con;
    void *mlx_win;
    
    //hooks member variable
    t_img img;
}   t_fractal;

int ft_strncmp(char *s1, char *s2, int len);
void putstr_fd(char *s, int fd);


#endif