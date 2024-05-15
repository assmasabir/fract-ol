#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct param
{
    double facteur;
    int bits_per_pixel;
    int line_len;
    int endian;
    void    *img;
    void    *connection;
    void    *window;
    char    *address; 
} t_param;

void somme(double *reel, double *img, double reel2, double img2)
{
    *reel = *reel + reel2;
    *img = (*img) + img2;
}
void produit(double *reel, double *img, double reel2, double img2)
{
    double temp; 
    temp = *reel;
    *reel = temp * reel2 - (*img) * img2;
    *img = img2 * temp + (*img) * reel2;
}

double  scale(double x, double a, double b, double min, double max)
{
    return (((b - a) * (x - min) / (max - min)) + a);
}

void my_mlx_pixel_put(char *address, int bpp, int line_lengh, int i, int j, int color)
{
    char  *temp;

    temp = address + j * line_lengh + (i * bpp / 8);
    *(int *)temp = color;
}

int    print_color(double i, double j, t_param *tpar, int k, int b, int display)
{
    // double x;
    // double y;

    // x = scale(i, -2, 2, 0, 800);
    // y = scale(j, 2, -2, 0, 800);
    if (i * i + j * j < 4)
    {
        my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0x383532);
            return(0);
    }
    else
    {
        if(display==5)
        {
            my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0xb57d47);
            return(1);
        }
        else if(display==10)
        {
            my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0xb57d47);
            return(1);
        }
        else if(display==20)
        {
            my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0xab7037);
            return(1);
        }
        else if(display==30)
        {
            my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0xab6826);
            return(1);
        }
        else if(display==40)
        {
            my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0xb56618);
            return(1);
        }
        else if(display==50)
        {
            my_mlx_pixel_put(tpar->address, tpar->bits_per_pixel, tpar->line_len, k, b, 0xdb8025);
            return(1);
        }
        return(1);
    }
}
void mandelbrot_equation(t_param *tpar)
{
    double z1;
    double z2;
    double k;
    double j;
    double index;
    double  k_scaled;
    double  j_scaled;
    int     display;

    z1 = 0;
    z2 = 0;
    index = 0;
    k = 0;
    display =0;
    while( k != 800)
    {
        j = 0;
        while(j != 800)
        {
            index = 0;
            z1 = 0;
            z2 = 0;
            k_scaled = scale(k, -2, 2, 0, 800)*1.5; //(tpar->facteur);
            j_scaled = scale(j, 2, -2, 0, 800)*1.5; //(tpar->facteur);
            while(index <= 50)
            {
                display =0;
                produit(&z1,&z2,z1, z2);
                somme(&z1,&z2, k_scaled, j_scaled);
                if(index<=5)
                    display=5;
                else if(index<=10)
                    display=10;
                else if(index<=20)
                    display = 20;
                else if(index<=30)
                    display = 30;
                else if(index<=40)
                    display = 40;
                else if(index<=50)
                    display =50;
                if(print_color(z1, z2,tpar, k, j, display)==0)
                    index++;
                else
                    break;
            }
            j++;
        }
        k++;
    }
    mlx_put_image_to_window(tpar->connection, tpar->window,tpar->img, 0, 0);
}

int mouse_handler(int button, int x, int y, t_param *tpar)
{
     
   
    (void)x;
    (void)y;
    
        if(button==4)
        {
            tpar->facteur = tpar->facteur*0.9;
        }
        else if(button==5)
        {
            tpar->facteur = tpar->facteur*1.1;
        }
        //tpar->address = mlx_get_data_addr(tpar->img, &(tpar->bits_per_pixel), &(tpar->line_len), &(tpar->endian));
        mandelbrot_equation(tpar);
        // mlx_put_image_to_window(tpar->connection, tpar->window, tpar->img, 0, 0);
    return (0);
}

int main()
{
    t_param *tpar;
    tpar = malloc(sizeof(t_param));

     tpar->facteur = 1;
    // void *connection;
    // void *window;
    // void *img;
    // int bits_per_pixel;
    // int line_len;
    // int endian;


    
    tpar->connection = mlx_init();
    if(!tpar->connection)
        return (1);
    tpar->window = mlx_new_window(tpar->connection,800, 800, "fract-ol");
    tpar->img = mlx_new_image(tpar->connection, 800, 800);
    //char *address;
    tpar->address = mlx_get_data_addr(tpar->img, &(tpar->bits_per_pixel), &(tpar->line_len), &(tpar->endian));
    mandelbrot_equation(tpar);
    // mlx_put_image_to_window(tpar->connection, tpar->window,tpar->img, 0, 0);
    mlx_mouse_hook(tpar->window, mouse_handler, tpar->connection);
    mlx_loop(tpar->connection);
}