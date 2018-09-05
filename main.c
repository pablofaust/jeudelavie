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

void		read_coords(t_coords *coords)
{
	while (coords)
	{
		printf("%d, %d\n", coords->number, coords->alive);
		coords = coords->next;
	}
}

int		main(int ac, char **av)
{
	t_env		env;
	t_coords	*coords1;

	if (!(check_arguments(ac)))
		return (0);
	if (!(parse_screen(av, &env)))
		return (0);
	coords1 = NULL;
	if (!(parse_coords(av, &env, &coords1)))
		return (0);
	read_coords(coords1);
	if (!(draw_initial_situation(&coords1, &env)))
		return (0);
	if (!(go_live(&coords1, &env)))
		return (0);
	env.coords1 = coords1;
	events_listener(&env);
	mlx_loop(env.mlx);
	return (0);
}
