#include "gol.h"

void		apply_rules(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	read_matrix(env->matrix1, env);
	while (y < env->rows)
	{
		x = 0;
		while (x < env->cols)
		{
			if (y == 0 && x == 0)
			{
				if (check_up_left_corner(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				else if (!(check_up_left_corner(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (y == 0 && x == env->cols - 1)
			{
				if (check_up_right_corner(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				else if (!(check_up_right_corner(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (y == env->rows - 1 && x % env->cols == 0)
			{
				if (check_down_left_corner(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				else if (!(check_down_left_corner(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (y == env->rows - 1 && x == env->cols * env->rows - 1)
			{
				if (check_down_right_corner(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				else if (!(check_down_right_corner(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (y == 0)
			{
				if (check_up_border(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				if (!(check_up_border(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (y == env->rows - 1)
			{
				if (check_down_border(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				if (!(check_down_border(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (x % env->cols == 0)
			{
				if (check_left_border(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				if (!(check_left_border(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else if (x % env->cols == env->cols - 1)
			{
				if (check_right_border(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				if (!(check_right_border(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			else
			{
				if (check_center(y, x, env) && env->matrix2[y][x] == 0)
					env->matrix2[y][x] = 1;
				else if (!(check_center(y, x, env)) && env->matrix2[y][x] == 1)
					env->matrix2[y][x] = 0;
			}
			x++;
		}
		y++;
	}
}

int			life(t_env *env)
{
	int			i;
	int			**matrix2;

	matrix2 = NULL;
	if (!(create_matrix(env, &matrix2)))
		return (0);
	env->matrix2 = matrix2;
	i = 1;
	while (i < TURNS)
	{
		draw_matrix(env->matrix1, env);
		delay(1000);
		apply_rules(env);
		draw_matrix(env->matrix2, env);
		free_matrix(env->matrix1, env);
		env->matrix1 = env->matrix2;
		i++;
	}
	return (1);
}
