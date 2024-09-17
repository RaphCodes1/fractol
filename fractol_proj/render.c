#include "fractol.h"
#include "../minilibx/mlx.h"


static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixel_str + offset) = color;
}

static void what_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if(!ft_strncmp(fractal->name,"julia",5))
    {   
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;
    }
}

static double map_out(int val, char *s, char coord)
{   
    double holder;
    if(coord == 'y')
    {
        if(!ft_strncmp(s,"burning ship",12))
            holder = map(val, -2, +2, HEIGHT);
        else
            holder = map(val, -2, +2, HEIGHT);
    }
    else
        holder = map(val, -2, +2, WIDTH);
    return (holder);
}

static void handle_pixel(int x,int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    z.x = (map_out(x,fractal->name,'x') * fractal->zoom) + fractal->shift_x;
    z.y = (map_out(y,fractal->name,'y') * fractal->zoom) + fractal->shift_y;
    what_fractal(&z,&c, fractal);
    while(i < fractal->iteration_def)
    {   
        //formula z = z^2 + c
        z = sum_complex(square_complex(z,fractal->name),c);
        if((z.x * z.x) + (z.y * z.y) > fractal->esc_value)
        {   
            color = map(i, BLACK, FLUORESCENT_PURPLE , fractal->iteration_def);
            my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, BLACK);
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while(++y < HEIGHT)
    {   
        x = -1;
        while(++x < WIDTH)
        {
            handle_pixel(x,y,fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win, 
                            fractal->img.img_ptr, 
                            0, 0);
}
