/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:34:00 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 02:42:22 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Scalar Product
 *
 * @param a Vector with x and y
 * @param b Vector with x and y
 * @return Dot result
 */
float dot_vector(t_vector a, t_vector b)
{
	float	dot;

	dot = (a.x * b.x) + (a.y * b.y);
	return (dot);
}
