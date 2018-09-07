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
	int				**matrix1;
	int				**matrix2;
}					t_env;

int					parse_screen(char **av, t_env *env);
int					parse_coords(char **av, t_env *env);
int					create_matrix(t_env *env, int ***matrix);
void				read_matrix(int **matrix, t_env *env);

int					life(t_env *env);
void				events_listener(t_env *env);
void				draw_matrix(int **matrix, t_env *env);
//void				draw_cell(int number, t_env *env);
//int					create_cells(t_env *env);
//int					go_live(t_env *env);
#endif
