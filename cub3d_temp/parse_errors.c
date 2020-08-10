#include "cub3d.h"

void    parsing_error_messege(char c, t_parse *p_data)
{
    if (c == 'r')
    {
        p_data->parse_error = 1;
        printf ("Wrong map file input in Resolution parsing\n");
    }
}