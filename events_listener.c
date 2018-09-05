#include "gol.h"

void		free_all(t_coords *coords1)
{
	t_coords *begin;
	t_coords *tmp;

	begin = coords1;
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		free_all(env->coords1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void		events_listener(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
}
