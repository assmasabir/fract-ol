#include <mlx.h>
#include <stdio.h>

double  scale(double x, double a, double b, double min, double max)
{
    return (((b - a) * (x - min) / (max - min)) + a);
}

void    print_color(int i, int j, void *connection, void *window)
{
    double x;
    double y;
    x = scale(i, -2, 2, 0, 800);
    y = scale(j, 2, -2, 0, 800);
    if (x * x + y * y < 4)
    {
        mlx_pixel_put(connection, window, i, j, 0xfcc603);
    }
    else
        mlx_pixel_put(connection, window, i, j, 0xffffff);
}

int main()
{
    void *connection;
    void *window;
    int i;
    int j;

    
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

    while (j < 800)
    {
        i = 0;
        while (i < 800)
        {
            print_color(i, j, connection, window);
            i++;
        }
        j++;
    }
    mlx_loop(connection);


}