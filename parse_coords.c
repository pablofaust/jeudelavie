#include "gol.h"

int		len_x(char *av)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (av[i] && av[i] != ',')
	{
		if (!(ft_isdigit(av[i])))
		{
			ft_putstr("Veuillez renseigner les coordonnees sous la forme \"x,y\".");
			return (0);
		}
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

void	lstaddafter(t_coords **alst, t_coords **new)
{
	t_coords	*tmp;

	if (!alst)
		(*alst) = (*new);
	else
	{
		tmp = (*alst)->next;
		if (new)
		{
			(*alst)->next = *new;
			(*new)->next = tmp;
		}
		else
			(*alst)->next = NULL;
	}
}

t_coords	*create_new(char *av, t_env *env)
{
	t_coords	*new;

	if (!(new = (t_coords*)malloc(sizeof(t_coords))))
		return (0);
	if (!(new->x = parse_x(av)))
		return (0);
	if (!(new->y = parse_y(av)))
		return (0);
	if (new->x > env->cols || new->y > env->rows)
	{
		ft_putstr("Certaines coordonnees renseignees ne conviennent pas a la taille de tableau selectionnee.\n");
		return (0);
	}
	new->next = NULL;
	return (new);
}

int		parse_coords(char **av, t_env *env, t_coords **coords)
{
	t_coords	*new;
	int		i;

	new = *coords;
	i = 3;
	while (av[i])
	{
		if (*coords == 0)
		{
			new = create_new(av[i], env);
			*coords = new;
		}
		else
		{
			while (new->next)
				new = new->next;
			new->next = create_new(av[i], env);
		}
		i++;
	}
	if (env)
		return (1);
	return (1);
}
