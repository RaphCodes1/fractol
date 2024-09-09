#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_complex
{
    double real;
    double i;
}   t_complex;

int main()
{
    t_complex z;
    t_complex c;
    double real_tmp;
    int i;

    z.real = 0;
    z.i = 0;
    c.real = 0.251;
    c.i = 0.476;
    i = 0;
    while(i < 42)
    {
        //formula z = z^2 + c;
        real_tmp = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.i * z.real;
        z.real = real_tmp;

        z.real += c.real;
        z.i += c.i;
        printf("Iter: %d Real: %f I: %f\n",i++,z.real,z.i);
    }    
}