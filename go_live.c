#include "gol.h"

int			apply_rules(t_coords **coords1, t_coords **coords2)
{
	t_coords	*begin;

	begin = *coords2;
	while (begin)
	{
		if (begin->alive == 0)
		{
			if (check_for_life(coords1))
				begin->alive = 1;
		}
		else
		{
			if (!(check_for_survive(coords1)))
				begin->alive = 0;
			else if (check_for_overpopulation(coords1))
				begin->alive = 0;
			else if (check_for_solitude(coords1))
				begin->alive = 0;
		}
	}
}

int			go_live(t_coords **coords1, t_coords **coords2, t_env *env)
{
	int			i;

	i = 1;
	while (i < TURNS)
	{
		printf("Jusqu'ici tout va bien\n");	
		if (*coords2 == NULL)
		{
			if (!(create_cells(coords2, env)))
				return (0);
		}
		else
			coords1 = coords2;
		if (!(apply_rules(coords1, coords2)))
			return (0);
		i++;
	}
	if (coords1)
		return (1);
	return (1);
}
