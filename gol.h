#ifndef GOL_H
# define GOL_H
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include "mlx_keys_macos.h"

typedef struct		s_env
{
	int		cols;
	int		rows;
	int		screen_width;
	int		screen_height;
	void		*mlx;
	void		*win;
	void		*img;
	unsigned int	*data_addr;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
}			t_env;

typedef struct		s_coords
{
	int		x;
	int		y;
	struct s_coords	*next;
}			t_coords;

int			parse_screen(char **av, t_env *env);
int		parse_coords(char **av, t_env *env, t_coords **coords);

#endif
