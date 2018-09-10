#include "gol.h"

int			check_up_left_corner(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y][x + 1] + env->matrix1[y + 1][x] + env->matrix1[y + 1][x + 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2)
		return (1);
	return (0);
}

int			check_up_right_corner(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y][x - 1] + env->matrix1[y + 1][x - 1] + env->matrix1[y + 1][x];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2)
		return (1);
	return (0);
}

int			check_down_left_corner(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y - 1][x] + env->matrix1[y - 1][x + 1] + env->matrix1[y][x + 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2)
		return (1);
	return (0);
}

int			check_down_right_corner(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y - 1][x - 1] + env->matrix1[y - 1][x] + env->matrix1[y][x - 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2)
		return (1);
	return (0);
}

int			check_up_border(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y][x - 1] + env->matrix1[y][x + 1] + env->matrix1[y + 1][x - 1] + env->matrix1[y + 1][x] + env->matrix1[y + 1][x + 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2 && neighboors <= 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors > 3)
		return (0);
	return (0);
}

int			check_down_border(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y - 1][x - 1] + env->matrix1[y - 1][x] + env->matrix1[y - 1][x - 1] + env->matrix1[y][x - 1] + env->matrix1[y][x + 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2 && neighboors <= 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors > 3)
		return (0);
	return (0);
}

int			check_left_border(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y - 1][x] + env->matrix1[y - 1][x + 1] + env->matrix1[y][x + 1] + env->matrix1[y + 1][x] + env->matrix1[y + 1][x + 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2 && neighboors <= 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors > 3)
		return (0);
	return (0);
}

int			check_right_border(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y - 1][x - 1] + env->matrix1[y - 1][x] + env->matrix1[y][x - 1] + env->matrix1[y + 1][x - 1] + env->matrix1[y + 1][x];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2 && neighboors <= 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors > 3)
		return (0);
	return (0);
}

int			check_center(int y, int x, t_env *env)
{
	int		neighboors;

	neighboors = env->matrix1[y - 1][x - 1] + env->matrix1[y - 1][x] + env->matrix1[y - 1][x + 1] \
				 + env->matrix1[y][x - 1] + env->matrix1[y][x + 1] \
				 + env->matrix1[y + 1][x - 1] + env->matrix1[y + 1][x] + env->matrix1[y + 1][x + 1];
	if (env->matrix1[y][x] == 0 && neighboors == 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors < 2)
		return (0);
	else if (env->matrix1[y][x] == 1 && neighboors >= 2 && neighboors <= 3)
		return (1);
	else if (env->matrix1[y][x] == 1 && neighboors > 3)
		return (0);
	return (0);
}
