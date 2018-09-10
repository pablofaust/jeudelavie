#include "gol.h"

void		draw_cell(int y, int x, t_env *env)
{
	int		position;
	int		i;
	int		j;

	if (x == 0 && y == 0)
		position = 0 *env->screen_width * CELL_WIDTH + 0 * CELL_WIDTH;
	else
		position = y * env->screen_width * CELL_WIDTH + x * CELL_WIDTH;
	i = 0;
	while (i < CELL_WIDTH)
	{
		j = 0;
		while (j < CELL_WIDTH)
		{
			env->data_addr[position + i + j * env->screen_width] = 0xffffff;
			j++;
		}
		i++;
	}
}

void	draw_matrix(int **matrix, t_env *env)
{    
	int		y;
	int		x;

	read_matrix(matrix, env);
	y = 0;
	while (y < env->rows)
	{
		x = 0;
		while (x < env->cols)
		{
			if (matrix[y][x])
				draw_cell(y, x, env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
