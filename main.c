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
	env.coords1 = coords1;
	events_listener(&env);
	mlx_loop(env.mlx);
	return (0);
}
