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

void		draw_cell(int x, int y, t_env *env)
{
	int	position;
	int 	i;
	int	k;

	i = 0;
	position = y * 10 * env->screen_width + x * 10;
	printf("position = %d\n", position);
	while (i <= 10)
	{
		k = 0;
		while (k <= 10)
		{
			env->data_addr[position + i *env->screen_width + k] = 0xffffff;
			k++;
		}
		env->data_addr[position + i * env->screen_width] = 0xffffff;
		printf("position2 = %d\n", position + i * env->screen_width);
		i++;
	}
}

/*int		draw_initial_situation(t_coords **coords, t_env *env)
{	
	while (*coords)
	{
		draw_cell((*coords)->x, (*coords)->y, env);
		(*coords) = (*coords)->next;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}*/

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
//	if (!(draw_initial_situation(&coords1, &env)))
//		return (0);
//	mlx_loop(env.mlx);
	return (0);
}
