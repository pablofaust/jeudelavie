#ifndef GOL_H
# define GOL_H
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include "mlx_keys_macos.h"
# define CELL_WIDTH 100
# define TURNS 3

typedef struct		s_env
{
	int				cols;
	int				rows;
	int				screen_width;
	int				screen_height;
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*data_addr;
	int				bits_per_pixel;
	int				bytes_per_line;
	int				endian;
	struct s_coords *coords1;
	struct s_coords *coords2;
}					t_env;

typedef struct		s_coords
{
	int				number;
	int				alive;
	struct s_coords	*next;
}					t_coords;

int					parse_screen(char **av, t_env *env);
int					parse_coords(char **av, t_env *env, t_coords **coords);
void				read_coords(t_coords **coords);
void				events_listener(t_env *env);
int					draw_initial_situation(t_coords **coords, t_env *env);
void				draw_cell(int number, t_env *env);
int					create_cells(t_coords **coords, t_env *env);
int					go_live(t_coords **coords1, t_coords **coords2, t_env *env);
#endif
