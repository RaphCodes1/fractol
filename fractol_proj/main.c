#include "fractol.h"

typedef struct s_complex
{
    double real;
    double i;
}   t_complex;

int main(int ac, char **av)
{   
    t_fractal fractal;
    if((ac == 2 && !ft_strncmp(av[1],"mandelbrot",10)) ||
    (ac == 4 && !ft_strncmp(av[1],"julia",5)))
    {
        putstr_fd("Welcome!\n",1);
    }
    else
    {
        putstr_fd(ERROR_MSG,2);
        exit(EXIT_FAILURE);
    }
}