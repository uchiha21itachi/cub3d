#include "../includes/cub3d.h"

void	move_up(t_game *g_data)
{
	int			xmap;
	int			ymap;

	xmap = (int)((g_data->posX + g_data->dirX * g_data->moveSpeed));
	ymap = (int)g_data->posY + g_data->dirY * g_data->moveSpeed;
	if (g_data->p_data->map[(int)(g_data->posY)][xmap] == 0)
		g_data->posX += g_data->dirX * g_data->moveSpeed;
	if (g_data->p_data->map[ymap][(int)(g_data->posX)] == 0)
		g_data->posY += g_data->dirY * g_data->moveSpeed;
	render_map(g_data);
}

void	move_down(t_game *g_data)
{
	int			xmap;
	int			ymap;

	xmap = (int)g_data->posX - g_data->dirX * g_data->moveSpeed;
	ymap = (int)g_data->posY - g_data->dirY * g_data->moveSpeed;
	if (g_data->p_data->map[(int)g_data->posY][xmap] == 0)
		g_data->posX -= g_data->dirX * g_data->moveSpeed;
	if (g_data->p_data->map[ymap][(int)g_data->posX] == 0)
		g_data->posY -= g_data->dirY * g_data->moveSpeed;
	render_map(g_data);
}

void	move_right(t_game *g_data)
{
	int			xmap;
	int			ymap;
	double		olddirx;
	double		tempx;
	double		tempy;

	g_data->rotSpeed = 1.5708;
	olddirx = g_data->dirX;
	tempx = g_data->dirX * cos(-g_data->rotSpeed) - g_data->dirY *
		sin(-g_data->rotSpeed);
	tempy = olddirx * sin(-g_data->rotSpeed) + g_data->dirY *
		cos(-g_data->rotSpeed);
	xmap = (int)(g_data->posX + tempx * g_data->moveSpeed);
	ymap = (int)(g_data->posY + tempy * g_data->moveSpeed);
	if (g_data->p_data->map[(int)g_data->posY][xmap] == 0)
		g_data->posX += tempx * g_data->moveSpeed;
	if (g_data->p_data->map[ymap][(int)g_data->posX] == 0)
		g_data->posY += tempy * g_data->moveSpeed;
	render_map(g_data);
}

void	move_left(t_game *g_data)
{
	int			xmap;
	int			ymap;
	double		olddirx;
	double		tempx;
	double		tempy;

	g_data->rotSpeed = -1.5708;
	olddirx = g_data->dirX;
	tempx = g_data->dirX * cos(g_data->rotSpeed) - g_data->dirY *
		sin(g_data->rotSpeed);
	tempy = olddirx * sin(g_data->rotSpeed) + g_data->dirY *
		cos(g_data->rotSpeed);
	xmap = (int)(g_data->posX - tempx * g_data->moveSpeed);
	ymap = (int)(g_data->posY - tempy * g_data->moveSpeed);
	if (g_data->p_data->map[(int)g_data->posY][xmap] == 0)
		g_data->posX -= tempx * g_data->moveSpeed;
	if (g_data->p_data->map[ymap][(int)g_data->posX] == 0)
		g_data->posY -= tempy * g_data->moveSpeed;
	render_map(g_data);
}
