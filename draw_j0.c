#include "gol.h"

void		draw_cell(int number, t_env *env)
{
	int		y;
	int		x;
	int		position;
	int		i;
	int		j;

	printf("number = %d\n", number);
	if (number == 0)
		position = 0 *env->screen_width * CELL_WIDTH + 0 * CELL_WIDTH;
	else
	{
		y = number / env->cols;
		if (y == 0)
			x = number;
		else
			x = number % (y * env->cols);
		position = y * env->screen_width * CELL_WIDTH + x * CELL_WIDTH;
	}
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

int		draw_initial_situation(t_coords **coords, t_env *env)
{      
	t_coords *begin;

	begin = *coords;
	while (begin)
	{
		if (begin->alive == 1)
		{
			draw_cell(begin->number, env);
		}
		begin = begin->next;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
