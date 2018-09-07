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

int		create_matrix(t_env *env, int ***matrix)
{
	int		i;
	int		j;

	i = 0;
 	if (!(*matrix = ft_memalloc(sizeof(int**) * env->rows * env->cols)))
		return (0);
	while (i < env->rows)
	{
		if (!((*matrix)[i] = ft_memalloc(sizeof(int*) * env->cols)))
			return (0);
		j = 0;
		while (j < env->cols)
		{
			(*matrix)[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		get_coords(char *av, int *ptr1, int *ptr2, t_env *env)
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
	if (x > env->cols || y > env->rows)
	{
		ft_putstr("Veillez a en pas entrer de coordonnees qui sortent du tableau.\n");
		return (0);
	}
	*ptr1 = x - 1;
	*ptr2 = y - 1;
	return (1);
}


void	wake_cell(int **matrix, int x, int y)
{
	matrix[y][x] = 1;		
}

int		parse_coords(char **av, t_env *env)
{
	int		a;
	int		b;
	int		i;
	int		*x;
	int		*y;
	int		**matrix;

	matrix = NULL;
	i = 3;
	a = 0;
	b = 0;
	x = &a;
	y = &b;
	if (!(create_matrix(env, &matrix)))
		return (0);
	while (av[i])
	{
		if (!(get_coords(av[i], x, y, env)))
			return (0);
		wake_cell(matrix, *x, *y);
		i++;
	}
	env->matrix1 = matrix;
	return (1);
}
