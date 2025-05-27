#include "../includes/cub3d.h"

void	create_mlx_img(t_img *img, void *mlx, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
}



void	init_windows(t_game *game)
{
	game->mlx = mlx_init();
	if(!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "RAYCASTING");
	create_mlx_img(&game->layers.cub3d, game->mlx, WIDTH, HEIGHT);
}

void	init_player(t_player *player)
{
	player->pos.x = 5;
	player->pos.y = 5;
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
				game->player.pos.x = x + 0.5;
				game->player.pos.y = y + 0.5;
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

	rotate_vector(&game->player.dir, 0.003);
	rotate_vector(&game->player.plane, 0.003);
	clean_image(&game->layers.cub3d);
	background(game);
	x = 0;
	while (x < WIDTH)
	{
		map_pos.x = floor(game->player.pos.x);
		map_pos.y = floor(game->player.pos.y);
		plane_pixel = mult_vector(game->player.plane, ray_mult(x));
		ray_dir = add_vector(&plane_pixel, game->player.dir);
		float delta_dist_x = 0;
		float delta_dist_y = 0;
		if (ray_dir.x == 0)
		{
			delta_dist_x = 1;
			delta_dist_y = 0;
		}
		else
		{
			if (ray_dir.y != 0)
				delta_dist_x = ft_abs(1.0f / ray_dir.x);
		}
		if (ray_dir.y == 0)
		{
			delta_dist_x = 0;
			delta_dist_y = 1;
		}
		else
		{
			if (ray_dir.x != 0)
				delta_dist_y = ft_abs(1.0f / ray_dir.y);
		}

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
			if (wall_map_pos.y >= 0 && wall_map_pos.y < 10 &&	wall_map_pos.x >= 0 && wall_map_pos.x < 24 && game->map[(int)wall_map_pos.y][(int)wall_map_pos.x] && game->map[(int)wall_map_pos.y][(int)wall_map_pos.x] == '1')
				hit = true;
		}
		if (hitside == 0)
		{
			distance = ft_abs((wall_map_pos.x - game->player.pos.x + ((1 - step_x) / 2))/ ray_dir.x);
		}
		else if (hitside == 1)
		{
			distance = ft_abs((wall_map_pos.y - game->player.pos.y + ((1 - step_y) / 2))/ ray_dir.y);
		}
		float wall_height;
		wall_height = HEIGHT / distance;
		float start_wall = HEIGHT/2 - wall_height/2;
		float end_wall = HEIGHT/2 + wall_height/2;
		int color;
		if (!hitside)
			color = 0x800000;
		else
			color = 0xff0000;
		ft_line((t_vector){x, start_wall}, (t_vector){x, end_wall}, &game->layers.cub3d, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->layers.cub3d.ptr, 0, 0);
	return (1);
}


int	main(void)
{
	t_game	game;

	//10x10
	char *map[] = {
		"1111111111",
		"1100100001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1100000011",
		"1000000011",
		"1000000001",
		"1110100011",
		"1111111111",
	};

	game.map = map;
	init_windows(&game);
	init_player(&game.player);
	// // get_player_pos(&game);
	// rotate_vector(&game.player.dir, 3.6);
	// rotate_vector(&game.player.plane, 3.6 );
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
