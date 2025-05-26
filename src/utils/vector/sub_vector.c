/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:40:16 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 02:49:59 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Calculate the sub of two vectors a - b.
 *
 * @param a Vector with x and y interger
 * @param b Vector with x and y interger
 * @return New vector result of sub A - B
 */
t_vector	sub_vector(t_vector *a, t_vector b)
{
	(*a).x = (*a).x - b.x;
	(*a).y = (*a).y - b.y;
	return (*a);
}
