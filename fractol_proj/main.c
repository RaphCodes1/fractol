#include "fractol.h"

int main(int ac, char **av)
{   
    t_fractal fractal;

    if((ac == 2 && !ft_strncmp(av[1],"mandelbrot",10)) ||
    (ac == 4 && !ft_strncmp(av[1],"julia",5)) ||
    (ac == 2 && !ft_strncmp(av[1],"burning ship",12)))
    {   
        fractal.name = av[1];
        if(!ft_strncmp(av[1],"julia",5))
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
        putstr_fd(ERROR_MSG,2);
        exit(EXIT_FAILURE);
    }
}