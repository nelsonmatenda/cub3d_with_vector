/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:16:40 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/26 21:32:53 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	define_direction(t_vector a, t_vector b, float *dir_x, float *dir_y)
// {
// 	if (a.x < b.x)
// 		*dir_x = 1;
// 	else
// 		*dir_x = -1;
// 	if (a.y < b.y)
// 		*dir_y = 1;
// 	else
// 		*dir_y = -1;
// }

// void	update_pos(float *err, float *p, float delta, float dir)
// {
// 	*err += delta;
// 	*p += dir;
// }

void	ft_line(t_vector a, t_vector b, t_img *img, int color)
{
	int	y;
	float	tmp;

	if (a.x != b.x)
		return;
	if (a.y > b.y)
	{
		tmp = a.y;
		a.y = b.y;
		b.y = tmp;
	}
	y = (int)a.y;
	while (y <= (b.y))
	{
		if (a.x >= 0 && a.x < WIDTH && y >= 0 && y < HEIGHT)
			put_pixel(img, color, (int)a.x, y);
		y++;
	}
}
// void	ft_line(t_vector start, t_vector end, t_img *img, int color)
// {
// 	int y;

// 	if ((int)start.x != (int)end.x)
// 		return ; // só desenhamos linhas verticais aqui

// 	if (start.y > end.y)
// 	{
// 		float tmp = start.y;
// 		start.y = end.y;
// 		end.y = tmp;
// 	}

// 	y = (int)start.y;
// 	while (y <= (int)end.y)
// 	{
// 		if (start.x >= 0 && start.x < WIDTH && y >= 0 && y < HEIGHT)
// 			put_pixel(img, color, (int)start.x, y);
// 		y++;
// 	}
// }
