#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <time.h>
# define WIDTH 800
# define HEIGHT 800
int main()
{   
    void *mlx_connect;
    void *mlx_window;
    int x;
    int y;
    int random_val;

    srand(time(NULL));
    x = HEIGHT * 0.1;
    mlx_connect = mlx_init();
    mlx_window = mlx_new_window(mlx_connect,WIDTH, HEIGHT, "Hello there!");
    while(x < HEIGHT * 0.9)
    {   
        y = WIDTH * 0.1;
        random_val = rand() % 0x100000;
        while(y < WIDTH * 0.9)
            mlx_pixel_put(mlx_connect, mlx_window, y++,x,random_val);
        x++;
    }
    mlx_string_put(mlx_connect,mlx_window,WIDTH * 0.41, HEIGHT * 0.95,0xFFFFFF,"Welcome to the Matrix");

    mlx_loop(mlx_connect);

}