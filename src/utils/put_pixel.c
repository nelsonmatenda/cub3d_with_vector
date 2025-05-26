/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:26 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/24 22:15:20 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_img *img, int color, int x, int y)
{
	int	pixel_pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel_pos = (y * img->size_line) + \
					(x * (img->bpp / BITS));
	img->data[pixel_pos] = (char)color & 0xFF;
	img->data[pixel_pos + 1] = (color >> BITS) & 0xFF;
	img->data[pixel_pos + 2] = (color >> (2 * BITS)) & 0xFF;
}
