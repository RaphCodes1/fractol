#include "../minilibx/mlx.h"
#include <stdio.h>

typedef struct s_complex
{
    double real;
    double i;
}   t_complex;
int main()
{
    // void *mlx_con;
    // void *mlx_win;

    // mlx_con = mlx_init();
    // mlx_win = mlx_new_window(mlx_con,500,500,"fractol");

    // mlx_loop(mlx_con);
    t_complex z;
    t_complex c;
    double tmp_real;
    int i;

    z.real = 0;
    z.i = 0;

    c.real = 0.25;
    c.i = 0.4;

    i = 0;
    while(i < 10)
    {
        //formula z = z^2 + c
        tmp_real = (z.real * z.real) - (z.i * z.i);

        z.i = 2 * z.real * z.i;
        z.real = tmp_real;

        //adding c value;
        z.real += c.real;
        z.i += c.i;

        printf("Iteration: %d, real:  %f, imaginary: %f\n",i,z.real,z.i);
        i++;
    }
}