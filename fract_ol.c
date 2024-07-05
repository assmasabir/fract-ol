
#include "fractol.h"


int on_destroy(t_params *par)
{
    mlx_destroy_window(par->connection, par->window);
    mlx_destroy_image(par->connection, par->img);
    mlx_destroy_display(par->connection);
    free(par->connection);
    free(par);
    exit(0);
}

int  escape(int keycode, t_params *par)
{
    if(keycode == 65307)
        on_destroy(par);
    return 1;
}
void fill_window(t_params *par, int check)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if(check==0)
        return;
    while(j < 1000)
    {
        i=0;
        while(i <1000)
        {
            if(check==1)
                mandelbrot(par, i, j);
            if(check==2)
                julia(par, i, j);
            i++;
        }
        j++;
    }
}
int main (int argc, char **argv)
{
    t_params *par;
    int j;
    par = malloc(sizeof(t_params));
    j = parse_input(argc, argv, par);
    par->facteur =1;
    par->connection = mlx_init();
    par->window = mlx_new_window(par->connection, 1000,1000, "fract-OL");
    par->img = mlx_new_image(par->connection, 1000, 1000);
    par->address = mlx_get_data_addr(par->img, &(par->bits_per_pixel), &(par->size_line), &(par->endian));
    fill_window(par, parse_input(argc, argv, par));
    mlx_put_image_to_window(par->connection, par->window, par->img, 0, 0);
    mlx_mouse_hook(par->window, mouse_hundler, par);
    mlx_hook(par->window, 17, 1, on_destroy, par );
    mlx_key_hook(par->window, escape, par);
    mlx_loop(par->connection);
}