#include "fractol.h"

double map(double unscaled_num, double new_min, double new_max, 
            double old_max)
{
    return (new_max - new_min) * (unscaled_num - 0.0) / (old_max - 0.0) + new_min;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;
    
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex square_complex(t_complex z)
{
    t_complex result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}

double string_to_double(char *s)
{   
    int conv;
    long int_part;
    double point_part;
    double power;

    int_part = 0;
    point_part = 0;
    power = 1;
    conv = 1;
    while(*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    while(*s == '+' || *s == '-')
        if(*s++ == '-')
            conv *= -1;
    while(*s != '.' && *s)
        int_part = int_part * 10 + *s++ - '0';
    if('.' == *s)
        s++;
    while(*s)
    {
        power /= 10;
        point_part = point_part + (*s++ - '0') * power; 
    }
    return((int_part + point_part) * conv);
}
