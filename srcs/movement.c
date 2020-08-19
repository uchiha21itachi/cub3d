#include "../includes/cub3d.h"

void        move_up(t_game  *g_data)
{
    int xMap;
	int yMap;

        xMap = (int)((g_data->posX + g_data->dirX * g_data->moveSpeed));
		yMap = (int)g_data->posY + g_data->dirY * g_data->moveSpeed;
		// printf("first if map[%d][%d]\n", (int)g_data->posY, xMap);
		if(g_data->p_data->map[(int)(g_data->posY)][xMap] == 0)
		{
			g_data->posX += g_data->dirX * g_data->moveSpeed;
		}
		// printf("second if map[%d][%d]\n", yMap, (int)g_data->posX);
		if(g_data->p_data->map[yMap][(int)(g_data->posX)] == 0)
		{
			g_data->posY += g_data->dirY * g_data->moveSpeed;
		}
		render_map(g_data);
    	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}

void        move_down(t_game *g_data)
{
    int xMap;
	int yMap;


    xMap = (int)g_data->posX - g_data->dirX * g_data->moveSpeed;
    yMap = (int)g_data->posY - g_data->dirY * g_data->moveSpeed;
    
    // printf("num max for x [%d]\n", g_data->p_data->map_x[(int)g_data->posY]);
    // printf("y for x[y] - [%d]\n", (int)g_data->posY);
    // if (xMap >= g_data->p_data->map_x[(int)g_data->posY - 1] || 
        // g_data->posX >= g_data->p_data->map_x[(int)g_data->posY] -1)
            // printf("wrong map access\n");
    
    // printf("first if map[%d][%d]\n", (int)g_data->posY, xMap);
    if(g_data->p_data->map[(int)g_data->posY][xMap] == 0)
    {
        g_data->posX -= g_data->dirX * g_data->moveSpeed;
    }
    // printf("second if map[%d][%d]\n", yMap, (int)g_data->posX);

    if(g_data->p_data->map[yMap][(int)g_data->posX] == 0)
    {
        g_data->posY -= g_data->dirY * g_data->moveSpeed;
    }
	// printf("exit \n");

    render_map(g_data);
    	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}


void        move_right(t_game *g_data)
{
        int xMap;
    	int yMap;
        g_data->rotSpeed = 1.5708;
		double oldDirX = g_data->dirX;
		double tempx = g_data->dirX * cos(-g_data->rotSpeed) - g_data->dirY * sin(-g_data->rotSpeed);
      	double tempy = oldDirX * sin(-g_data->rotSpeed) + g_data->dirY * cos(-g_data->rotSpeed);
		xMap = (int)(g_data->posX + tempx * g_data->moveSpeed);
		yMap = (int)(g_data->posY + tempy * g_data->moveSpeed);
		
		// printf("first if map[%d][%d]\n", (int)g_data->posY, xMap);
		if(g_data->p_data->map[(int)g_data->posY][xMap] == 0)
			g_data->posX += tempx * g_data->moveSpeed;

		// printf("second if map[%d][%d]\n", yMap, (int)g_data->posX);
		if(g_data->p_data->map[yMap][(int)g_data->posX] == 0)
			g_data->posY += tempy * g_data->moveSpeed;
		render_map(g_data);
    	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}


void        move_left(t_game *g_data)
{
        int xMap;
    	int yMap;
        
        g_data->rotSpeed = -1.5708;
		double oldDirX = g_data->dirX;
		double tempx  = g_data->dirX * cos(g_data->rotSpeed) - g_data->dirY * sin(g_data->rotSpeed);
      	double tempy  = oldDirX * sin(g_data->rotSpeed) + g_data->dirY * cos(g_data->rotSpeed);
		xMap = (int)(g_data->posX - tempx * g_data->moveSpeed);
		yMap = (int)(g_data->posY - tempy * g_data->moveSpeed);


		// printf("first if map[%d][%d]\n", (int)g_data->posY, xMap);
		if(g_data->p_data->map[(int)g_data->posY][xMap] == 0) 
			g_data->posX -= tempx * g_data->moveSpeed;

		// printf("second if map[%d][%d]\n", yMap, (int)g_data->posX);
		if(g_data->p_data->map[yMap][(int)g_data->posX] == 0) 
			g_data->posY -= tempy * g_data->moveSpeed;
		render_map(g_data);
    	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}

void       rotate_right(t_game *g_data)
{
    double oldDirX = g_data->dirX;
    g_data->dirX = g_data->dirX * cos(-g_data->rotSpeedX) - g_data->dirY * sin(-g_data->rotSpeedX);
    g_data->dirY = oldDirX * sin(-g_data->rotSpeedX) + g_data->dirY * cos(-g_data->rotSpeedX);
    double oldPlaneX = g_data->planeX;
    g_data->planeX = g_data->planeX * cos(-g_data->rotSpeedX) - g_data->planeY * sin(-g_data->rotSpeedX);
    g_data->planeY = oldPlaneX * sin(-g_data->rotSpeedX) + g_data->planeY * cos(-g_data->rotSpeedX);
	render_map(g_data);
    	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}

void        rotate_left(t_game *g_data)
{
     double oldDirX = g_data->dirX;
      g_data->dirX = g_data->dirX * cos(g_data->rotSpeedX) - g_data->dirY * sin(g_data->rotSpeedX);
      g_data->dirY = oldDirX * sin(g_data->rotSpeedX) + g_data->dirY * cos(g_data->rotSpeedX);
      double oldPlaneX = g_data->planeX;
      g_data->planeX = g_data->planeX * cos(g_data->rotSpeedX) - g_data->planeY * sin(g_data->rotSpeedX);
      g_data->planeY = oldPlaneX * sin(g_data->rotSpeedX) + g_data->planeY * cos(g_data->rotSpeedX);
	  render_map(g_data);
    	mlx_put_image_to_window(g_data->mlx->mlx, g_data->mlx->mlx_win, g_data->img->img, 0, 0);

}