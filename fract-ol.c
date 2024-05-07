#include "/home/techwhimsy/Desktop/fract-ol/minilibx-linux/mlx.h"
#include <stdio.h>

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
void    print_color(int i, int j, void *connection, void *window, void *img, char *addr, int bpp, int line_len)
{
    double x;
    double y;

    x = scale(i, -2, 2, 0, 800);
    y = scale(j, 2, -2, 0, 800);
    if (x * x + y * y < 4)
        my_mlx_pixel_put(addr, bpp, line_len, i, j, 0xfcc603);
    else
        my_mlx_pixel_put(addr, bpp, line_len, i, j, 0xffffff);
}

int main()
{
    void *connection;
    void *window;
    void *img;
    int i;
    int j;
    int bits_per_pixel;
    int line_len;
    int endian;

    
    j = 0;
    connection = mlx_init();
    if(!connection)
        return (1);
    window = mlx_new_window(connection,800, 800, "fract-ol");
    // while(j<900)
    // {
    //     i = 300;
    //     while(i<600)
    //     {
    //         mlx_pixel_put(connection, window, i, j, 0xfc3d03);
    //         i++;
    //     }
    //     j++;
    // }
    img = mlx_new_image(connection, 800, 800);
    char *address = mlx_get_data_addr(img, &bits_per_pixel, &line_len, &endian);
    printf("%d | %d | %d | %p\n", bits_per_pixel, line_len, endian, address);
    while (j < 800)
    {
        i = 0;
        while (i < 800)
        {
            print_color(i, j, connection, window, img, address, bits_per_pixel, line_len);
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(connection, window,img, 0, 0);
    mlx_loop(connection);
}