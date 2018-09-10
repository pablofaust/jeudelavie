#include "gol.h"

void		free_matrix(int **matrix, t_env *env)
{
	int		y;
	int		i;
	int		allocated;

	y = 0;
	allocated = 0;
	while (y < env->rows)
	{
		i = 0;
		while (i < env->cols)
		{
			if (matrix[y][i])
				allocated = 1;
			i++;
		}
		if (allocated)
			free(matrix[y]);
		y++;
	}
}

void		free_all(t_env *env)
{
	if (env->matrix1)
		free_matrix(env->matrix1, env);
	if (env->matrix2)
		free_matrix(env->matrix2, env);
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		free_all(env);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void		events_listener(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
}
