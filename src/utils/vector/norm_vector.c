/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:34:00 by matenda           #+#    #+#             */
/*   Updated: 2025/05/24 02:41:59 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Normalize a vector
 *
 * @param a Vector with x and y
 */
void	norm_vector(t_vector *a)
{
	float	m;

	m = magnitude_of_vector(*a);
	a->x /= m;
	a->y /= m;
}
