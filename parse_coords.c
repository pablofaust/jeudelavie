#include "gol.h"

int		len_x(char *av)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (av[i] && av[i] != ',')
	{
		i++;
		len++;
	}	
	if (len == 0)
	{
		ft_putstr("Veuillez renseigner les coordonnees sous la forme \"x,y\".");
		return (0);
	}
	return (len);
}

int		len_y(char *av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (av[i] && av[i] != ',')
		i++;
	i++;
	j = 0;
	len = 0;
	while (av[i])
	{
		if (!(ft_isdigit(av[i])))
		{
			ft_putstr("Veuillez renseigner les coordonnees sous la forme \"x,y\".");
			return (0);
		}
		i++;
		j++;
		len++;
	}
	if (len == 0)
	{
		ft_putstr("Veuillez renseigner les coordonnees sous la forme \"x,y\".");
		return (0);
	}
	return (len);
}

int		parse_x(char *av)
{
	int	i;
	int	len;
	char	*x;

	i = 0;
	len = 0;
	if (!(len = len_x(av)))
		return (0);
	if (!(x = malloc(sizeof(char) * len)))
		return (0);
	while (i <= len)
	{
		x[i] = av[i];
		i++;
	}
	return (ft_atoi(x));
}

int		parse_y(char *av)
{
	int	i;
	int	j;
	int	len;
	char	*y;

	i = 0;
	len = 0;
	if (!(len = len_y(av)))
		return (0);
	if (!(y = malloc(sizeof(char) * len)))
		return (0);
	while (av[i] && av[i] != ',')
		i++;
	i++;
	j = 0;
	while (j <= len)
	{
		y[j] = av[i];
		i++;
		j++;
	}
	return (ft_atoi(y));
}

t_coords	*create_empty_cell(int i)
{
	t_coords	*new;

	if (!(new = (t_coords*)malloc(sizeof(t_coords))))
		return (0);
	new->number = i;
	new->alive = 0;
	new->next = NULL;
	return (new);
}

int		create_cells(t_coords **coords, t_env *env)
{
	int		cells;
	int		i;
	t_coords	*new;

	cells = env->cols * env->rows;
	i = 0;
	new = *coords;
	while (i < cells)
	{	
		if (*coords == 0)
		{
			new = create_empty_cell(i);
			*coords = new;
		}
		else
		{
			while (new->next)
				new = new->next;
			new->next = create_empty_cell(i);
		}
		i++;
	}
	return (1);
}

int		get_coords(char *av, int *position, int width, int height)
{
	int	x;
	int	y;

	if (!(x = parse_x(av)))
	{
		ft_putstr("Une coordonnee ne peut pas avoir 0 comme valeur sur l'axe x");
		return (0);
	}
	if (!(y = parse_y(av)))
	{
		ft_putstr("Une coordonnee ne peut pas avoir 0 comme valeur sur l'axe y");
		return (0);
	}
	if (x > width || y > height)
	{
		ft_putstr("Veillez a en pas entrer de coordonnees qui sortent du tableau.\n");
		return (0);
	}
	*position = (y - 1) * width + (x - 1);
	return (1);
}


int		wake_cell(t_coords **coords, int *position)
{
	t_coords *begin;

	begin = *coords;
	while (begin)
	{
		if ((begin)->number == *position)
			(begin)->alive = 1;
		(begin) = (begin)->next;
	}
	return (1);
}

int		parse_coords(char **av, t_env *env, t_coords **coords)
{
	int		a;
	int		i;
	int		*position;

	i = 3;
	a = 0;
	position = &a;
	if (!(create_cells(coords, env)))
		return (0);
	while (av[i])
	{
		if (!(get_coords(av[i], position, env->cols, env->rows)))
			return (0);
		if (!(wake_cell(coords, position)))
			return (0);
		i++;
	}
	return (1);
}
