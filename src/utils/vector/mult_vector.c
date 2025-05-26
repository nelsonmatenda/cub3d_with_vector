/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:34:00 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 02:42:03 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Multiply a vector with a scalar
 *
 * @param a Vector with x and y
 * @param mult Scalar
 */
void	mult_vector(t_vector *a, float mult)
{
	a->x *= mult;
	a->y *= mult;
}
