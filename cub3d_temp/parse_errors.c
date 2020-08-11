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