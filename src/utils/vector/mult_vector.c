/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:34:00 by matenda           #+#    #+#             */
/*   Updated: 2025/05/27 17:17:07 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Multiply a vector with a scalar
 *
 * @param a Vector with x and y
 * @param mult Scalar
 * @return t_vector New vector
 */
t_vector	mult_vector(t_vector a, float mult)
{
	t_vector	v;

	v.x = a.x * mult;
	v.y = a.y * mult;
	return (v);
}
