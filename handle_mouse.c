#include "fractol.h"

int mouse_hundler(int button, int x, int y, t_params *par)
{
    int i;
    int j;
    (void)x;
    (void)y;
    i = 0;
    j = 0;
    if(button==4)
        par->facteur *=0.95;
    else if(button==5)
        par->facteur *=1.1;
    while(j < 1000)
    {
        i=0;
        while(i <1000)
        {
            equation(par, i, j);
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(par->connection, par->window, par->img, 0, 0);
    return (0);
}