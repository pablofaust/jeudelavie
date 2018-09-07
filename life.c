#include "gol.h"

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
	//	apply_rules(env);
	//	draw_matrix(env->matrix2, env);
	//	free_matrix(env->matrix1, env);
	//	env->matrix1 = env->matrix2;
		i++;
	}
	return (1);
}
