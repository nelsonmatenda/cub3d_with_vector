/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:02:40 by matenda           #+#    #+#             */
/*   Updated: 2025/05/25 09:04:01 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_background(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= WIDTH)
	{
		j = -1;
		while (++j <= HEIGHT / 2)
			put_pixel(img, 0x03202F, i, j);
	}
	i = -1;
	while (++i <= WIDTH)
	{
		j = HEIGHT / 2;
		while (++j <= HEIGHT)
			put_pixel(img, 0x020202, i, j);
	}
}

void	background(t_game *game)
{
	render_background(&game->layers.background);
	mlx_put_image_to_window(game->mlx, game->win, game->layers.background.ptr, 0, 0);
}
