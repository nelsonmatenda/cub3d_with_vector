/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:51:10 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 02:41:49 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Rotate a vector
 *
 * @param a Vector with x and y integer
 * @param angle Angle of rotation
 */
void	rotate_vector(t_vector *a, float angle)
{
	t_vector vector;

	vector = *a;
	a->x = (vector.x * cos(angle)) - (vector.y * sin(angle));
	a->y = (vector.x * cos(angle)) + (vector.y * sin(angle));
}
