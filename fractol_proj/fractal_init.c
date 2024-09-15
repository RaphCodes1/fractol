#include "fractol.h"
#include "../minilibx/mlx.h"

static void error_malloc(void)
{
    perror("Problem with malloc");
    exit(EXIT_FAILURE);
}

static void data_init(t_fractal *fractal)
{
    fractal->esc_value = 4; // hypotenous;
    fractal->iteration_def = 42;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->zoom = 1.0;
    fractal->x_mouse = 0;
    fractal->y_mouse = 0;
}

static void events_init(t_fractal *fractal)
{   
    //KeyPress
    mlx_hook(fractal->mlx_win,02,(1L<<0),key_handler,fractal);
    //ButtonPress //Mouse
    mlx_hook(fractal->mlx_win,04,(1L<<2),mouse_handler,fractal);
    //DestroyNotify
    mlx_hook(fractal->mlx_win,17,(1L<<17),close_handler,fractal);
    //For Julia
    mlx_hook(fractal->mlx_win,06,(1L<<06),julia_track,fractal);
}
void fractal_init(t_fractal *fractal)
{
    fractal->mlx_con = mlx_init();
    if(fractal->mlx_con == NULL)
        error_malloc();

    fractal->mlx_win = mlx_new_window(fractal->mlx_con, WIDTH, HEIGHT, fractal->name);
    if(fractal->mlx_win == NULL)
    {
        mlx_destroy_window(fractal->mlx_con,fractal->mlx_win);
        free(fractal->mlx_con);
        error_malloc();
    }

    fractal->img.img_ptr = mlx_new_image(fractal->mlx_con,WIDTH,HEIGHT);
    if(fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_con,fractal->mlx_win);
        mlx_destroy_image(fractal->mlx_con,fractal->img.img_ptr);
        free(fractal->mlx_con);
        error_malloc();
    }

    fractal->img.pixel_str = mlx_get_data_addr(fractal->img.img_ptr,&fractal->img.bpp,
                                                &fractal->img.line_len,
                                                &fractal->img.endian);
    
    events_init(fractal);
    data_init(fractal);
}