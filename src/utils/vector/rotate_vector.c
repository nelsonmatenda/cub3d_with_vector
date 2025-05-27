/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:51:10 by matenda           #+#    #+#             */
/*   Updated: 2025/05/27 18:18:28 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static float	normalize_angle(float angle)
{
    while (angle > PI)
        angle -= 2 * PI;
    while (angle < -PI)
        angle += 2 * PI;
    return angle;
}

/**
 * @brief Rotate a vector
 *
 * @param a Vector with x and y integer
 * @param angle Angle of rotation
 */
void	rotate_vector(t_vector *a, float angle)
{
	t_vector	v;
	float		norm_angle;

	v = *a;
	norm_angle = normalize_angle(angle);
	a->x = (v.x * cos(norm_angle)) - (v.y * sin(norm_angle));
	a->y = (v.x * sin(norm_angle)) + (v.y * cos(norm_angle));
}
