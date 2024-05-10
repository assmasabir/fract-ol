#include <mlx.h>
#include <stdio.h>
#include "fract_ol.h"
double  scale(double x, double a, double b, double min, double max)
{
    return (((b - a) * (x - min) / (max - min)) + a);
}

void my_mlx_pixel_put(char *address, int bpp, int line_lengh, int i, int j, int color)
{
    char  *temp;

    temp = address + j * line_lengh + i * bpp/8 ;
    *(int *)temp = color;
}
int    print_color(double i, double j, char *addr, int bpp, int line_len, int k, int b)
{
    // double x;
    // double y;

    // x = scale(i, -2, 2, 0, 800);
    // y = scale(j, 2, -2, 0, 800);
    if (i * i + j * j < 4)
        {
            my_mlx_pixel_put(addr, bpp, line_len, k, b, 0xfcc603);
            return(0);
        }
    else
        {
            my_mlx_pixel_put(addr, bpp, line_len, k, b, 0xffffff);
            return(1);
        }
}

int main()
{
    void *connection;
    void *window;
    void *img;
    int bits_per_pixel;
    int line_len;
    int endian;

    
    connection = mlx_init();
    if(!connection)
        return (1);
    window = mlx_new_window(connection,800, 800, "fract-ol");
    img = mlx_new_image(connection, 800, 800);
    char *address = mlx_get_data_addr(img, &bits_per_pixel, &line_len, &endian);
    mandelbrot_equation(800, 800,address, bits_per_pixel, line_len);
    mlx_put_image_to_window(connection, window,img, 0, 0);
    mlx_loop(connection);
}