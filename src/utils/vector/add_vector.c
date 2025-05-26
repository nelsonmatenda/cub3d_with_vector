/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:40:16 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 03:34:52 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Calculate the sum of two vectors.
 *
 * @param a Vector with x and y do want add
 * @param b Vector with x and y
 * @return New vector result of sum
 */
t_vector	add_vector(t_vector *a, t_vector b)
{
	(*a).x = (*a).x + b.x;
	(*a).y = (*a).y + b.y;
	return (*a);
}
