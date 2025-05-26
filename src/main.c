#include "../includes/cub3d.h"

void	create_mlx_img(t_img *img, void *mlx)
{
	img->ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
}



void	init_windows(t_game *game)
{
	game->mlx = mlx_init();
	if(!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "RAYCASTING");
	create_mlx_img(&game->layers.background, game->mlx);
	background(game);
}

void	init_player(t_player *player)
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->plane_pixel.x = 0;
	player->plane_pixel.y = 0;
}

void	get_player_pos(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
			{
				game->player.pos.x = x;
				game->player.pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}

}

float	ray_mult(float x)
{
	return ((2 * (x / WIDTH)) - 1);
}

int	game_loop(t_game *game)
{
	int	x;
	t_vector	plane_pixel;
	t_vector	ray_dir;
	t_vector	map_pos;
	float		distance;

	map_pos.x = floor(game->player.pos.x);
	map_pos.y = floor(game->player.pos.y);
	x = 0;
	while (x <= WIDTH)
	{
		plane_pixel = game->player.plane;
		mult_vector(&plane_pixel, ray_mult(x));
		ray_dir = add_vector(&plane_pixel, game->player.dir);
		float delta_dist_x = ft_abs((magnitude_of_vector(ray_dir) / ray_dir.x));
		float delta_dist_y = ft_abs((magnitude_of_vector(ray_dir) / ray_dir.y));
		float dist_to_size_x;
		float dist_to_size_y;
		int step_x;
		int	step_y;
		step_x = 1;
		step_y = 1;
		if (ray_dir.x < 0)
		{
			dist_to_size_x = (game->player.pos.x - map_pos.x) * delta_dist_x;
			step_x = -1;
		}
		else
			dist_to_size_x = (map_pos.x +1 - game->player.pos.x) * delta_dist_x;
		if (ray_dir.y < 0)
		{
			dist_to_size_y = (game->player.pos.y - map_pos.y) * delta_dist_y;
			step_y = -1;
		}
		else
			dist_to_size_y = (map_pos.y +1 - game->player.pos.y) * delta_dist_y;
		//DDA
		bool hit = false;
		int hitside;
		(void)hitside;
		float dda_line_size_x = dist_to_size_x;
		float dda_line_size_y = dist_to_size_y;
		t_vector	wall_map_pos = map_pos;
		while (!hit)
		{
			if (dda_line_size_x < dda_line_size_y)
			{
				wall_map_pos.x += step_x;
				dda_line_size_x += delta_dist_x;
				hitside = 0;
			}
			else
			{
				wall_map_pos.y += step_y;
				dda_line_size_y +=  delta_dist_y;
				hitside = 1;
			}
			if (game->map[(int)wall_map_pos.y][(int)wall_map_pos.x] && game->map[(int)wall_map_pos.y][(int)wall_map_pos.x] == '1')
				hit = true;
		}
		if (hitside == 0)
			distance = ft_abs(wall_map_pos.x - game->player.pos.x + ((1 - step_x) / 2))/ ray_dir.x;
		else if (hitside == 1)
			distance = ft_abs(wall_map_pos.y - game->player.pos.y + ((1 - step_y) / 2))/ ray_dir.y;

		x++;
	}
	return (1);
}


int	main(void)
{
	t_game	game;

	//24x10
	char *map[] = {
		"111111111111111111111111",
		"110000000000000000000011",
		"100000000001000000000001",
		"100000000000000000000001",
		"101000000000000000000101",
		"1000000000000N0000000001",
		"100000000000000000000001",
		"100000001001001000000001",
		"110000000000000000000011",
		"111111111111111111111111",
	};
	game.map = map;
	init_windows(&game);
	init_player(&game.player);
	get_player_pos(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
