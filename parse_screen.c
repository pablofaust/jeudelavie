#include "gol.h"

static int	check_screen(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (!(ft_isdigit(av[1][i])))
		{
			ft_putstr("Veuillez passer la largeur du tableau en premier argument.\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		if (!(ft_isdigit(av[1][i])))
		{
			ft_putstr("Veuillez passer la hauteur du tableau en second argument.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_screen(char **av, t_env *env)
{
	if (!(check_screen(av)))
		return (0);
	env->cols = ft_atoi(av[1]);
	env->rows = ft_atoi(av[2]);
	if (env->cols < 3 || env->rows < 3)
	{
		ft_putstr("Pour pouvoir jouer au Jeu de la vie, un tableau d'au moins 3x3 est necessaire.\n");
		return (0);
	}
	env->screen_width = env->cols * 2;
	env->screen_height = env->rows * 2;
//	env->mlx = mlx_init();
//	if (!(env->win = mlx_new_window(env->mlx, env->screen_width, env->screen_height, "Jeu de la vie")))
//		return (0);
//	if (!(env->img = mlx_new_image(env->mlx, env->screen_width, env->screen_height)))
//		return (0);
//	if (!(env->data_addr = (unsigned int*)mlx_get_data_addr(env->img, &env->bits_per_pixel, &env->bytes_per_line, &env->endian)))
//		return (0);
	return (1);
}


