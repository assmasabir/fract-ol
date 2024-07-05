#include "fractol.h"
int parse_julia_param(char* str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i])
    {
        if((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
        {
            if(str[i] == '.')
                count++;
            i++;
        }
        else
            return(1);
    }
    if((count == 0 && (str[i-1] != '-' && str[i-1] != '+')) || (count == 1 && (str[0] != '.' || i != 1)))
        return (0);
    else
        return(1);
}
double return_double(char *str, int i, double res, int count)
{
    while(str[i] && str[i] != '.')
    {
        res = res*10 + (str[i] - '0');
        i++;
    }
    if(str[i] == '.' && str[++i])
    {
        while(str[i])
        {
            res = res*10 + (str[i] - '0');
            i++;
            count++;
        }
        return(res/(pow(10, count)));
    }
    return(res);
}
double atod(char *str)
{
    int sign;
    int i;
    double res;
    int count;

    i = 0;
    res = 0;
    sign = 1;
    count = 0;
    if(str[i]=='-')
    {
        sign*=-1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    res = return_double(str, i, res, count);
    return(sign*res);
}

int ft_strcmp(char *str1, char*str2)
{
    int i;

    i = 0;
    while(str1[i] && str2[i])
    {
        if(str1[i]==str2[i])
        {
            i++;
        }
        else
            break;
    }
    return(str1[i]-str2[i]);
}
void print_error_and_exit(t_params *par)
{
    write(2, "mandelbrot: mandelbrot\n julia: julia <real> <imaginary>\n", 56);
    free(par);
    exit(EXIT_FAILURE);
}

int parse_input(int argc, char **argv, t_params *par)
{
    int i;

    i = 0;
    if (ft_strcmp(argv[1], "mandelbrot")==0 && argc==2)
        return(1);
    else if(ft_strcmp(argv[1], "julia")==0 && argv[2] && argv[3])
    {
        if(parse_julia_param(argv[2])==1 || parse_julia_param(argv[3])==1)
        {
            print_error_and_exit(par);
            return(0);
        }
        else
        {
            par->j1 = atod(argv[2]);
            par->j2 = atod(argv[3]);
            return(2);
        }
    }
    else
    {
        print_error_and_exit(par);
        return(0);
    }
}