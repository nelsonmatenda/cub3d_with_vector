#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "windows.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

# define BITS 8
# define PI 3.141592

typedef struct s_vector
{
	float	x;
	float	y;
}			t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	plane_pixel;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_win		layers;
	t_player	player;
	char		**map;
}t_game;

// UTIL OPERATIONS WITH VECTOR
t_vector	add_vector(t_vector *a, t_vector b);
t_vector	sub_vector(t_vector *a, t_vector b);
float		angle_between_vector(t_vector a, t_vector b);
float		dot_vector(t_vector a, t_vector b);
float		magnitude_of_vector(t_vector a);
t_vector	mult_vector(t_vector a, float mult);
void		norm_vector(t_vector *a);
void		rotate_vector(t_vector *a, float angle);
//
void		ft_line(t_vector a, t_vector b, t_img *img, int color);
float		ft_abs(float x);
//
void		put_pixel(t_img *img, int color, int x, int y);
void		background(t_game *game);
void		clean_image(t_img *img);

#endif
