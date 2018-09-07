#include "gol.h"

static int	check_arguments(int ac)
{
	if (ac < 3)
	{
		ft_putstr("Le nombre d'argument n'est pas correct. Veuillez specifier une taille de tableau et des coordonnees de cellules.\n");
		return (0);
	}
	return (1);
}

void		read_matrix(int **matrix, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->rows)
	{
		j = 0;
		while (j < env->cols)
		{
			printf("%d : %d\n", i * env->cols + j, matrix[i][j]);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env		env;

	if (!(check_arguments(ac)))
		return (0);
	if (!(parse_screen(av, &env)))
		return (0);
	if (!(parse_coords(av, &env)))
		return (0);
	life(&env);
	events_listener(&env);
	mlx_loop(env.mlx);
	return (0);
}
