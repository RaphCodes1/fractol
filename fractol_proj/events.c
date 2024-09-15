#include "fractol.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_con,fractal->img.img_ptr);
    mlx_clear_window(fractal->mlx_con,fractal->mlx_win);
    free(fractal->mlx_con);
    exit(EXIT_SUCCESS);
}

int key_handler(int keysym, t_fractal *fractal)
{   
    // printf("%d\n",keysym);
    if(keysym == 53)
        close_handler(fractal);
    else if(keysym == 126) //Up Key
        fractal->shift_y += (0.5 * fractal->zoom);
    else if(keysym == 125) //Down Key
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if(keysym == 123) //Left key
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if(keysym == 124) //Right Key
        fractal->shift_x += (0.5 * fractal->zoom);
    else if(keysym == 24) //Plus Key
        fractal->iteration_def += 2;
    else if(keysym == 27) //Minus Key
        fractal->iteration_def -= 2;
    fractal_render(fractal);
    return 0;
}

int mouse_handler(int button,int x, int y, t_fractal *fractal)
{
    //get mouse coordinates 
    // mlx_mouse_get_pos(fractal->mlx_win,&fractal->x_mouse,&fractal->y_mouse);
    // printf("x mouse: %d, y mouse: %d\n",fractal->x_mouse, fractal->y_mouse);
    x = x * 1;
    y = y * 1;
    if(button == 4)
    {
        fractal->zoom *= 0.90;
    } // zoom out;
    else if(button == 5)
    {
        fractal->zoom *= 1.10;
    } // zoom in;
    fractal_render(fractal);
    return 0;
}

int julia_track(int x, int y, t_fractal *fractal)
{
    if(!ft_strncmp(fractal->name,"julia",5))
    {
        fractal->julia_x = (map(x,-2,2,HEIGHT) * fractal->zoom) + fractal->shift_x;
        fractal->julia_y = (map(y,-2,+2,HEIGHT) * fractal->zoom) + fractal->shift_y;
        fractal_render(fractal);
    }
    return (0);
}