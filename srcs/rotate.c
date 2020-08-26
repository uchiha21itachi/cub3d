#include "../includes/cub3d.h"

void	rotate_right(t_game *g_data)
{
	double		olddirx;
	double		oldplanex;

	olddirx = g_data->dirX;
	g_data->dirX = g_data->dirX * cos(-g_data->rotSpeedX) - g_data->dirY *
		sin(-g_data->rotSpeedX);
	g_data->dirY = olddirx * sin(-g_data->rotSpeedX) + g_data->dirY *
		cos(-g_data->rotSpeedX);
	oldplanex = g_data->planeX;
	g_data->planeX = g_data->planeX * cos(-g_data->rotSpeedX) -
		g_data->planeY * sin(-g_data->rotSpeedX);
	g_data->planeY = oldplanex * sin(-g_data->rotSpeedX) +
		g_data->planeY * cos(-g_data->rotSpeedX);
	render_map(g_data);
}

void	rotate_left(t_game *g_data)
{
	double		olddirx;
	double		oldplanex;

	olddirx = g_data->dirX;
	g_data->dirX = g_data->dirX * cos(g_data->rotSpeedX) -
		g_data->dirY * sin(g_data->rotSpeedX);
	g_data->dirY = olddirx * sin(g_data->rotSpeedX) +
		g_data->dirY * cos(g_data->rotSpeedX);
	oldplanex = g_data->planeX;
	g_data->planeX = g_data->planeX * cos(g_data->rotSpeedX) -
		g_data->planeY * sin(g_data->rotSpeedX);
	g_data->planeY = oldplanex * sin(g_data->rotSpeedX) +
		g_data->planeY * cos(g_data->rotSpeedX);
	render_map(g_data);
}
