#include "gol.h"

void		free_matrix(int **matrix, t_env *env)
{
	int		y;

	y = 0;
	read_matrix(matrix, env);
	while (y < env->rows)
	{
		printf("Jusqu'ici tout va bien\n");	
		if (matrix[y])
			free(&matrix[y]);
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
