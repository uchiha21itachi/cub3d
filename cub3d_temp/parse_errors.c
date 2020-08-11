#include "cub3d.h"

void    parsing_error_messege(char c, t_parse *p_data)
{
    if (c == 'r')
    {
        p_data->parse_error = 1;
        printf ("Wrong map file input in Resolution parsing\n");
    }
    else if (c == 'd')
    {
        p_data->parse_error = 1;
        printf ("Error- Already parsed line is again in file\n");
    }
    else if (c == 'c')
    {
        p_data->parse_error = 1;
        printf ("Error- Wrong map file input in colour parsing\n\n");
    }
}

void    malloc_error_messege(char c, t_parse *p_data)
{
    if (c == 'm')
    {
        p_data->parse_error = 2;
        printf ("Error -- while malloc\n Exiting program\n");
    }
}

void    print_data_temp(t_parse *p_data)
{
    int i;

    i = 0;
    printf("temp counter is - %d \n", p_data->temp_counter);
    while (i < p_data->temp_counter)
    {
        printf("length of x[%d] = %d\n", i, p_data->map_x[i]);
        i++;
    }
    printf("resx - [%d] resy - [%d], parse error - [%d]\n", p_data->res_x, p_data->res_y, p_data->parse_error);
    printf("floor color - [%d] ceiling color - [%d], parse error - [%d]\n", p_data->floor_color, p_data->ceiling_color, p_data->parse_error);
}